// Pin configuration
const int irSensorPin = 2;  // Digital pin connected to the IR sensor output
const int buzz = 5;

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  pinMode(irSensorPin, INPUT);  // Set IR sensor pin as input
  pinMode(buzz,OUTPUT);
}

void loop() {
  // Read the state of the IR sensor
  int obstacleDetected = digitalRead(irSensorPin);

  if(obstacleDetected == HIGH)
  {
    digitalWrite(buzz,HIGH);
    Serial.println("Object detected.");
  }
  else
  {
    digitalWrite(buzz,LOW);
    Serial.println("Object not detected.");
  }
  // Print the sensor output to the serial monitor
  // Serial.print("Obstacle detected: ");
  // Serial.println(obstacleDetected);

  // Add a delay to prevent rapid serial output
  delay(500);  // Adjust delay as needed
}
