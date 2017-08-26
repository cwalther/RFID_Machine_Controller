
//#include <WiFiClientSecure.h>

#define SD_CSN_PIN 0
#define SERVERPACKETS 8        // number of server sendout packets (=buffer)

#define USE_SERIALINPUT  // uncomment to acvate serial input commands (see ackpayloads.h)
#define SERVERMININTERVAL 1000  // minimum interval (in ms) between server sendouts (where a pending event is sent)
#define DEFAULTSTRINGLENGTH 32 //strings stored in eeprom have this length by default (31 chars + termination)
#define SERVERCREDENTIALSTRINGLENGTH 55 //string length for server credentials (Cayenne credentials are up to 50 chars long)
#define MULTIWIFIS 2 //number of wifi credentials to store for wifi multi (uses lots of ram in the config)
#define RFID_SECTORKEY  0x000000000000 //secret access key for first datasector (must be entered upon compiling, never commit to github, not even compiled file)
#define RFID_SECRETKEY  {0x00000000, 0x00000000, 0x00000000, 0x00000000} //16byte (4x32bit) secret key stored in first sector for additional security (can not be copied) key must be inserted before compiling (and never commited to GIThub)

//EEPROM definitions
#define EEPROMSIZE 768
#define EE_START 8  //staring address of data (first 8 bytes can be used as identifiers and versioning)
#define EE_SSID_ADDR  EE_START                                      //base address for wifi passwords
#define EE_WIFIPASS_ADDR EE_SSID_ADDR+(MULTIWIFIS*DEFAULTSTRINGLENGTH)     //base address for wifi passwords
#define EE_NEXTWIFI_ADDR EE_WIFIPASS_ADDR+(MULTIWIFIS*DEFAULTSTRINGLENGTH)    //address for next wifi credentials to (over)write (wifi multi)
#define EE_DEVICENAME_ADDR EE_NEXTWIFI_ADDR+SERVERCREDENTIALSTRINGLENGTH //address for device name (accesspoint name, default: RFIDnode-xx)
#define EE_DEVICEPASS_ADDR EE_DEVICENAME_ADDR+DEFAULTSTRINGLENGTH   //address for device passworkd (accesspoint passworkd, default: 12345678)
#define EE_NTP_ADDR EE_DEVICEPASS_ADDR+DEFAULTSTRINGLENGTH          //address for NTP server name string
#define EE_IP_ADDR EE_NTP_ADDR+DEFAULTSTRINGLENGTH                  //address for static IP
#define EE_NETMASK_ADDR EE_IP_ADDR+4                                //address for static Netmask IP
#define EE_GATEWAY_ADDR EE_NETMASK_ADDR+4                           //address for static Gateway IP
#define EE_DHCP_ADDR EE_GATEWAY_ADDR+4                              //address for 'use DHCP' boolean
#define EE_TIMEZONE_ADDR EE_DHCP_ADDR+4                             //address for timezone, signed uint8_t (currently not used)
#define EE_MID_ADDR EE_TIMEZONE_ADDR+1                              //address for machine ID, uint8_t
#define EE_MACHINENAME_ADDR EE_MID_ADDR+1                           //address for machine name, string
#define EE_SERVERIP_ADDR EE_MACHINENAME_ADDR+DEFAULTSTRINGLENGTH    //address for server IP address, 32byte string (string can be an ip like "192.168.1.1")
#define EE_SERVERPORT_ADDR EE_SERVERIP_ADDR+DEFAULTSTRINGLENGTH     //address for server port, uint16_t
#define EE_END EE_SERVERPORT_ADDR+2                       //address reserved

//additional config stuff needed:
/*
  currently none
  todo: make the config use fixed string lengths as char arrays, read and write the full struct in one go making it a lot more flexible!
  can use mystring.toCharArray(config.thisstring, mytring.length()+1); to copy a string to char array and String mystring = String(config.thisstring) to convert it back
*/


//function prototypes (todo: need to clean up the header file depedency mess!)
void wifiAddAP(String name, String password);
time_t getRtcTimestamp(void);
void userDBpurge(void);
bool handleHTTPRequest(String path);
void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t lenght);


// global variables
Adafruit_SSD1306 display(0); //do not use reset pin
ESP8266WebServer server(80);  // The Webserver
ESP8266HTTPUpdateServer httpUpdater; //http firmware update
//AsyncWebServer server(80);  // The Webserver
//AsyncWebSocket ws("/ws");

WebSocketsServer webSocket = WebSocketsServer(81);
WiFiClient espClient;

//configuration for webupdate of firmware
const char* update_path = "/firmware";
const char* update_username = "admin";
const char* update_password = "admin";
//password for the config webpage access
const char* webpage_username = "admin";
const char* webpage_password = "admin";


// WiFiClientSecure SSLclient; //secure connections
// uint8_t* SSLspacebloackreservation;
uint8_t watchdog;      // counter for watchdog
uint8_t APactive = 0;  // is zero if AP is deactivated, 1 if active (set to 1 to launch accesspoint mode)
bool refreshUserDB = true; //update the user database immediately if set to true (do so on bootup)
bool localTimeValid;
bool RTCTimeValid = false; //is set true after setting the RTC successfully
bool machineLocked = true;
uint32_t userStarttime; //timestamp at start of machine use

uint8_t websocket_connected = 0;
bool webserver_active = false; //set true if webserver is started

struct NodeConfig {
  String ssid[MULTIWIFIS];           // 31 bytes maximum
  String wifipass[MULTIWIFIS];       // 31 bytes maximum
  uint8_t nextmultiwifitowrite; //next space in array to write
  String MachineName;         //31 bytes
  uint8_t mid;                 //machine ID
  String serverAddress;         //server address tring (can be an IP)
  uint16_t serverPort;         //port of server
  String DeviceName;     // 31 bytes maximum, name for access point
  String DevicePW;       // 31 bytes maximum, password for access point
  String ntpServerName;  // 31 bytes maximum
  IPAddress IP;
  IPAddress Netmask;
  IPAddress Gateway;
  bool useDHCP;
} config;





// Server Payload
struct sendoutpackage {
  bool pending;
  uint32_t timestamp;  // time of event
  uint8_t event;     //event to send (0 = controller_start, 1 = controller_ok, 2 = controller_error, 3 = tag_login,4 = tag_logout)
  int16_t tid;         //tag id (set to -1 if not a tag event)
  char remarks[41]; //string for any remarks for the log (limited to 40 chars to not waste a lot of ram in the buffer, must be of constant size for database)
  //note the machine id is read from the config, it does not to be saved in the payload but is added during parsing of the payload
};

//struct for user authentication, 46byte per entry, at 500 entries: 23kB -> no problem to stor in flash (but may take some time to validate a tag...read speed of flash is about 400kB/s according to a test found in the forum, so at 23kb this should take less than 100ms which is ok)

struct userAuth {
  uint16_t tagid; //2byte database tag id (used in the database as a reference to the uid)
  uint32_t uid; //4 byte uid of the RFID card
  uint32_t ts_validfrom; //entry date and time of tag
  uint32_t ts_validuntil; //expiration date and time of tag
  char name[32]; //32byte name of user
} userentry;

uint16_t currentuser = 0; //database entry of current user

sendoutpackage datatosend[SERVERPACKETS]; //buffer for packages to send out

//function prototypes (todo: need to clean up the head file depedency mess!)
bool eventDBaddentry(sendoutpackage* evententry);

void WriteConfig() {
  uint8_t i;
  EEPROM.begin(EEPROMSIZE);
  Serial.println("Writing Config");
  EEPROM.write(0, 'C');
  EEPROM.write(1, 'F');
  EEPROM.write(2, 'G');


  for (i = 0; i < MULTIWIFIS ; i++)
  {
    WriteStringToEEPROM(EE_SSID_ADDR + (i * DEFAULTSTRINGLENGTH), config.ssid[i], DEFAULTSTRINGLENGTH);
    WriteStringToEEPROM(EE_WIFIPASS_ADDR + (i * DEFAULTSTRINGLENGTH), config.wifipass[i], DEFAULTSTRINGLENGTH);
  }
  EEPROM.write(EE_NEXTWIFI_ADDR, config.nextmultiwifitowrite);
  WriteStringToEEPROM(EE_NTP_ADDR, config.ntpServerName, DEFAULTSTRINGLENGTH);
  WriteStringToEEPROM(EE_DEVICENAME_ADDR, config.DeviceName, DEFAULTSTRINGLENGTH);
  WriteStringToEEPROM(EE_DEVICEPASS_ADDR, config.DevicePW, DEFAULTSTRINGLENGTH);


  //note: need to write the IP byte by byte as direct access to the array is not possible (IPaddress is a class)
  EEPROM.write(EE_NETMASK_ADDR, config.Netmask[0]);
  EEPROM.write(EE_NETMASK_ADDR + 1, config.Netmask[1]);
  EEPROM.write(EE_NETMASK_ADDR + 2, config.Netmask[2]);
  EEPROM.write(EE_NETMASK_ADDR + 3, config.Netmask[3]);
  EEPROM.write(EE_GATEWAY_ADDR, config.Gateway[0]);
  EEPROM.write(EE_GATEWAY_ADDR + 1, config.Gateway[1]);
  EEPROM.write(EE_GATEWAY_ADDR + 2, config.Gateway[2]);
  EEPROM.write(EE_GATEWAY_ADDR + 3, config.Gateway[3]);
  EEPROM.write(EE_IP_ADDR, config.IP[0]);
  EEPROM.write(EE_IP_ADDR + 1, config.IP[1]);
  EEPROM.write(EE_IP_ADDR + 2, config.IP[2]);
  EEPROM.write(EE_IP_ADDR + 3, config.IP[3]);
  EEPROM.write(EE_DHCP_ADDR, config.useDHCP);


  EEPROM.write(EE_MID_ADDR, config.mid);
  WriteStringToEEPROM(EE_MACHINENAME_ADDR, config.MachineName, DEFAULTSTRINGLENGTH);
  WriteStringToEEPROM(EE_SERVERIP_ADDR, config.serverAddress, DEFAULTSTRINGLENGTH);
  EEPROMWriteByteArray(EE_SERVERPORT_ADDR, (uint8_t*)&config.serverPort, 2); //uint16_t

  EEPROM.commit();
  EEPROM.end();
}

void writeDefaultConfig(void) {
  // DEFAULT CONFIG
  uint8_t i;
  for (i = 0; i < MULTIWIFIS ; i++)
  {
    config.ssid[i] = " ";
    config.wifipass[i] = " ";
  }
  config.nextmultiwifitowrite = 0;
  config.useDHCP = true;
  config.IP[0] = 192;
  config.IP[1] = 168;
  config.IP[2] = 1;
  config.IP[3] = 44;
  config.Netmask[0] = 255;
  config.Netmask[1] = 255;
  config.Netmask[2] = 255;
  config.Netmask[3] = 0;
  config.Gateway[0] = 192;
  config.Gateway[1] = 168;
  config.Gateway[2] = 1;
  config.Gateway[3] = 1;
  config.ntpServerName = "pool.ntp.org";

  // Use MAC address to generate a uique ID like "AlphaNode-7F89" (code snippet
  // from sparkfun example)
  uint8_t mac[WL_MAC_ADDR_LENGTH];
  WiFi.softAPmacAddress(mac);
  String macID = String(mac[WL_MAC_ADDR_LENGTH - 2], HEX);
  macID.toUpperCase();
  config.DeviceName = "RFIDnode-" + macID; //todo: update this to machine name once it is known
  config.DevicePW = "12345678";
  config.MachineName = "NoName";
  config.mid = 255;
  config.serverAddress = "";
  config.serverPort = 3000;

  WriteConfig();
  Serial.println(F("Standard config applied"));
}

void ReadConfig() {
  uint8_t i;
  EEPROM.begin(EEPROMSIZE);
  Serial.println("Reading Configuration");
  if (EEPROM.read(0) == 'C' && EEPROM.read(1) == 'F' && EEPROM.read(2) == 'G') {
    Serial.println("Configurarion Found!");

    for (i = 0; i < MULTIWIFIS ; i++)
    {
      config.ssid[i] = ReadStringFromEEPROM(EE_SSID_ADDR + (i * DEFAULTSTRINGLENGTH));
      config.wifipass[i] = ReadStringFromEEPROM(EE_WIFIPASS_ADDR + (i * DEFAULTSTRINGLENGTH));
    }
    config.nextmultiwifitowrite = EEPROM.read(EE_NEXTWIFI_ADDR);
    config.ntpServerName = ReadStringFromEEPROM(EE_NTP_ADDR);
    config.DeviceName = ReadStringFromEEPROM(EE_DEVICENAME_ADDR);
    config.DevicePW = ReadStringFromEEPROM(EE_DEVICEPASS_ADDR);

    //note: need to read the IPs byte by byte as direct access to the array is not possible (IPaddress is a class)
    config.Netmask[0] = EEPROM.read(EE_NETMASK_ADDR);
    config.Netmask[1] = EEPROM.read(EE_NETMASK_ADDR + 1);
    config.Netmask[2] = EEPROM.read(EE_NETMASK_ADDR + 2);
    config.Netmask[3] = EEPROM.read(EE_NETMASK_ADDR + 3);
    config.Gateway[0] = EEPROM.read(EE_GATEWAY_ADDR);
    config.Gateway[1] = EEPROM.read(EE_GATEWAY_ADDR + 1);
    config.Gateway[2] = EEPROM.read(EE_GATEWAY_ADDR + 2);
    config.Gateway[3] = EEPROM.read(EE_GATEWAY_ADDR + 3);
    config.IP[0] = EEPROM.read(EE_IP_ADDR);
    config.IP[1] = EEPROM.read(EE_IP_ADDR + 1);
    config.IP[2] = EEPROM.read(EE_IP_ADDR + 2);
    config.IP[3] = EEPROM.read(EE_IP_ADDR + 3);
    config.useDHCP = EEPROM.read(EE_DHCP_ADDR);

    config.mid = EEPROM.read(EE_MID_ADDR);
    config.MachineName = ReadStringFromEEPROM(EE_MACHINENAME_ADDR);

    config.serverAddress = ReadStringFromEEPROM(EE_SERVERIP_ADDR);
    EEPROMReadByteArray(EE_SERVERPORT_ADDR, (uint8_t*)&config.serverPort, 2); //uint16_t

  } else {
    Serial.println(F("Configurarion NOT FOUND!"));
    writeDefaultConfig();
  }
  EEPROM.end();
}

//start webserver to serve config page
void WebServerinit(void)
{

    webserver_active = true;
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println(F("Starting Webserver"));
    if (WiFi.status() == WL_CONNECTED)
    {
      display.print(F("IP: "));
      display.println(WiFi.localIP());
    }
    else
    {
      display.println(F("WIFI DISCONNECTED"));
    }
    display.println(F("Reboot when done"));
    display.display();

    server.on("/", HTTP_GET, []() {
      if (!server.authenticate(webpage_username, webpage_password))
        return server.requestAuthentication();
      if (!handleHTTPRequest("/index.htm")) server.send(404, "text/plain", "FileNotFound");
    });
    server.onNotFound([]() { // handle page not found: check if file or path is available on SPIFFS
      if (!handleHTTPRequest(server.uri()))
        server.send(404, "text/plain", "FileNotFound");
    });


    httpUpdater.setup(&server, update_path, update_username, update_password);
    server.begin();  // start webserver  todo: only need webserver in server mode, not in client mode so could just start it there... may save some ram and make system more stable?
    webSocket.begin(); //todo: check if this can lead to memory leaks if called multiple times
    webSocket.onEvent(webSocketEvent);
  
}

void checkButtonState(void) {
  static uint8_t buttonstate = 0; //set to 1 if button is pressed
  static uint32_t buttontimestamp = 0;

  // note: button is connected to SD cards CSN. when pressed, the card's SPI
  // becomes active. This is not a problem just a hint.

  // wait for any ongoing SPI transaction to finish:
  while (SPI1CMD & SPIBUSY) {
  }

  // now make the pin an input, read it and set it to an output again
  pinMode(SD_CSN_PIN, INPUT);
  if (digitalRead(SD_CSN_PIN) == LOW) {
    if (buttonstate == 0)
    {
      buttonstate = 1;
      buttontimestamp = millis();
    }
  } else
  {
    buttonstate = 0;
  }
  pinMode(SD_CSN_PIN, OUTPUT);
  digitalWrite(SD_CSN_PIN, HIGH);
  if (buttonstate == 1)
  {
    if (webserver_active == false)
    {
      WebServerinit();
    }
    if (millis() - buttontimestamp > 2000 && APactive < 2)
    {
      APactive = 1;  // activate accesspoint
      Serial.println(F("accesspoint triggered"));
      display.println(F("Accesspoint Started:"));
      display.println(config.DeviceName);
      display.print(F("Pass: "));
      display.println(config.DevicePW);
      display.println(F("Go to 192.168.4.1"));
      display.display();
    }
    if (millis() - buttontimestamp > 8000) {
      writeDefaultConfig();  //"reset to factory defaults"
      userDBpurge(); //also delete the user database
      uint32_t waittimestamp = millis();
      // LED_rainbow();
      //TODO: print something on the display!
      display.println(F("RESETTING CONFIG"));
      while (millis() - waittimestamp < 3000)
      {
        updateLED();
        delay(1);
      }
      delay(100);
      ESP.restart();  // reboot
    }
  }

  // todo: possibility to add more functions, like change to default radio
  // channel or something

}

void printConfig(void) {
  uint8_t i;
  Serial.println("config content:");
  Serial.println(config.useDHCP);
  Serial.println(config.IP[0]);
  Serial.println(config.IP[1]);
  Serial.println(config.IP[2]);
  Serial.println(config.IP[3]);
  Serial.println(config.Netmask[0]);
  Serial.println(config.Netmask[1]);
  Serial.println(config.Netmask[2]);
  Serial.println(config.Netmask[3]);
  Serial.println(config.Gateway[0]);
  Serial.println(config.Gateway[1]);
  Serial.println(config.Gateway[2]);
  Serial.println(config.Gateway[3]);
  for (i = 0; i < MULTIWIFIS ; i++)
  {
    Serial.println(config.ssid[i]);
    Serial.println(config.wifipass[i]);
  }
  Serial.println(config.ntpServerName);
  Serial.println(config.DeviceName);
  Serial.println(config.DevicePW);
  //  Serial.println(config.APIkey);
}

//function to generate a log event from data passed to function, if the queue is full, write the new event to the SD card. remarks must be smaller than 40 chars or it gets truncated
void addEventToQueue(uint8_t logevent, int16_t tagID, String remarkstr)
{
  sendoutpackage tempevent; //create a temporary data struct

  //fill in the data, add current time for timestamp
  tempevent.pending = true;
  tempevent.timestamp = getRtcTimestamp(); //get current timestamp from the RTC (returns 0 if RTC time is invalid due to hardware fault)
  Serial.println(tempevent.timestamp);
  tempevent.event = logevent; //event to send (0 = controller_start, 1 = controller_ok, 2 = controller_error, 3 = tag_login,4 = tag_logout)
  tempevent.tid = tagID;
  remarkstr.toCharArray(tempevent.remarks, 41); //copy the string

  //find an available spot in the queue
  uint8_t i;
  bool bufferfull = true;
  for (i = 0; i < SERVERPACKETS; i++)
  {
    if (datatosend[i].pending == false)
    {
      bufferfull = false; //available space found
      break;
    }
  }
  if (!bufferfull)
  {
    datatosend[i] = tempevent; //copy the struct to the queue
  }
  else //if buffer is full, save the event to the SD card database
  {
    eventDBaddentry(&tempevent);
  }
}

//create log event without tagid
void addEventToQueue(uint8_t logevent, String remarkstr)
{
  addEventToQueue(logevent, 0, remarkstr); //if no tid provided, tid is set zero (and not sent out)
}


//function to generate an error event, errorstr must be smaller than 40 chars or it gets truncated
void createErrorEvent(String errorstr)
{
  addEventToQueue(2, errorstr); //event  2 = controller_error
}

