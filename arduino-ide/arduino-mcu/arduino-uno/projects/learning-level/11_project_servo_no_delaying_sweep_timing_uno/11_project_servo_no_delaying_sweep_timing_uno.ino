const int Servo_pin = 2;
int Servo_Angle;

void setup() {
  pinMode(Servo_pin, OUTPUT);
}


void Servo_Angling(int Angle) {
  int Time_Of_HIGH = map(Angle, 0, 180, 1000, 2000);

  digitalWrite(Servo_pin, HIGH);
  delayMicroseconds(Time_Of_HIGH);
  digitalWrite(Servo_pin, LOW);
  delayMicroseconds(20000 - Time_Of_HIGH);
}



void loop() {
  Servo_Angle = 0;
  Servo_Angling(Servo_Angle);
  delay(3);

  for (Servo_Angle = 0; Servo_Angle < 180; Servo_Angle = Servo_Angle + 1)
  {
    Servo_Angling(Servo_Angle);
    delay(3);
  }
  while (Servo_Angle != 0) {
    Servo_Angling(Servo_Angle);
    Servo_Angle--;
    delay(3);
  }
}
