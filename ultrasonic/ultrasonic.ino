//  FIND DISTANCE USIING ULTRASONIC SENSOR

//  DECALERING VARIABLES

int trigpin = 10;

int echopin = 12;

long distance, duration;

void setup()
{

  pinMode(trigpin, OUTPUT);

  pinMode(echopin, INPUT);

  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigpin, LOW);

  delayMicroseconds(4);

  digitalWrite(trigpin, HIGH);  

  delayMicroseconds(15);

  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH);

//  CONVERTING THE TIME INTO A DISTANCE = SPEED * TIME

  distance = duration * 0.034 / 2;

  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.println();

  delay(1000);
  
}
