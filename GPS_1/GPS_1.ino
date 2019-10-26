#include <TinyGPS++.h>
#include <SoftwareSerial.h>

SoftwareSerial ss(11,10);
TinyGPSPlus gps;

String number = "+919650270957";
void setup() {
  Serial.begin(9600);     
  ss.begin(9600);
  Serial.println("GPS START: ");
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  while(ss.available()){
  gps.encode(ss.read());
  }
   if(gps.location.isUpdated())
   {
    Serial.begin(9600);
    Serial.print("\r");
    delay(1000);
    Serial.print("AT+CMGF=1");
    delay(1000);
    ss.println("AT+CMGS=\"" + number + "\"\r"); //Mobile phone number to send message
  delay(1000);
    Serial.println(gps.location.lat(),6);
    Serial.println(gps.location.lng(),6);
    Serial.print("\r");
    delay(1000);
    Serial.println((char)26);
    delay(1000);
    Serial.write(0x1A);
    Serial.write(0x10);
    Serial.write(0x0A);
    delay(1000);
   }
}
