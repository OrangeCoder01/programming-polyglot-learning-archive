int TapSensorPin = 3;
int LED_pin = 2;

bool LED_State = 0;
bool Previous_TapSensor_State = 0;

void Stabilizing()
{

  
}

void Analyzing_The_Tap_Sensor_Response() {

  bool Triggering = digitalRead(TapSensorPin);

  if (Triggering != Previous_TapSensor_State && Triggering == 1) {

    LED_State = !LED_State;
    digitalWrite(LED_pin, LED_State);
  }

  Previous_TapSensor_State = Triggering;
  Serial.println(Triggering);
}


void setup() {

  pinMode(TapSensorPin, INPUT);
  pinMode(LED_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  Analyzing_The_Tap_Sensor_Response();
  delay(150);
}