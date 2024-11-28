//#include <Wire.h> 
////#include<MPU6050.h>
////#include <MPU6050.h>
//#include <Adafruit_MPU6050.h>
//#include <Adafruit_Sensor.h>
//
//Adafruit_MPU6050 mpu;
//
////AdaFruit_MPU6050 mpu;
//
//void setup()
//{
//  Serial.begin(9600);
//
//  Wire.begin();
//
//  if (!mpu.begin()) {
//    Serial.println("Failed to find MPU5060 chip");
//    while (1);
//  }
//
//  Serial.println("MPU6050 Intialized!");
//
//  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
//  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
//  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
//}
//
//void loop()
//{
//  sensors_event_t a, g, temp;
//
//  mpu.getEvent(&a, &g, &temp);
//
//  Serial.print("Gyro X : ");
//  Serial.print(g.gyro.x);
//
//  Serial.print(" , Y : ");
//  Serial.print(g.gyro.y);
//
//  Serial.print(", Z : ");
//  Serial.println(g.gyro.z);     
//
//  
//  delay(1000);
//}


#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>


Adafruit_MPU6050 mpu;

// Define the threshold for accident detection
const float threshold = 1.0; // Threshold in rad/s

void setup() {
  Serial.begin(9600);
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
//    while (1)
//    {
//       Serial.println("Failed to find MPU6050 chip");
//    }
  }
  Serial.println("MPU6050 Initialized!");
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Calculate the magnitude of the angular velocity
//  float gyroMagnitude = sqrt(sq(g.gyro.x) + sq(g.gyro.y) + sq(g.gyro.z));

  float gyro_x = g.gyro.x;


  Serial.println("gyro_x");
//  if (gyroMagnitude > threshold) {
//    Serial.print("gyroMagniude");
//    Serial.println("Accident detected!");
//  } else {
//    Serial.println("Normal motion.");
//  }

  // Print the gyro readings for debugging
//  Serial.print("Gyro Magnitude: ");
//  Serial.println(gyroMagnitude);

  delay(2000);
}
