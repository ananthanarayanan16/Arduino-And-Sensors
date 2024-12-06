
#include <Servo.h>. 

const int trigPin = 5;
const int echoPin = 6;

long duration;
int distance;

Servo myServo; 

void setup() 
{
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  myServo.attach(12); 
}

void loop() 
{
  
  for(int i = 0; i <= 180; i++)
  {
    myServo.write(i);
    distance = calculateDistance();

    if(distance < 50)
    {
      Serial.print("OBJECT DETECTED, ");
      Serial.print("ANGLE : ");
      Serial.print(i); 
      Serial.print(" degree");
      Serial.print(",  DISTANCE : "); 
      Serial.print(distance); 
      Serial.println(" cm.");
      delay(300);
    }
    else
    {
      Serial.print("OBJECT CANNOT DETECTED, ");
      Serial.print("ANGLE : ");
      Serial.print(i);
      Serial.println(" degree");
      delay(300);
    }
  }

  for(int i = 180; i >= 0; i--)
  {
    myServo.write(i);
    distance = calculateDistance();

    if(distance < 50)
    {
      Serial.print("OBJECT DETECTED, ");
      Serial.print("ANGLE : ");
      Serial.print(i);
      Serial.print(" degree");
      Serial.print(",  DISTANCE : ");
      Serial.print(distance);
      Serial.println(" cm.");
      delay(300);
    }
    else
    {
      Serial.print("OBJECT CANNOT DETECTED, ");
      Serial.print("ANGLE : ");
      Serial.print(i);
      Serial.println(" degree");
      delay(300);
    }
  }
  
  delay(1000);

}

int calculateDistance()
{ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  
  return distance;
}
