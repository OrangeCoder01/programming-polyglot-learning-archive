
const int Vx = A0; // Y-Axis
const int Vy = A1; // X-Axis 
const int SW = 13; // My Joystick swapped the X-axis and Y-axis interpretations with the confusion between VRx and VRy, and that is a Hardware manufacturing mistake.

int prev_X_axis = 0;
int prev_Y_axis  = 0;
int prev_logical_Z_axis = 0;

void setup()
{
  pinMode(SW, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop()
{
  int X_axis = analogRead(Vy);
  int Y_axis = analogRead(Vx);
  int Logical_Z_axis = digitalRead(SW);

  int Mapped_X_axis = map(X_axis, 0, 1023, -511, 512);
  int Mapped_Y_axis = map(Y_axis, 0, 1023, -511, 512);

  if(abs(prev_X_axis - X_axis) > 10 || prev_logical_Z_axis != Logical_Z_axis || abs(prev_Y_axis - Y_axis) > 10)
  {

    Serial.println("==================================================");
    Serial.print("X_axis: ");Serial.print(Mapped_X_axis);Serial.println("");
    delay(50);

    Serial.print("Y_axis: ");Serial.print(Mapped_Y_axis);Serial.println("");
    delay(50);

    Serial.print("Logical Z axis: ");Serial.print(Logical_Z_axis);Serial.println("");
    Serial.println("==================================================");
    delay(50);
  }

  prev_logical_Z_axis = Logical_Z_axis;
  prev_X_axis = X_axis;
  prev_Y_axis = Y_axis;

}
