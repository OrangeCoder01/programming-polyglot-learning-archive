int Shock_pin = 13;
int LED_pin = 12;

unsigned long Pulse_Time = 150;
int Pulse_Count = 0;

bool Current_State = 0;
bool Previous_State = 0;

void State_Detector(bool Current, bool Previous)
{
  if(Current != Previous)
  {
    digitalWrite(LED_pin, Current);
    delay(300);
  }
}

void Shock_Sensor_analyzer()
{
  Pulse_Count = 0;

  unsigned long Start_Time = millis();

  while(millis() - Start_Time <= Pulse_Time)
  {
    if(digitalRead(Shock_pin) == LOW)
    {
      Pulse_Count = Pulse_Count + 1;
    }

    while(digitalRead(Shock_pin) == LOW);
  }

  Serial.print("Number of Pulses: "); Serial.println(Pulse_Count);

  if(Pulse_Count >= 1)
  {
    Current_State = !Previous_State;
    State_Detector(Current_State, Previous_State);
  }

  Previous_State = Current_State;
}

void setup()
{
  pinMode(Shock_pin, INPUT_PULLUP);
  pinMode(LED_pin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Shock_Sensor_analyzer();
}