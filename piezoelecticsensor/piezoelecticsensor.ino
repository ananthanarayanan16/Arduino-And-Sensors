int piezo = A0;

// VOID SETUP FUNCTION FOR INITIALIZE SETTING

void setup()
{
  pinMode(piezo, INPUT); 
  Serial.begin(9600);    
}

// VOID LOOP FUNCTION FOR DOING THE PROCESS INFINITLY

void loop()
{
  int piezovalue = analogRead(piezo); 

  Serial.println(piezovalue); 

  delay(100); 
}
