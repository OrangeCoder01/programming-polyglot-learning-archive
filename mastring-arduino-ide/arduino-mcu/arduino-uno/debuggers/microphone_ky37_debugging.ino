const int Mic_pin = A0;
char User_choice = 'N';

void setup()
{
  Serial.begin(9600);
}

void User_decision_function(void (*Callback)(void))
{
 do
    {
      Serial.println("");
      for(int i = 0; i < 10; i ++)
      {
        Callback();
      }

      Serial.print("Would you like to continue?");Serial.println("");
      Serial.print("Enter Y or y on Keypad, if otherwise, enter any other key: "); User_choice = Serial.read();

      while(Serial.available() == 0){}

    }while(User_choice == 'Y' || User_choice == 'y');

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
}