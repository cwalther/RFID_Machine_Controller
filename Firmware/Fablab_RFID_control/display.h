#include <Fonts/FreeSansBold12pt7b.h>

// "Fonts/g9regular.h" already included in global.h
#include "Fonts/g12bold.h"


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
  0x1c, 0x00, 0x63, 0x00, 0x80, 0x80, 0x41, 0x00, 0x22, 0x00, 0x14, 0x00, 0x08, 0x00
};
// 'wifi_ok', 9x7px
const unsigned char wifiokicon [] PROGMEM = {
  0x1c, 0x00, 0x7f, 0x00, 0xff, 0x80, 0x7f, 0x00, 0x3e, 0x00, 0x1c, 0x00, 0x08, 0x00
};
// 'DB_fail', 6x7px
const unsigned char DBfailicon [] PROGMEM = {
  0x30, 0xcc, 0x84, 0x84, 0x84, 0xcc, 0x30
};
// 'DB_ok', 6x7px
const unsigned char DBokicon [] PROGMEM = {
  0x30, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x30
};
// 'server_fail', 7x7px
const unsigned char serverfailicon [] PROGMEM = {
  0x7c, 0x44, 0x44, 0x7c, 0x00, 0xc6, 0xc6
};
// 'server_ok', 7x7px
const unsigned char serverokicon [] PROGMEM = {
  0x7c, 0x7c, 0x7c, 0x7c, 0x18, 0xfe, 0xee
};
// 'SD_fail', 6x7px
const unsigned char SDfailicon [] PROGMEM = {
  0x3c, 0x44, 0x84, 0x84, 0x84, 0x84, 0xfc
};
// 'SD_ok', 6x7px
const unsigned char SDokicon [] PROGMEM = {
  0x3c, 0x7c, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc
};

#define check_xbm_width 32
#define check_xbm_height 32
static const unsigned char check_xbm_bits[] PROGMEM = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x7C,
   0x00, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x80, 0xFF,
   0x00, 0x00, 0xC0, 0x7F, 0x00, 0x00, 0xE0, 0x3F, 0x00, 0x00, 0xF0, 0x1F,
   0x00, 0x00, 0xF8, 0x0F, 0x00, 0x00, 0xFC, 0x07, 0x1C, 0x00, 0xFE, 0x03,
   0x3E, 0x00, 0xFF, 0x01, 0x7F, 0x80, 0xFF, 0x00, 0xFF, 0xC0, 0x7F, 0x00,
   0xFF, 0xE1, 0x3F, 0x00, 0xFE, 0xF3, 0x1F, 0x00, 0xFC, 0xFF, 0x0F, 0x00,
   0xF8, 0xFF, 0x07, 0x00, 0xF0, 0xFF, 0x03, 0x00, 0xE0, 0xFF, 0x01, 0x00,
   0xC0, 0xFF, 0x00, 0x00, 0x80, 0x7F, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00,
   0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

#define cross_xbm_width 32
#define cross_xbm_height 32
static const unsigned char cross_xbm_bits[] PROGMEM = {
   0x1C, 0x00, 0x00, 0x38, 0x3E, 0x00, 0x00, 0x7C, 0x7F, 0x00, 0x00, 0xFE,
   0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x01, 0x80, 0xFF, 0xFE, 0x03, 0xC0, 0x7F,
   0xFC, 0x07, 0xE0, 0x3F, 0xF8, 0x0F, 0xF0, 0x1F, 0xF0, 0x1F, 0xF8, 0x0F,
   0xE0, 0x3F, 0xFC, 0x07, 0xC0, 0x7F, 0xFE, 0x03, 0x80, 0xFF, 0xFF, 0x01,
   0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFE, 0x7F, 0x00, 0x00, 0xFC, 0x3F, 0x00,
   0x00, 0xF8, 0x1F, 0x00, 0x00, 0xF8, 0x1F, 0x00, 0x00, 0xFC, 0x3F, 0x00,
   0x00, 0xFE, 0x7F, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x80, 0xFF, 0xFF, 0x01,
   0xC0, 0x7F, 0xFE, 0x03, 0xE0, 0x3F, 0xFC, 0x07, 0xF0, 0x1F, 0xF8, 0x0F,
   0xF8, 0x0F, 0xF0, 0x1F, 0xFC, 0x07, 0xE0, 0x3F, 0xFE, 0x03, 0xC0, 0x7F,
   0xFF, 0x01, 0x80, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0x7F, 0x00, 0x00, 0xFE,
   0x3E, 0x00, 0x00, 0x7C, 0x1C, 0x00, 0x00, 0x38 };

//print the header: machine name and status icons
void displayAddHeader(void) {
  display.setFont(&g9regularFont);
  display.setCursor(0, 7);
  display.print(config.MachineName);

  if (WiFi.status() == WL_CONNECTED)
  {
    display.drawBitmap(94, 0, wifiokicon, 9, 7, 1);
  }
  else
  {
    display.drawBitmap(94, 0, wififailicon, 9, 7, 1);
  }
  if (userDBupdated)
  {
    display.drawBitmap(105, 0, DBokicon, 6, 7, 1);
  }
  else
  {
    display.drawBitmap(105, 0, DBfailicon, 6, 7, 1);
  }
  if (serverhealthy)
  {
    display.drawBitmap(113, 0, serverokicon, 7, 7, 1);
  }
  else
  {
    display.drawBitmap(113, 0, serverfailicon, 7, 7, 1);
  }

  if (SDcardOK)
  {
    display.drawBitmap(122, 0, SDokicon, 6, 7, 1);
  }
  else
  {
    display.drawBitmap(122, 0, SDfailicon, 6, 7, 1);
  }

  display.drawFastHLine(0, 8, 128, 1); //draw horizontal line
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
    char temparr[11];
    snprintf(temparr, sizeof(temparr), "%02u.%02u.%04u", day(), month(), year());
    display.setFont(&g9regularFont);
    display.setCursor(37, 33);
    display.print(temparr);
    snprintf(temparr, sizeof(temparr), "%02u:%02u:%02u", hour(), minute(), second());
    display.setFont(&g12boldFont);
    display.setCursor(35, 47);
    display.print(temparr);

    //todo: remove this debug output (or if it is deemed useful in production, properly integrate it into the layout)
    if (WiFi.status() == WL_CONNECTED)
    {
      display.setFont(&g9regularFont);
      display.setCursor(0, 63);
      display.print(F("IP: "));
      display.print(WiFi.localIP());
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
    display.setFont(&g12boldFont);
    display.setCursor(0, 21);
    display.print(String(userentry.name));
    //display.print(0, 27);
    //display.print(surname);
    display.setFont(&FreeSansBold12pt7b);

    time_t timeinuse = getRtcTimestamp() - userStarttime;

    uint16_t usehours = timeinuse / 3600;
    uint16_t useminutes = (timeinuse % 3600) / 60;
    uint16_t useseconds = timeinuse % 60;

    char temparr[12];
    // getTextBounds considers the bitmap size, not the advance width, so the
    // text width differs for a narrow glyph like '1' at the end, which makes
    // the text jump around. To avoid that, append a dummy char of known width
    // for measuring and remove it for rendering.
    snprintf(temparr, sizeof(temparr), "%u:%02u:%02u.", usehours, useminutes, useseconds);
    int16_t x, y;
    uint16_t w1, w2, h;
    display.getTextBounds(temparr, 0, 0, &x, &y, &w1, &h);
    temparr[strlen(temparr)-1] = '\0';
    w1 -= 5;
    display.setCursor(64 - w1/2, 46);
    display.print(temparr);

    //todo: calculate and display running cost
#if 0
    uint16_t cost = timeinuse/3; //dummy
    snprintf(temparr, sizeof(temparr), "%d.%02d.", cost/100, cost%100);
    display.setFont(&g12boldFont);
    display.getTextBounds(temparr, 0, 0, &x, &y, &w1, &h);
    temparr[strlen(temparr)-1] = '\0';
    w1 -= 3;
    display.setCursor(128-w1, 63);
    display.print(temparr);
    display.setFont(&g9regularFont);
    display.getTextBounds("CHF", 0, 0, &x, &y, &w2, &h);
    display.setCursor(128-w1-w2-5, 63);
    display.print("CHF");
#endif
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
  //todo: display username of recognized tag
#if 0
  display.setFont(&g12boldFont);
  display.setCursor(0, 21);
  display.print("Master");
#endif
  display.setFont(&FreeSansBold12pt7b);
  display.setCursor(44, 51);
  display.print("Start");
  display.drawXBitmap(5, 27, check_xbm_bits, check_xbm_width, check_xbm_height, 1);
  display.display();
}

void displayLogout(void)
{
  display.clearDisplay();
  displayAddHeader();
  //todo: display username of recognized tag
#if 0
  display.setFont(&g12boldFont);
  display.setCursor(0, 21);
  display.print("Damian Schneider");
#endif
  display.setFont(&FreeSansBold12pt7b);
  display.setCursor(44, 51);
  display.print("Stop");
  display.drawXBitmap(5, 27, check_xbm_bits, check_xbm_width, check_xbm_height, 1);
  display.display();
}

//display access denied (with a reason)
//reasons: 0 = unauthorized, 1 = occupied, 2 = invalid tag
void displayDenied(uint8_t reason)
{
  display.clearDisplay();
  displayAddHeader();
  display.setFont(&g12boldFont);
  //todo: display username of recognized tag (if any)
#if 0
  display.setCursor(0, 21);
  display.print("Wolfgang Lochbihler");
#endif
  display.setCursor(44, 46);
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
  display.drawXBitmap(5, 27, cross_xbm_bits, cross_xbm_width, cross_xbm_height, 1);
  display.display();
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
  display.setFont(&g9regularFont);
  display.setCursor(0, 7);

}

