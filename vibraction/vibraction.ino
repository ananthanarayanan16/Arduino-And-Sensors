// Pin configuration
const int vibrationSensorPin = 2; // Digital pin connected to the vibration sensor output

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(vibrationSensorPin, INPUT); // Set vibration sensor pin as input
}

void loop() {
  // Read the state of the vibration sensor
  int vibrationDetected = digitalRead(vibrationSensorPin);

  // Print the sensor output to the serial monitor
  Serial.print("Vibration detected: ");
  Serial.println(vibrationDetected);

  // Add a delay to prevent rapid serial output
  delay(500); // Adjust delay as needed
}
