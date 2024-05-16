#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  
  Wire.begin();
  mpu.initialize();
  
  Serial.println("Initializing MPU6050...");
  Serial.println("Testing gyro values...");
  delay(1000);
}

void loop() {
  int16_t ax, ay, az, gx, gy, gz;
  
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  
  Serial.print("Gyro X: ");
  Serial.print(gx);
  Serial.print(" | Gyro Y: ");
  Serial.print(gy);
  Serial.print(" | Gyro Z: ");
  Serial.println(gz);
  
  delay(1000); // Adjust delay as needed
}
