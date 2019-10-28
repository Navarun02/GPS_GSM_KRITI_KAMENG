//#include <LiquidCrystal.h> 
#include <SoftwareSerial.h> 
#include <TinyGPS.h> 
float late,lon; // create variable for latitude and longitude object  
SoftwareSerial gpsSerial(3,4);//rx,tx 
//SoftwareSerial GPRS(7, 8);
//LiquidCrystal lcd(A0,A1,A2,A3,A4,A5); 
TinyGPS gps; // create gps object 
void setup(){ 
Serial.begin(9600); // connect serial 
Serial.println("The GPS Received Signal:"); 
gpsSerial.begin(9600); // connect gps sensor 
//lcd.begin(16,2); 

//GPRS.begin(9600);
  //Serial.begin(9600);
//GPRS.println("AT+CMGF=1");
//delay(1000);
} 
void loop(){ 
 // while(GPRS.available()) {
  //  Serial.write(GPRS.read());
 // }
  
  while(gpsSerial.available()){ // check for gps data 
  if(gps.encode(gpsSerial.read()))// encode gps data 
  {  
  gps.f_get_position(&late,&lon); // get latitude and longitude 
  // display position 
  //lcd.clear(); 
  //lcd.setCursor(1,0); 
  //lcd.print("GPS Signal"); 
  Serial.print("Position: "); 
  Serial.print("Latitude:"); 
  Serial.print(late,6); 
  Serial.print(";"); 
  Serial.print("Longitude:"); 
  Serial.println(lon,6);  
  //lcd.setCursor(1,0); 
  //lcd.print("LAT:"); 
  //lcd.setCursor(5,0); 
  //lcd.print(late); 
  Serial.print(late); 
  Serial.print(" "); 
  //lcd.setCursor(0,1); 
  //lcd.print(",LON:"); 
  //lcd.setCursor(5,1); 
  //lcd.print(lon); 
 } 
} 
String latitude = String(late,6); 
  String longitude = String(lon,6); 
Serial.println(latitude+";"+longitude); 
delay(1000); 

//GPRS.println("AT+CMGS=\"+919650270957\"");
  //delay(500);
  
  //GPRS.println(latitude);
  //GPRS.println(longitude);
  
 // GPRS.println(state ? "on" : "off");
 // GPRS.write( 0x1a ); // ctrl+Z character
  
  //delay(500);
}


/*void sendSMS() {  
  GPRS.println("AT+CMGS=\"+919650270957\"");
  delay(500);
  
  GPRS.println(latitude);
  GPRS.println(longitude);
  
 // GPRS.println(state ? "on" : "off");
  GPRS.write( 0x1a ); // ctrl+Z character
  
  delay(500);
}*/
