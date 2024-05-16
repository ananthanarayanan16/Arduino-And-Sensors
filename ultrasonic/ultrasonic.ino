// Define pins for the ultrasonic sensor
const int trigPin = 2; // Trigger pin
const int echoPin = 3; // Echo pin

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set trigPin as an output and echoPin as an input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delay(100);

  // Send a 10 microsecond pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delay(100);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo pulse
  unsigned long duration = pulseIn(echoPin, HIGH);

  // Convert the duration to distance (in centimeters)
  // Speed of sound at sea level is approximately 343 m/s or 0.0343 cm/microsecond
  // Distance = (duration / 2) * speed of sound
  float distance_cm = duration * 0.0343 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  // Wait for a short time before taking the next measurement
  delay(1000);
}
