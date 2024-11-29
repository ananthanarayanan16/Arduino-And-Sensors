//////#include <Wire.h> 
////////#include<MPU6050.h>
////////#include <MPU6050.h>
//////#include <Adafruit_MPU6050.h>
//////#include <Adafruit_Sensor.h>
//////
//////Adafruit_MPU6050 mpu;
//////
////////AdaFruit_MPU6050 mpu;
//////
//////void setup()
//////{
//////  Serial.begin(9600);
//////
//////  Wire.begin();
//////
//////  if (!mpu.begin()) {
//////    Serial.println("Failed to find MPU5060 chip");
//////    while (1);
//////  }
//////
//////  Serial.println("MPU6050 Intialized!");
//////
//////  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
//////  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
//////  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
//////}
//////
//////void loop()
//////{
//////  sensors_event_t a, g, temp;
//////
//////  mpu.getEvent(&a, &g, &temp);
//////
//////  Serial.print("Gyro X : ");
//////  Serial.print(g.gyro.x);
//////
//////  Serial.print(" , Y : ");
//////  Serial.print(g.gyro.y);
//////
//////  Serial.print(", Z : ");
//////  Serial.println(g.gyro.z);     
//////
//////  
//////  delay(1000);
//////}
////
////
////#include <Adafruit_MPU6050.h>
////#include <Adafruit_Sensor.h>
////#include <Wire.h>
////
////
////Adafruit_MPU6050 mpu;
////
////// Define the threshold for accident detection
////const float threshold = 1.0; // Threshold in rad/s
////
////void setup() {
////  Serial.begin(9600);
////  if (!mpu.begin()) {
////    Serial.println("Failed to find MPU6050 chip");
//////    while (1)
//////    {
//////       Serial.println("Failed to find MPU6050 chip");
//////    } 
////  }
////  Serial.println("MPU6050 Initialized!");
////}
////
////void loop() {
////  sensors_event_t a, g, temp;
////  mpu.getEvent(&a, &g, &temp);
////
////  // Calculate the magnitude of the angular velocity
//////  float gyroMagnitude = sqrt(sq(g.gyro.x) + sq(g.gyro.y) + sq(g.gyro.z));
////
////  int gyro_x = g.gyro.x;
////
////
////  Serial.println(gyro_x);
//////  if (gyroMagnitude > threshold) {
//////    Serial.print("gyroMagniude");
//////    Serial.println("Accident detected!");
//////  } else {
//////    Serial.println("Normal motion.");
//////  }
////
////  // Print the gyro readings for debugging
//////  Serial.print("Gyro Magnitude: ");
//////  Serial.println(gyroMagnitude);
////
////  delay(2000);
////}
//
//
//
//
//#include <Wire.h>
//#include <MPU6050_tockn.h>
//
//MPU6050 mpu(Wire);
//
//void setup() {
//  Serial.begin(9600);
//  Wire.begin();
//  mpu.begin();
//  mpu.calcGyroOffsets(true); // Calibrate sensor offsets
//  Serial.println("MPU6050 initialized");
//}
//
//void loop() {
//  mpu.update(); // Update sensor readings
//
//  // Get raw gyro values
//  float gyroX_raw = mpu.getGyroX(); // Raw gyro data in degrees/sec
//  float gyroY_raw = mpu.getGyroY();
//  float gyroZ_raw = mpu.getGyroZ();
//
//  // Normalize gyro values to 0–250 range
//  int gyroX_normalized = map(gyroX_raw, -250, 250, 0, 250);
//  int gyroY_normalized = map(gyroY_raw, -250, 250, 0, 250);
//  int gyroZ_normalized = map(gyroZ_raw, -250, 250, 0, 250);
//
////  // Print results
//  Serial.print("Gyro X (normalized): "); Serial.print(gyroX_normalized);
//  Serial.print("\tGyro Y (normalized): "); Serial.print(gyroY_normalized);
//  Serial.print("\tGyro Z (normalized): "); Serial.println(gyroZ_normalized);
//
//
////  Serial.print("Gyro X (normalized): "); Serial.print(gyroX_raw);
////  Serial.print("\tGyro Y (normalized): "); Serial.print(gyroY_raw);
////  Serial.print("\tGyro Z (normalized): "); Serial.println(gyroZ_raw);
//
//
//  delay(500);
//}




#include <Wire.h>
#include <MPU6050_tockn.h>

MPU6050 mpu(Wire);

const int threshold = 150; // Set threshold for accident detection (°/s)

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.begin();
  mpu.calcGyroOffsets(true); // Calibrate sensor offsets
  Serial.println("MPU6050 initialized");
}

void loop() {
  mpu.update(); // Update sensor readings

  // Get raw gyro values
  float gyroX_raw = mpu.getGyroX(); // Raw gyro data in degrees/sec
  float gyroY_raw = mpu.getGyroY();
  float gyroZ_raw = mpu.getGyroZ();

  // Check for accident conditions
  if (abs(gyroX_raw) > threshold || abs(gyroY_raw) > threshold || abs(gyroZ_raw) > threshold) {
    Serial.println("Accident Detected!");
    // Perform any action here, like triggering an alert or sending data
  }

  // Print raw gyro values for monitoring
  Serial.print("Gyro X: "); Serial.print(gyroX_raw);
  Serial.print("\tGyro Y: "); Serial.print(gyroY_raw);
  Serial.print("\tGyro Z: "); Serial.println(gyroZ_raw);

  delay(500);
}
