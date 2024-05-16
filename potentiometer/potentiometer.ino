int analogpin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int digitalvalue = analogRead(analogpin);
  float analogvalue = (digitalvalue*5.0)/1023;
  Serial.print("Digital Value : ");
  Serial.print(digitalvalue);
  Serial.print("\t Voltage Value : ");
  Serial.println(analogvalue);

  delay(200);
}
