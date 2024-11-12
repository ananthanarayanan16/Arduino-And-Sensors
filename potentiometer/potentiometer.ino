//READ VOLTAGE VALUE USE POTENTIOMETER

const int analogpin = A0;

int sensordigitalvalue = 0;

float sensorvoltagevalue = 0.0;

void setup()
{
    //  INITIALIZE SERIAL COMMUNUCATION 

    Serial.begin(9600);
}

void loop()
{
//   READ ANALOG VALUE

    sensordigitalvalue = analogRead(analogpin);

    sensorvoltagevalue = (sensordigitalvalue * 5.0) / 1023;

    Serial.print("Digital Value = ");
    
    Serial.print(sensordigitalvalue);
    
    Serial.print("\t Voltage Value = ");

    Serial.println(sensorvoltagevalue);

    delay(500);
    
}
