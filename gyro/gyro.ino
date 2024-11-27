#include <Wire.h> 
//#include<MPU6050.h>
//#include <MPU6050.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

//AdaFruit_MPU6050 mpu;

void setup()
{
  Serial.begin(9600);

  Wire.begin();

  if (!mpu.begin()) {
    Serial.println("Failed to find MPU5060 chip");
    while (1);
  }

  Serial.println("MPU6050 Intialized!");

  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop()
{
  sensors_event_t a, g, temp;

  mpu.getEvent(&a, &g, &temp);

  Serial.print("Gyro X : ");
  Serial.print(g.gyro.x);

  Serial.print(" , Y : ");
  Serial.print(g.gyro.y);

  Serial.print(", Z : ");
  Serial.println(g.gyro.z);     

  
  delay(1000);
}
