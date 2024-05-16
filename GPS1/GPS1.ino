#include<TinyGPS.h>
#include<SoftwareSerial.h>

TinyGPS gps;
SoftwareSerial ss(3,4);
float latitude,longitude,lng_str,lat_str;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ss.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(ss.available() > 0)
  {
    if(gps.encode(ss.read()))
    {
      if(gps.location.isValid())
      {
        latitude = gps.location.lat();
        lat_str = String(latitude,5);
        longitude = gps.location.lng();
        lng_str = String(longitude,5);
      }
    }
    Serial.println(lng_str);
    Serial.println(lat_str);
  }
  delay(100);
}
