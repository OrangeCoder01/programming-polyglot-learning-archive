int MicAnalogPin = A0;
int LED_pin = 12;

const int Threshold_Value = 18;
const int DC_Offset = 545;

bool Current_State  = 0;
bool Previous_State = 0;

void Checking_State(bool Current, bool Previous)
{
  if(Current != Previous)
  {
    digitalWrite(LED_pin, Current);
  }
}

void Microphone_Response_To_Clapping()
{
  int AC_Ripple_Max = 0;

  // determining the Max peak of the shock wave by sampling 50 times
  for(int i = 0; i <= 50; i++)
  {
    int Signal_Value = analogRead(MicAnalogPin);
    int AC_Ripple = abs(Signal_Value - DC_Offset);

    if(AC_Ripple > AC_Ripple_Max)
    {
      AC_Ripple_Max = AC_Ripple;
    }

  }

  Serial.println(AC_Ripple_Max);

  bool Triggering = AC_Ripple_Max > Threshold_Value;

  if (Triggering == 1 && Previous_State == 0)
  {
    Current_State = !Current_State;
    digitalWrite(LED_pin, Current_State);
  }

  Previous_State = Triggering;
  delay(50);

}

void setup()
{
  pinMode(LED_pin , OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  Microphone_Response_To_Clapping();
}