int E = 12;
int Rs = 13;
int D4 = 4;
int D5 = 5;
int D6 = 6;
int D7 = 7;
int CLK = 8;
int DT = 9;
int SW = 10;

int Reference_CLK;
//int Reference_DT;
//int Reference_SW;

void PulseEnable()
{
  digitalWrite(E, LOW);
  delayMicroseconds(2);

  digitalWrite(E, HIGH);
  delayMicroseconds(2);

  digitalWrite(E, LOW);
  delayMicroseconds(50);
}

void Rewriting_the_value_into_the_D_pins(uint8_t Single_Char_Val)
{
  digitalWrite(D4, (Single_Char_Val >> 0) & 1);
  digitalWrite(D5, (Single_Char_Val >> 1) & 1);
  digitalWrite(D6, (Single_Char_Val >> 2) & 1);
  digitalWrite(D7, (Single_Char_Val >> 3) & 1);

delayMicroseconds(1);

  PulseEnable();
}

void Send(uint8_t Single_Char_Val, uint8_t Mode )
{
  digitalWrite(Rs, Mode);
  Rewriting_the_value_into_the_D_pins(Single_Char_Val >> 4);
  Rewriting_the_value_into_the_D_pins(Single_Char_Val & 0x0F);
  delayMicroseconds(50);
}

void Command(uint8_t Single_Char_Val)
{
  Send(Single_Char_Val, LOW);
}

void PrintCharacter(uint8_t Single_Char_Val)
{
  Send(Single_Char_Val, HIGH);
}

void LCDprint(const char* str)
{
  while(*str)
  {
    PrintCharacter(*str);
    str++;
  }
}

void Initialization()
{
  delay(50);

  Rewriting_the_value_into_the_D_pins(0x03);
  delay(50);

  Rewriting_the_value_into_the_D_pins(0x03);
  delay(50);

  Rewriting_the_value_into_the_D_pins(0x03);
  delay(50);
 
  Rewriting_the_value_into_the_D_pins(0x02);
  delay(50);

  Command(0x28);
  Command(0x0C);
  Command(0x06);
  Command(0x01);

  delay(5);
}
void setup() 
{
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT); 
  pinMode(D7, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(Rs, OUTPUT);

  pinMode(CLK, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP);
  pinMode(SW, INPUT_PULLUP);

  Serial.begin(9600); 
  Initialization();
  Reference_CLK = digitalRead(CLK);
//  Reference_DT = digitalRead(DT);
}

void loop()
{
  int currentCLK = digitalRead(CLK);
  if(currentCLK !=  Reference_CLK  && currentCLK == HIGH)
  {
    delayMicroseconds(50);

    if(digitalRead(DT) == LOW)
    {
    Command(0x01);
    delay(5);
    
    LCDprint("ClockWise");
    Serial.println("ClockWise");
    }
    else if(digitalRead(DT) == HIGH)
    {
      Command(0x01);
      delay(5);

      LCDprint("AntiClockWise");
      Serial.println("AntiClockWise");
    }
  }

  if(digitalRead(SW) == LOW)
  {
    Command(0x01);
    delay(5);
  }
  delay(3);
  Reference_CLK = currentCLK;

}

 /*else if(currentDT =! Reference_DT && currentDT == HIGH )
  {
    if(digitalRead(currentCLK) == LOW)
    {
    clearScreen();
    LCDprint("ClockWise");
    Serial.println("ClockWise");
    }
    else if(digitalRead(currentCLK) == HIGH)
    {
    clearScreen();
    LCDprint("Anti-ClockWise");
    Serial.println("Anti-ClockWise");
    }

  }
}
*/
