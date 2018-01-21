#include <Adafruit_GFX.h>

#include <Fonts/FreeSans9pt7b.h>  //linienabstand: 16
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSans18pt7b.h>
#include <Fonts/FreeSansBoldOblique12pt7b.h>
#include <Fonts/FreeSansBold18pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>



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

void displayUpdate(void) {

  //todo: need to define the display layout

  //stuff to display: time
  //currently logged in user

  //if machine is unused:
  //display the current time, maybe also the date, what else?
  display.clearDisplay();

  if (machineLocked)
  {
    display.setFont(&FreeSans9pt7b);
    display.setCursor(20, 12);

    char temparr[5];
    sprintf(temparr, "%02u", hour()); //need a fixed length, easiest using sprintf
    String hourstr = String(temparr);
    sprintf(temparr, "%02u", minute()); //need a fixed length, easiest using sprintf
    String minutestr = String(temparr);
    sprintf(temparr, "%02u", second()); //need a fixed length, easiest using sprintf
    String secondstr = String(temparr);
    String localtimestr = hourstr + ":" + minutestr + ":" + secondstr;
    display.print(localtimestr);

    display.setFont(&FreeSansBoldOblique12pt7b);
    display.setCursor(30, 43);
    display.print("FREI");
    display.setCursor(0, 62);
    display.setFont();//default tiny font

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
    if(currentuser == 0) //the admin tag is logged in
    {
      firstname = "ADMIN";
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
    display.setFont(&FreeSans9pt7b);
    display.setCursor(0, 12);
    display.print(firstname);
    display.setCursor(0, 27);
    display.print(surname);

    display.setFont(&FreeSansBold12pt7b);
    display.setCursor(10, 60);

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

  char numberbuffer[6];
  dtostrf(1234, 6, 2, numberbuffer);
  //display.print(numberbuffer);

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
  //todo: add fablab logo here



  display.drawBitmap(31, 0, fablablogo, 64, 64, 1);
  display.display();
  delay(800);
  display.clearDisplay();
  display.display();
  display.setCursor(0, 0);

}

