#include <LiquidCrystal.h>

const int RGB_R      = A2;
const int RGB_G      = A1;

const int Buzzer_pin = A0;

const int Register_pin = 13;
const int Enable_pin   = 12;
const int D4           = 11;
const int D5           = 10;
const int D6           = 9;
const int D7           = 8;

LiquidCrystal LCD(Register_pin, Enable_pin, D4, D5, D6, D7);

  
const int Trig_pin  = 4;
const int Echo_pin  = 3;
const int Motor_pin = 2;

float Value;


////////////////////////////////////////////

bool Object_detection()
{
  static long int Last_trigger = 0;
  static bool Trigger_state = false;
  static bool Is_there_detection = false;
  
  
  unsigned long Current_time = micros();
  
  if(Current_time - Last_trigger >= 20000)
  {
    Last_trigger = Current_time;
    Trigger_state = true;
    
    digitalWrite(Trig_pin, HIGH);
  }

  if(Trigger_state == true && (Current_time - Last_trigger >= 10))
  {
  	digitalWrite(Trig_pin, LOW);
    Trigger_state = false;
  }
  
  if(Trigger_state == false && (Current_time - Last_trigger) > 100)
  {
    float duration = pulseIn(Echo_pin, HIGH);
  	float Sound_wave_speed = 0.0343;//cm/micro-second
  	float distance = 0.5*(Sound_wave_speed)*(duration);
    Value = distance;
    
  	if(distance - 15.0 < 0)
  	{
     Is_there_detection = true;
  	}
  	else if(distance - 15.0 >= 0)
  	{
     Is_there_detection = false;
  	}
  }
 return Is_there_detection;
}

/////////////////////////////////////////////


void LCD_Display(bool state)
{
  bool Sign_1 = state;
  static bool Prev_sign = false;
  
  if(Sign_1 == true)
  {
    if(Prev_sign != Sign_1)
    {
      LCD.clear();
	  LCD.setCursor(0,0);
    }
    
    Prev_sign = Sign_1;
    
    LCD.print("         ");
    LCD.setCursor(0, 1);
    LCD.print("         ON");
  }
  
  else
  {
    if(Prev_sign != Sign_1)
    {
      LCD.clear();
	  LCD.setCursor(0,0);     
    }
    LCD.print("                ");
    LCD.setCursor(0, 1);
    LCD.print("         OFF");
    
	Prev_sign = Sign_1;
  }
}

///////////////////////////////////////////


void Water_motor_dispenser(bool state)
{
  bool Dispense_decision = state;
  
  if(Dispense_decision == true)
  {
    digitalWrite(Motor_pin, HIGH);
  }
  else
  {
    digitalWrite(Motor_pin, LOW );
  }
}

/////////////////////////////////////////////

void Buzzer_warning(bool state)
{
    static bool playing = false;
    static bool previous_state = false;

    static int note = 0;
    static unsigned long last_change = 0;

    const int melody[] =
    {
        1000,
        2000,
        3000,
        2000,
        1000
    };

    if(state && !previous_state)
    {
        playing = true;
        note = 0;
        last_change = millis();
        tone(Buzzer_pin, melody[note]);
    }

    previous_state = state;

    if(playing)
    {
        if(millis() - last_change >= 200)
        {
            note++;
            last_change = millis();

            if(note < 5)
            {
                tone(Buzzer_pin, melody[note]);
            }
            else
            {
                noTone(Buzzer_pin);
                playing = false;
            }
        }
    }

    if(!state && !playing)
    {
        noTone(Buzzer_pin);
    }
}
//////////////////////////////////////////////

void RGB_LED_state_indicator(bool state)
{
  bool State_1 = state;
  
  if(State_1 == true)
  {
    digitalWrite(RGB_R, LOW );
    digitalWrite(RGB_G, HIGH);
  }
  else
  {
    digitalWrite(RGB_R, HIGH);
    digitalWrite(RGB_G, LOW );
  }
}

/////////////////////////////////////////////////
//
void Integrating_the_project()
{
  bool detection_state  = Object_detection();
  
  Water_motor_dispenser(detection_state);
  LCD_Display(detection_state);



void setup()
{
  pinMode(RGB_R,        OUTPUT);
  pinMode(RGB_G,        OUTPUT);
  
  pinMode(Buzzer_pin,   OUTPUT);
  
  LCD.begin(16,2);
  
  pinMode(Trig_pin    ,OUTPUT);
  pinMode(Echo_pin    ,INPUT);
  
  pinMode(Motor_pin, OUTPUT);
  digitalWrite(Trig_pin, LOW);
}

void loop()
{
  Integrating_the_project();
}
    Buzzer_warning(detection_state);
  RGB_LED_state_indicator(detection_state);
}