const int Buzzer_pin = A0;


void setup()
{
  Serial.begin(9600);
}

void loop()
{
  for(int freq = 0; freq < 2000; freq = freq + 200)
  {
    tone(Buzzer_pin, freq);
    delay(300);
    noTone(Buzzer_pin);
    delay(300);
  }
}