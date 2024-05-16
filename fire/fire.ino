// Pin configuration
const int flameSensorPin = 5; // Digital pin connected to the flame sensor output

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(flameSensorPin, INPUT); // Set flame sensor pin as input
}

void loop() {
  // Read the state of the flame sensor
  int flameDetected = digitalRead(flameSensorPin);

  // Print the sensor output to the serial monitor
  if (flameDetected == HIGH) {
    Serial.println("Flame detected!");
  } else {
    Serial.println("No flame detected");
  }

  // Add a delay to prevent rapid serial output
  delay(500); // Adjust delay as needed
}
