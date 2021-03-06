#include <Fonts/FreeSans9pt7b.h>  //linienabstand: 16
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSans18pt7b.h>
#include <Fonts/FreeSansBoldOblique12pt7b.h>
#include <Fonts/FreeSansBold18pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>

//#include "Fonts/NimbusBold9.h" //small font, still readable but ugly...
#include "Fonts/DialogPlain5pt.h"
#include "Fonts/DialogBold5pt.h" //too small, not really readable anymore
#include "Fonts/DialogBold6pt.h"

#include "Fonts/DialogPlain8pt.h" //sehr klein, aber unleserlich und hässlich
#include "Fonts/SansSerif8.h"
#include "Fonts/DialogPlain9.h"
#include "Fonts/DialogPlain12.h"
#include "Fonts/DialogBold9.h"
#include "Fonts/DialogBold10.h"
#include "Fonts/DialogBold11.h"
#include "Fonts/DialogBold12.h"
#include "Fonts/DialogBold20.h"
#include "Fonts/NimbusBold9.h"
#include "Fonts/NimbusBold10.h"


#if (SSD1306_LCDHEIGHT != 64)
#error("Display height not set to 64 pixels, please fix Adafruit_SSD1306.h!");
#endif


//logo generated using http://javl.github.io/image2cpp/

unsigned char fablablogo []  = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xf8, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x07, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x00,
  0x00, 0x00, 0x7f, 0x80, 0x07, 0xfc, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x3f, 0x00, 0x00,
  0x00, 0x07, 0xe0, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x07, 0xc0, 0x00,
  0x00, 0x1e, 0x00, 0x7f, 0xf8, 0x03, 0xe0, 0x00, 0x00, 0x3c, 0x03, 0xff, 0xff, 0x00, 0xf0, 0x00,
  0x00, 0x78, 0x0f, 0xfc, 0xff, 0xc0, 0x78, 0x00, 0x00, 0xf0, 0x3f, 0xf0, 0x7f, 0xf0, 0x3c, 0x00,
  0x01, 0xe0, 0xff, 0xe0, 0x1f, 0xf8, 0x1e, 0x00, 0x03, 0xc1, 0xff, 0x80, 0x07, 0xfe, 0x0f, 0x00,
  0x07, 0x83, 0xff, 0xe0, 0x01, 0xff, 0x07, 0x00, 0x07, 0x07, 0xff, 0xff, 0xe0, 0xff, 0x87, 0x80,
  0x0e, 0x0f, 0xff, 0xff, 0xf8, 0x3f, 0x83, 0xc0, 0x1c, 0x0f, 0xdf, 0xff, 0xfc, 0x0f, 0xc1, 0xc0,
  0x1c, 0x1f, 0x07, 0xff, 0xfe, 0x03, 0xe1, 0xe0, 0x18, 0x1c, 0x03, 0xff, 0xfe, 0x01, 0xe0, 0xe0,
  0x38, 0x00, 0x03, 0xff, 0xfe, 0x00, 0x00, 0xf0, 0x30, 0x70, 0x03, 0xff, 0xfe, 0x00, 0x38, 0x70,
  0x78, 0x70, 0x03, 0xff, 0xfc, 0x00, 0x38, 0x70, 0x78, 0xf0, 0x01, 0xff, 0xfc, 0x00, 0x38, 0x38,
  0x78, 0xf0, 0x00, 0xff, 0xf0, 0x00, 0x3c, 0x38, 0x70, 0xf0, 0x00, 0x3f, 0xc0, 0x00, 0x3c, 0x38,
  0xf1, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x38, 0xf1, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x18,
  0xf1, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x18, 0xf1, 0xf0, 0x78, 0x00, 0x00, 0xf9, 0xfe, 0x18,
  0xf1, 0xf0, 0xfe, 0x00, 0x01, 0xff, 0xfe, 0x18, 0xf1, 0xf1, 0xff, 0x00, 0x03, 0xff, 0xfe, 0x00,
  0xf1, 0xf1, 0xff, 0x80, 0x07, 0xff, 0xfe, 0x40, 0xf1, 0xf1, 0xff, 0xc0, 0x0f, 0xff, 0xfe, 0x40,
  0xf1, 0xf1, 0xff, 0xe0, 0x1f, 0xff, 0xfe, 0x40, 0xf1, 0xf1, 0xff, 0xe0, 0x1f, 0xff, 0xfe, 0x08,
  0xf1, 0xf1, 0xff, 0xe0, 0x1f, 0xff, 0x3c, 0x08, 0x70, 0xf1, 0xff, 0xf0, 0x3f, 0xfe, 0x3c, 0x08,
  0x78, 0xf0, 0xff, 0xf0, 0x3f, 0xfc, 0x3c, 0x08, 0x78, 0xf0, 0xff, 0xf0, 0x3f, 0xfc, 0x38, 0x10,
  0x70, 0x70, 0x7f, 0xf0, 0x3f, 0xf8, 0x38, 0x10, 0x34, 0x70, 0x7f, 0xf0, 0x3f, 0xf0, 0x38, 0x30,
  0x3c, 0x70, 0x3f, 0xf0, 0x1f, 0xf0, 0x70, 0x70, 0x1e, 0x3c, 0x3f, 0xe0, 0x1f, 0xe0, 0xf0, 0x70,
  0x1e, 0x1e, 0x3f, 0xc0, 0x0f, 0x83, 0xe0, 0xa0, 0x1f, 0x1f, 0xff, 0x80, 0x00, 0x0f, 0xc0, 0xe0,
  0x0f, 0x0f, 0xff, 0x80, 0x00, 0x1f, 0xc1, 0xc0, 0x07, 0x87, 0xff, 0x80, 0x00, 0x7f, 0x80, 0xc0,
  0x07, 0xc3, 0xff, 0x80, 0x01, 0xff, 0x01, 0x80, 0x03, 0xc1, 0xff, 0x80, 0x03, 0xfe, 0x03, 0x00,
  0x01, 0xe0, 0xff, 0xc0, 0x0f, 0xfc, 0x02, 0x00, 0x00, 0xf0, 0x7f, 0xe0, 0x3f, 0xf0, 0x04, 0x00,
  0x00, 0xf8, 0x1f, 0xf8, 0xff, 0xe0, 0x88, 0x00, 0x00, 0x3c, 0x07, 0xfd, 0xff, 0x81, 0x90, 0x00,
  0x00, 0x1f, 0x01, 0xfd, 0xfc, 0x07, 0x20, 0x00, 0x00, 0x0f, 0xc0, 0x0c, 0xc0, 0x0e, 0x40, 0x00,
  0x00, 0x03, 0xe0, 0x00, 0x00, 0x3d, 0x80, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x01, 0xf6, 0x00, 0x00,
  0x00, 0x01, 0xff, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x3e, 0xe0, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// 'cloud-download'
const unsigned char DBdl [] PROGMEM = {
  0x00, 0x01, 0xf8, 0x00, 0x00, 0x07, 0xfc, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x1f, 0xff, 0x80,
  0x00, 0x1f, 0xff, 0x80, 0x00, 0x3f, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xc0,
  0x3f, 0xff, 0xff, 0xc0, 0x7f, 0xff, 0xff, 0xc0, 0x7f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xfc,
  0xff, 0xfc, 0x3f, 0xfe, 0xff, 0xf0, 0x0f, 0xfe, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xe0, 0x07, 0xff,
  0xff, 0xc1, 0x83, 0xff, 0xff, 0xc3, 0xc3, 0xff, 0xff, 0xc3, 0xc3, 0xff, 0x7f, 0xc3, 0xc3, 0xff,
  0x7f, 0xc3, 0xc3, 0xfe, 0x3f, 0x03, 0xc0, 0xfe, 0x1e, 0x03, 0xc0, 0x7c, 0x00, 0x03, 0xc0, 0x70,
  0x00, 0x1f, 0xf8, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x1f, 0xf8, 0x00,
  0x00, 0x0f, 0xf0, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x01, 0x80, 0x00
};

// 'wifi_fail', 9x7px
const unsigned char wififailicon [] PROGMEM = {
  0x1c, 0x31, 0xa0, 0x28, 0x22, 0x20, 0xa0, 0x21
};
// 'wifi_ok', 9x7px
const unsigned char wifiokicon [] PROGMEM = {
  0x1c, 0x3f, 0xbf, 0xef, 0xe3, 0xe0, 0xe0, 0x21
};
// 'DB_fail', 6x7px
const unsigned char DBfailicon [] PROGMEM = {
  0x33, 0x38, 0x61, 0x87, 0x33, 0x3f
};
// 'DB_ok', 6x7px
const unsigned char DBokicon [] PROGMEM = {
  0x33, 0xff, 0xff, 0xff, 0xf3, 0x3f
};
// 'server_fail', 7x7px
const unsigned char serverfailicon [] PROGMEM = {
  0x7c, 0x89, 0x13, 0xe0, 0x18, 0xf1, 0xff
};
// 'server_ok', 7x7px
const unsigned char serverokicon [] PROGMEM = {
  0x7c, 0xf9, 0xf3, 0xe3, 0x9f, 0xfb, 0xff
};
// 'SD_fail', 6x7px
const unsigned char SDfailicon [] PROGMEM = {
  0x3d, 0x18, 0x61, 0x86, 0x1f, 0xff
};
// 'SD_ok', 6x7px
const unsigned char SDokicon [] PROGMEM = {
  0x3d, 0xff, 0xff, 0xff, 0xff, 0xff
};

//print the header: machine name and status icons
void displayAddHeader(void) {
  display.setFont();
  display.setCursor(0, 0);
  display.print(config.MachineName);

  if (WiFi.status() == WL_CONNECTED)
  {
    display.drawBitmap(97, 0, wifiokicon, 9, 7, 1);
  }
  else
  {
    display.drawBitmap(97, 0, wififailicon, 9, 7, 1);
  }
  if (userDBupdated)
  {
    display.drawBitmap(107, 0, DBokicon, 6, 7, 1);
  }
  else
  {
    display.drawBitmap(107, 0, DBfailicon, 6, 7, 1);
  }
  if (serverhealthy)
  {
    display.drawBitmap(114, 0, serverokicon, 7, 7, 1);
  }
  else
  {
    display.drawBitmap(114, 0, serverfailicon, 7, 7, 1);
  }

  if (SDcardOK)
  {
    display.drawBitmap(122, 0, SDokicon, 6, 7, 1);
  }
  else
  {
    display.drawBitmap(122, 0, SDfailicon, 6, 7, 1);
  }

  display.drawFastHLine(0, 10, 128, 1); //draw horizontal line
}

void displayUpdate(void) {

  //todo: need to define the display layout

  //stuff to display: time
  //currently logged in user

  //if machine is unused:
  //display the current time, maybe also the date, what else?
  display.clearDisplay();
  displayAddHeader();

  if (machineLocked)
  {


    char temparr[5];
    sprintf(temparr, "%02u", day()); //need a fixed length, easiest using sprintf
    String daystr = String(temparr);
    sprintf(temparr, "%02u", month()); //need a fixed length, easiest using sprintf
    String monthstr = String(temparr);
    sprintf(temparr, "%04u", year()); //need a fixed length, easiest using sprintf
    String yearstr = String(temparr);
    sprintf(temparr, "%02u", hour()); //need a fixed length, easiest using sprintf
    String hourstr = String(temparr);
    sprintf(temparr, "%02u", minute()); //need a fixed length, easiest using sprintf
    String minutestr = String(temparr);
    sprintf(temparr, "%02u", second()); //need a fixed length, easiest using sprintf
    String secondstr = String(temparr);
    String localtimestr = hourstr + ":" + minutestr + ":" + secondstr;
    String datestr = daystr + "." + monthstr + "." + yearstr;

    display.setFont(&Dialogbold12);
    display.setCursor(18, 28);
    display.print(datestr);

    display.setFont(&Dialogbold20);
    display.setCursor(10, 50);
    display.print(localtimestr);


    display.setFont();//default tiny font
    display.setCursor(0, 57);
    if (WiFi.status() == WL_CONNECTED)
    {
      display.print(F("IP: "));
      display.print(WiFi.localIP());
    }
    else
    {
      display.print(F("WIFI DISCONNECTED"));
    }
  }
  else //machine is unlocked, user is logged in
  {
    String firstname;
    String surname;
    if (currentuser == 0) //the admin tag is logged in
    {
      firstname = "MASTER";
      surname = "";
    }
    else
    {
      //get current users name from database
      userdatabase.readRec(currentuser, EDB_REC userentry); //get the currently loggeed in user entry
      String fullname = String(userentry.name);
      firstname = splitStringbySeparator(fullname, char(' ')); //split the name string into first name and surname
      surname = fullname.substring(firstname.length() + 1);
    }
    display.setFont(&Dialogbold9);
    display.setCursor(0, 24);
    display.print(String(userentry.name));
    //display.print(0, 27);
    //display.print(surname);
    display.setFont(&Dialogbold20);
    display.setCursor(10, 48);


    time_t timeinuse = getRtcTimestamp() - userStarttime;

    uint16_t usehours = timeinuse / 3600;
    uint16_t useminutes = (timeinuse % 3600) / 60;
    uint16_t useseconds = timeinuse % 60;

    char temparr[5];
    sprintf(temparr, "%02u", usehours); //need a fixed length, easiest using sprintf
    String hourstr = String(temparr);
    sprintf(temparr, "%02u", useminutes); //need a fixed length, easiest using sprintf
    String minutestr = String(temparr);
    sprintf(temparr, "%02u", useseconds); //need a fixed length, easiest using sprintf
    String secondstr = String(temparr);
    String usetime = hourstr + ":" + minutestr + ":" + secondstr;
    display.print(usetime);

  }

  display.display();

  // char numberbuffer[6];
  //dtostrf(1234, 6, 2, numberbuffer);
  //display.print(numberbuffer);

}

void displayLogin(void)
{
  display.clearDisplay();
  displayAddHeader();
  display.setFont(&Dialogbold20);
  display.setCursor(35, 50);
  display.print("Start");
  //todo: add icon
  display.display();
}

void displayLogout(void)
{
  display.clearDisplay();
  displayAddHeader();
  display.setFont(&Dialogbold20);
  display.setCursor(35, 50);
  display.print("Stop");
  //todo: add icon
  display.display();
}

//display access denied (with a reason)
//reasons: 0 = unauthorized, 1 = occupied, 2 = invalid tag
void displayDenied(uint8_t reason)
{
  display.clearDisplay();
  displayAddHeader();
  display.setFont(&Dialogbold12);
  display.setCursor(25, 46);
  if (reason == 1)
  {
    display.print("besetzt");
  }
  else if (reason == 2)
  {
    display.print("tag error");
  }
  else
  {
    display.print("unberechtigt");
  }
  //todo: add icon
  display.display();
}


void fonttest(void)
{
  String text = "AabcefskFrown";
  String numbers = "1234567890";


  display.setFont(&SansSerif8); //well readable, braucht viel platz, ca 7 pixel hoch, genau gleich wie dialogplain8!
  display.clearDisplay();
  display.setCursor(0, 10);
  display.print("Laser klein");
  display.setCursor(0, 30);
  display.print(text);
  display.setCursor(0, 60);
  display.print(numbers);
  display.display();
  delay(5000);


  //dialogplain 8 ist auch eine gute default schrift.
  display.setFont(&DialogPlain8); //well readable, braucht viel platz, ca 7 pixel hoch
  display.clearDisplay();
  display.setCursor(0, 10);
  display.print("Laser klein");
  display.setCursor(0, 30);
  display.print(text);
  display.setCursor(0, 60);
  display.print(numbers);
  display.display();
  delay(5000);

  display.setFont(&Dialogplain9); //well readable, braucht viel platz, ca 8 pixel hoch
  display.clearDisplay();
  display.setCursor(0, 10);
  display.print("Wolfgang Lochbihler :) asdfghj");
  display.setCursor(0, 30);
  display.print(text);
  display.setCursor(0, 60);
  display.print(numbers);
  display.display();
  delay(5000);

  display.setFont(&Dialogbold9); //sehr gut lesbar, fett, schöne zahlen, ca 8 pixel hoch -> für allerlei benutzbar
  display.clearDisplay();
  display.setCursor(0, 10);
  display.print("Wolfgang Lochbihler :) asdfghj");
  display.setCursor(0, 30);
  display.print(text);
  display.setCursor(0, 60);
  display.print(numbers);
  display.display();
  delay(5000);

  display.setFont(&Dialogbold10); //
  display.clearDisplay();
  display.setCursor(0, 30);
  display.print(text);
  display.setCursor(0, 60);
  display.print(numbers);
  display.display();
  delay(5000);


  display.setFont(&Dialogbold11); //
  display.clearDisplay();
  display.setCursor(0, 30);
  display.print(text);
  display.setCursor(0, 60);
  display.print(numbers);
  display.display();
  delay(5000);


  display.setFont(&Dialogbold12); //
  display.clearDisplay();
  display.setCursor(0, 30);
  display.print(text);
  display.setCursor(0, 60);
  display.print(numbers);
  display.display();
  delay(5000);


  display.setFont(&Dialogplain12); //schöne schrift, gross
  display.clearDisplay();
  display.setCursor(0, 30);
  display.print(text);
  display.setCursor(0, 60);
  display.print(numbers);
  display.display();
  delay(5000);


  display.setFont(&NimbusBold9); //ok, lesbar, munzig
  display.clearDisplay();
  display.setCursor(0, 30);
  display.print(text);
  display.setCursor(0, 60);
  display.print(numbers);
  display.display();
  delay(5000);

  display.setFont(&NimbusBold10); //schlechter lesbar als grösse 9!
  display.clearDisplay();
  display.setCursor(0, 30);
  display.print(text);
  display.setCursor(0, 60);
  display.print(numbers);
  display.display();
  delay(5000);

}


void showCloudDownload(void)
{
  display.clearDisplay();
  display.drawBitmap(46, 20, DBdl, 32, 32, 1);
  display.setCursor(12, 0);
  display.println(F("Updating Database"));
  display.display();
}

void displayinit(void)
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Wire.setClock(400000);  // use fast speed
  display.clearDisplay();
  display.display();  //
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setTextWrap(false);

  /*
    display.setCursor(29, 15);
    display.setFont(&FreeSansBold12pt7b);
    display.println("Fablab");
    display.setCursor(30, 54);
    display.print("Winti");
    display.display();
  */
  //delay(500);
  display.drawBitmap(31, 0, fablablogo, 64, 64, 1);
  display.display();
  delay(800);
  display.clearDisplay();
  display.display();
  display.setFont(&DialogPlain8);
  display.setCursor(0, 0);

}

