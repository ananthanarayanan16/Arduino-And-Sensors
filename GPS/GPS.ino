#include <SoftwareSerial.h>

// Define the RX and TX pins for the GPS module
const int gpsRxPin = 2; // Connect GPS TX pin to Arduino digital pin 2
const int gpsTxPin = 3; // Connect GPS RX pin to Arduino digital pin 3

SoftwareSerial gpsSerial(gpsRxPin, gpsTxPin); // Create a software serial object for GPS communication

void setup() {
  Serial.begin(9600); // Initialize serial communication with the computer
  gpsSerial.begin(9600); // Initialize serial communication with the GPS module
}

void loop() {
  // Check if data is available from the GPS module
  if (gpsSerial.available()) {
    // Read the data from the GPS module and print it to the serial monitor
    Serial.write(gpsSerial.read());
  }
}
