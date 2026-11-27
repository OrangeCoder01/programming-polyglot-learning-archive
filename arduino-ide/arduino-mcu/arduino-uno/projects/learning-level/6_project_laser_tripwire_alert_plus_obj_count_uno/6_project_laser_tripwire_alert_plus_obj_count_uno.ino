
int PhotoElecResisPin = A0;

int LaserPin = 2;
int D4 = 4;
int D5 = 5;
int D6 = 6;
int D7 = 7;
int Rs = 10;
int E = 11;
int BuzzerPin = 13;

const int Threshold_PER = 150;
int Reference_PER;

int counter;
bool isbroken;


// LiquidCrystalDisplay LCD

void Pulse_E_Enabling() {

  digitalWrite(E, LOW);
  delayMicroseconds(5);

  digitalWrite(E, HIGH);
  delayMicroseconds(5);

  digitalWrite(E, LOW);
  delayMicroseconds(5);
}

void Assigning_D_pins(uint8_t Value) {
  digitalWrite(D4, Value >> 0 & 1);
  digitalWrite(D5, Value >> 1 & 1);
  digitalWrite(D6, Value >> 2 & 1);
  digitalWrite(D7, Value >> 3 & 1);

  delayMicroseconds(10);

  Pulse_E_Enabling();
}

void Sending(uint8_t Value, uint8_t Mode) {
  digitalWrite(Rs, Mode);

  Assigning_D_pins(Value >> 4 & 0x0F);
  Assigning_D_pins(Value);

  delayMicroseconds(50);
}

void LCD_Command(uint8_t Value) {
  a
    Sending(Value, LOW);
  delay(5);
}

void LCD_Print_Char(uint8_t Value) {

  Sending(Value, HIGH);
  delay(5);
}

void LCDprint(const char* str) {
  int i = 0;
  while (str[i] != '\0') {
    LCD_Print_Char(str[i]);
    i++;
  }
}

void LCD_Initialization() {
  delay(50);

  Assigning_D_pins(0x03);
  delay(50);
  Assigning_D_pins(0x03);
  delay(50);
  Assigning_D_pins(0x03);
  delay(50);

  Assigning_D_pins(0x02);
  delayMicroseconds(10);

  LCD_Command(0x28);
  delayMicroseconds(10);

  LCD_Command(0x0C);
  delayMicroseconds(10);

  LCD_Command(0x06);
  delayMicroseconds(10);

  LCD_Command(0x01);
  delayMicroseconds(10);
}

//////////////////////////////////

// PhotoelectricRessitor, ;

void Detection() {
  int value_PER = analogRead(PhotoElecResisPin);
  int Current_PE_Reading;

  if (value_PER >= Threshold_PER) {
    Current_PE_Reading = HIGH;
  } else {
    Current_PE_Reading = LOW;
  }

  Serial.print("Value: ");
  Serial.print(value_PER);
  Serial.println(" ");

  if (Current_PE_Reading == HIGH && Current_PE_Reading != Reference_PER) {
    LCD_Command(0x01);

    counter = counter + 1;

    LCDprint("Counter: ");
    delayMicroseconds(5);
    LCD_Command(0xC0);


    char buffer[10];
    itoa(counter, buffer, 10);
    LCDprint(buffer);

    digitalWrite(BuzzerPin, HIGH);

    delay(5);
  }

  else {
    LCD_Command(0x01);

    LCDprint("Counter: ");

    char buffer[10];
    itoa(counter, buffer, 10);
    LCDprint(buffer);

    delayMicroseconds(5);

    digitalWrite(BuzzerPin, LOW);
    //delay(5);
  }

  Reference_PER = Current_PE_Reading;
  //delay(5);
}

//////
// Implementing the code

void setup() {

  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(Rs, OUTPUT);

  pinMode(BuzzerPin, OUTPUT);

  pinMode(PhotoElecResisPin, INPUT);

  pinMode(LaserPin, OUTPUT);

  digitalWrite(LaserPin, HIGH);

  Reference_PER = HIGH;

  counter = 0;

  LCD_Initialization();
  Serial.begin(9600);
}

void loop() {
  delay(150);
  Detection();
}
