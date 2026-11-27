#include <Servo.h>

int potValue;
Servo Servo1;
int angle;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  Servo1.attach(3);
}

void loop()
{
  potValue = analogRead(A0);      // 0 → 1023

  angle = map(potValue, 0, 1023, 0, 180);

  Servo1.write(angle);

  Serial.println(angle);
}