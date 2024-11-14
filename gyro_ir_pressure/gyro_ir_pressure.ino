//  ACCIDENT MOTION DETECTION 

//
//#include <Wire.h>
//#include <MPU6050.h>
//
//MPU6050 mpu;
//
//void setup() {
//  Serial.begin(9600);
//  
//  Wire.begin();
//  mpu.initialize();
//  
//  Serial.println("Initializing MPU6050...");
//  Serial.println("Testing gyro values...");
////  delay(1000);
//}
//
//void loop() {
//  int16_t ax, ay, az, gx, gy, gz;
//  
//  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
//
//  int   x = map(ax, -17000, 17000, 0, 255 );
//
//  int y = map(ay, -17000, 17000, 0, 255);
//
//  int z = map(az, -17000, 17000, 0, 255);
//  
//  Serial.print("Gyro X: ");
//  Serial.print(x);
//  Serial.print(" | Gyro Y: ");
//  Serial.print(y);
//  Serial.print(" | Gyro Z: ");
//  Serial.println(z);
//  
//  delay(2000); // Adjust delay as needed
//}


//  FIRE SENSOR
//
//int firepin = 2;
//
//int buzzpin = 8;
//
//void setup()
//{
//  Serial.begin(9600);
//
//  pinMode(buzzpin, OUTPUT);
//
//  pinMode(firepin, INPUT);  
//}
//void loop()
//{
//  int detect = digitalRead(firepin);
//
//  if(detect == LOW)
//  {
//    Serial.println("Fire Detected.");
//
//    digitalWrite(buzzpin, HIGH);
//  }
//  else
//  {
//    Serial.println("Fire Not Detect.");
//    
//    digitalWrite(buzzpin, LOW);
//  }
//  delay(1000);
//}


//  PERSSURE SENSOR
//
//int piezopin = A1;
//
//void setup()
//{
////  pinMode(perssurepin, INPUT);
//
//  Serial.begin(9600);
//}
//
//void loop()
//{
//  int values = analogRead(piezopin);
//
//  Serial.println(values);
//
//  delay(1000);
//}
//


#include <Wire.h>
#include <MPU6050.h>

MPU6050 gyro;  // Create an instance of the MPU6050

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  gyro.initialize(); // Initialize the MPU6050

  if (gyro.testConnection()) {
    Serial.println("MPU6050 connection successful");
  } else {
    Serial.println("MPU6050 connection failed");
    while(1);  // Halt the program if connection fails
  }
}

void loop() {
  int16_t gx, gy, gz;  // Variables to hold gyro values for each axis

  // Read the gyroscope values for each axis
  gyro.getRotation(&gx, &gy, &gz);

  // Convert to degrees per second (optional, if using raw values is fine)
  float xRotation = gx / 131.0;  // Sensitivity for MPU6050: 131 LSB/(°/s)
  float yRotation = gy / 131.0;
  float zRotation = gz / 131.0;

  // Print the gyroscope values to Serial Monitor
  Serial.print("X: "); Serial.print(xRotation); Serial.print(" °/s, ");
  Serial.print("Y: "); Serial.print(yRotation); Serial.print(" °/s, ");
  Serial.print("Z: "); Serial.print(zRotation); Serial.println(" °/s");

  delay(500);  // Delay between readings
}
