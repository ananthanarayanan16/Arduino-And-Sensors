#include<Servo.h>
int servopin = 3;
Servo moto;

void setup() {
  // put your setup code here, to run once:
  moto.attach(servopin);
}

void loop() {
  // put your main code here, to run repeatedly:
  moto.write(0);
  delay(500);
  moto.write(90);
  delay(500);
  moto.write(180);
  delay(500);
}
