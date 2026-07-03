#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal LC(13,12,2,3,4,5);
Servo S1;
#define BaudRate 9600

int angle;
int Pot_Value;

void setup()
{ 
  Serial.begin(BaudRate);
  S1.attach(8);
  LC.begin(16,2);
}

void loop()
{
  LC.clear();
  LC.setCursor(0,0);
  
  Pot_Value = analogRead(A0);
  angle = map(Pot_Value, 0, 1023, 0, 180);
  S1.write(angle);
  
  LC.print("Angle: ");
  LC.setCursor(0,1);
  LC.print(angle);
  
  Serial.println(angle);
  delay(200);
}