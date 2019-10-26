#include <SoftwareSerial.h>
#include <TinyGPS.h>

int state = 0;
//const int pin = 9;
float gpslat, gpslon;
String slat, slon;

TinyGPS gps;
SoftwareSerial sgps(4, 5);
SoftwareSerial sgsm(2, 3);

void setup()
{
  sgsm.begin(9600);
  sgps.begin(9600);
}

  void loop()
{
  while (sgps.available())
  {
    int c = sgps.read();
    if (gps.encode(c))
    {
      gps.f_get_position(&gpslat, &gpslon);
    }
  }
    if (sgsm.available() > 0) {
      String    c = sgsm.readString();
      c.trim();
      if (c.indexOf("GET-GPS") >= 0) {
        sgsm.print("\r");
        delay(1000);
        sgsm.print("AT+CMGF=1\r");
        delay(1000);
        /*Replace XXXXXXXXXX to 10 digit mobile number &
          ZZ to 2 digit country code*/
        sgsm.print("AT+CMGS=\"+919650270957\"\r");
        delay(1000);
        //The text of the message to be sent.
        slat=String(gpslat,6);
        slon=String(gpslon,6);
        sgsm.print("Latitude :");
        sgsm.println(slat);
        Serial.println(gpslat, 6);
        sgsm.print("Longitude:");
        sgsm.println(slon);
        delay(1000);
        sgsm.write(0x1A);
        delay(1000);
      }
    }
  }
