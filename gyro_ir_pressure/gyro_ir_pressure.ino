////  ACCIDENT MOTION DETECTION 
//
////
////#include <Wire.h>
////#include <MPU6050.h>
////
////MPU6050 mpu;
////
////void setup() {
////  Serial.begin(9600);
////  
////  Wire.begin();
////  mpu.initialize();
////  
////  Serial.println("Initializing MPU6050...");
////  Serial.println("Testing gyro values...");
//////  delay(1000);
////}
////
////void loop() {
////  int16_t ax, ay, az, gx, gy, gz;
////  
////  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
////
////  int   x = map(ax, -17000, 17000, 0, 255 );
////
////  int y = map(ay, -17000, 17000, 0, 255);
////
////  int z = map(az, -17000, 17000, 0, 255);
////  
////  Serial.print("Gyro X: ");
////  Serial.print(x);
////  Serial.print(" | Gyro Y: ");
////  Serial.print(y);
////  Serial.print(" | Gyro Z: ");
////  Serial.println(z);
////  
////  delay(2000); // Adjust delay as needed
////}
//
//
////  FIRE SENSOR
////
////int firepin = 2;
////
////int buzzpin = 8;
////
////void setup()
////{
////  Serial.begin(9600);
////
////  pinMode(buzzpin, OUTPUT);
////
////  pinMode(firepin, INPUT);  
////}
////void loop()
////{
////  int detect = digitalRead(firepin);
////
////  if(detect == LOW)
////  {
////    Serial.println("Fire Detected.");
////
////    digitalWrite(buzzpin, HIGH);
////  }
////  else
////  {
////    Serial.println("Fire Not Detect.");
////    
////    digitalWrite(buzzpin, LOW);
////  }
////  delay(1000);
////}
//
//
////  PERSSURE SENSOR
////
////int piezopin = A1;
////
////void setup()
////{
//////  pinMode(perssurepin, INPUT);
////
////  Serial.begin(9600);
////}
////
////void loop()
////{
////  int values = analogRead(piezopin);
////
////  Serial.println(values);
////
////  delay(1000);
////}
////
//
//
//#include <Wire.h>
//#include <MPU6050.h>
//
//MPU6050 gyro;  // Create an instance of the MPU6050
//
//void setup() {
//  Serial.begin(9600);
//  Wire.begin();
//  
//  gyro.initialize(); // Initialize the MPU6050
//
//  if (gyro.testConnection()) {
//    Serial.println("MPU6050 connection successful");
//  } else {
//    Serial.println("MPU6050 connection failed");
//    while(1);  // Halt the program if connection fails
//  }
//}
//
//void loop() {
//  int16_t gx, gy, gz;  // Variables to hold gyro values for each axis
//
//  // Read the gyroscope values for each axis
//  gyro.getRotation(&gx, &gy, &gz);
//
//  // Convert to degrees per second (optional, if using raw values is fine)
//  float xRotation = gx / 131.0;  // Sensitivity for MPU6050: 131 LSB/(°/s)
//  float yRotation = gy / 131.0;
//  float zRotation = gz / 131.0;
//
//  // Print the gyroscope values to Serial Monitor
//  Serial.print("X: "); Serial.print(xRotation); Serial.print(" °/s, ");
//  Serial.print("Y: "); Serial.print(yRotation); Serial.print(" °/s, ");
//  Serial.print("Z: "); Serial.print(zRotation); Serial.println(" °/s");
//
//  delay(500);  // Delay between readings
//}











#include <Wire.h>
#include <MPU6050.h>

// Define pins
#define PIEZO_PIN A0
#define FLAME_PIN A1
#define BUZZER_PIN 8
#define LED_PIN 9

// Initialize MPU6050 gyroscope
MPU6050 mpu;

// Variables for sensor readings
int piezoValue = 0;
int flameValue = 0;
int accelX, accelY, accelZ;
int gyroX, gyroY, gyroZ;

void setup() {
  // Start serial communication
  Serial.begin(9600);
  
  // Initialize MPU6050
  Wire.begin();
  mpu.initialize();
  
  // Set up pins
  pinMode(PIEZO_PIN, INPUT);
  pinMode(FLAME_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  
  // Check if the MPU6050 is connected
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  }
  
  Serial.println("Accident Detection System Initialized");
}

void loop() {
  // Read gyroscope and accelerometer values
  mpu.getMotion6(&accelX, &accelY, &accelZ, &gyroX, &gyroY, &gyroZ);

  // Read piezoelectric sensor value
  piezoValue = analogRead(PIEZO_PIN);
  
  // Read flame sensor value
  flameValue = analogRead(FLAME_PIN);
  
  // Print sensor values to serial monitor (optional)
  Serial.print("Acc X: "); Serial.print(accelX);
  Serial.print(" Acc Y: "); Serial.print(accelY);
  Serial.print(" Acc Z: "); Serial.print(accelZ);
  Serial.print(" Gyro X: "); Serial.print(gyroX);
  Serial.print(" Gyro Y: "); Serial.print(gyroY);
  Serial.print(" Gyro Z: "); Serial.println(gyroZ);
  Serial.print("Piezo Sensor Value: "); Serial.println(piezoValue);
  Serial.print("Flame Sensor Value: "); Serial.println(flameValue);

  // Conditions for accident detection
  // 1. Sudden change in orientation (detect if the acceleration is high, indicating a crash)
  if (abs(accelX) > 15000 || abs(accelY) > 15000 || abs(accelZ) > 15000) {
    triggerAlarm("Accident Detected (Orientation Change)");
  }
  
  // 2. Vibration detection (if piezoelectric sensor detects a strong vibration)
  if (piezoValue > 500) {
    triggerAlarm("Accident Detected (Vibration)");
  }
  
  // 3. Flame detection (if the flame sensor detects fire)
  if (flameValue > 100) {
    triggerAlarm("Accident Detected (Fire)");
  }

  // Small delay before next loop iteration
  delay(500);
}

void triggerAlarm(String message) {
  // Output message to Serial Monitor
  Serial.println(message);

  // Turn on LED and buzzer as an indicator of accident detection
  digitalWrite(LED_PIN, HIGH);
  digitalWrite(BUZZER_PIN, HIGH);

  // Wait for 5 seconds before turning off the alarm
  delay(5000);

  // Turn off the alarm
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
}
