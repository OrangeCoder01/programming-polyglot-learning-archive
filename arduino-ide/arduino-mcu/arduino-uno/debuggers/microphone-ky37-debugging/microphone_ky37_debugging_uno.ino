const int Mic_pin = A0;
char User_choice = 'N';

void setup()
{
  Serial.begin(9600);
}

void Microphone_KY_037_debugging_function()
{
  float Raw_signal = analogRead(Mic_pin);
  if(Raw_signal > 520)
  {
    Serial.println("-------------------------------------------------");
    Serial.println("Sensitivity is too High");
    Serial.println("Rotate the KY-037 sensitivity potentiometer Clockwise");
    Serial.println("-------------------------------------------------");
    delay(500);

  }
  else if(Raw_signal < 500)
  {
    Serial.println("-------------------------------------------------");
    Serial.println("Sensitivity is too Low");
    Serial.println("Rotate the KY-037 sensitivity potentiometer Anti-Clockwise");
    Serial.println("-------------------------------------------------");
    delay(500);

  }
  else 
  {
    Serial.println("-------------------------------------------------");
    Serial.println("Perfect Range");
    Serial.println("-------------------------------------------------");
    delay(500);
  }
}

void loop()
{
  Microphone_KY_037_debugging_function()
}