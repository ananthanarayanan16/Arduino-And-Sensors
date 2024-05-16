int motor1 = 8;
int motor2 = 9;
int motor3 = 10;
int motor4 = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(motor4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //RIGHT MOTOR
  digitalWrite(motor1,HIGH);
  digitalWrite(motor2,LOW);
  //LEFT MOTOR
  digitalWrite(motor3,HIGH);
  digitalWrite(motor4,LOW);
  delay(1000);

  digitalWrite(motor1,LOW);
  digitalWrite(motor2,HIGH);
  //LEFT MOTOR
  digitalWrite(motor3,LOW);
  digitalWrite(motor4,HIGH);

  delay(2000);

  digitalWrite(motor1,HIGH);
  digitalWrite(motor2,LOW);
  //LEFT MOTOR
  digitalWrite(motor3,LOW);
  digitalWrite(motor4,HIGH);
  
  delay(3000);

  


}
