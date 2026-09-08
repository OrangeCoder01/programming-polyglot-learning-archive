How the the project works:

There three main particpant: 
1) Sensors.
2) Controller (MCU).
3) Actuators/Displays.

The sensors senses the shift in the enivronment and shift into electrical signals,
based on these electrical signals the controllers use logic, and based on that logic, a decision is made.
The actuators receive the decisions from the controller and proceed within the given task.

The sensor in the project is:
. Ultrasonic Sensor: For close-proximity object detection.

The controller is:
. Arduino UNO MCU: The Mind

The actuators/display are:
. Buzzer: For alerting that there is dispensing.
. RGB LED: Green light for dispensing (on), and red light for no action (off).
. Pumper: For pumping the water out.
. LCD: For Displaying "ON", or "OFF".

Electronic Components:
. Diode: This is one of the most crucial compnent, it protects the MCU and other devices from a dangerous reverse voltage from the Motor when turned off, the diode used in scenarios are called "Flyback diode"
. Transistor NPN: Also crucial, it acts as a switch and a buffer between the (diode and Motor) and (MCU and devices).
. 1pc 1K-OHM Resisors: 2x For RGB LED as it has no built-in resitors, 1pc 1K-OHM to the base of the transistor, 2pcs, 1pc 1K-OHM or none for the LCD, to control the light contrast of backlight and text.
. Wires: For electrical connections.
. 9v Battery for supplying the Motor.

The code:
###Object_detection()### function:

. Advanced timing logic instead doing of delays', such that in a large-scale system, The MCU does not waste time waiting for
  each line in the code, the implemented logic is as following, it checks this conditions "It is time or not", if "It is time", it executes it, if not, it passes to the next line,
  returning to it later.

. So the timing is introduced, there will be a current time which is the time from at which the MCU started and Last time is the reference time; because it is updated continuously.
  Static is a very crucial variable identity, a variable holding that variable identity does not get destroyed, nor be accesible outside the function it declared on.
  The interesting feature is its initalization logic:

  G_function()
  {
    Static int i = 0;
    i =+ 1;
    Serial.print("i = ");Serial.println(i);
  }

  The MCU will record the variable i in G_function(), i is initalized at zero and increments every loop, and enters each loop with the new assigned value from the previous loop

  i = 1
  i = 2
  i = 3
  i = 4
  i = 5
  .
  .
  .

  Check that as a mind exercise:
  F_Function()
  {
    static int i = 0;
    i =+ 1;
    if(i < 3)
    {
        Serial.print("Smaller than ");Serial.println("3");
    } 
    else if(i > 3 && i < 5)
    {
      Serial.print("Bigger than 3 ");Serial.print("and smaller than ");Serial.println(5);
    }
    else
    {
      Serial.println("3 and numbers Bigger or equal 5 ")
    }
  }

  Smaller than 3
  Smaller than 3
  3 and numbers Bigger or equal 5
  Bigger than 3 and smaller than 5
  Bigger than 3 and smaller than 5
  3 and numbers Bigger or equal 5
  3 and numbers Bigger or equal 5
  3 and numbers Bigger or equal 5
  .
  .
  .
  
  
. Writing static long int Last_trigger to tell that the reference time (Last_trigger) and the current time (Current_time).
  Current_time changes every loop as it is assigned with the calculated time since the time of start of the Arduino in the unit of micros
  If the difference between last time and current time exceeds every loop, 0, 20, 70, 300, 1000, 5000, 10000, and finally 20000
  There are no need to identify current_time as static

. if(Current_time - last_trigger >= 20000) becomes true the first time the elapsed time reaches or exceeds 20000 μs. It is executed once
  because Last_trigger is immediately updated, causing the elapsed time to return near zero.
  The MCU timing logic might slip the critical number 20000, if the variables are initalized as float
  for example, in one loop, the Current_time = 19999.56, and in the next, 20000.32
  So static long int is advisied, Curent_time is approximated ~= 20000 & 20001.

. Static bool Trigger_state is a helpful boolean variable to seperate the if conditionals from overlapping by making some specific and distictive that others
  It is initialized as false (0) and remains until the first condition if(current_time - Last_tigger >= 20000) is executed, toggling into true (1).
  It is set true only once when the Trigger pin is set HIGH, and afterwards it returns to false, signaling for that calculating the distance in the final
  condition if(Trigger_state == false && Current_time - Last_time > 100).

 . Upon achieving this condition if(Curent_time = Last_trigger >= 20000), the tigger (Trig) pin of the Ultrasonic sensor is set HIGH, in order to release
   the sound waves. And the Last_tigger is updated to the Current_time. The trigger_state is set to be true.

 . In the next if condition if(Trigger_state == true && Current_time - Last_trigger >= 10) gives a 10 microsecond gap
   it sets the trig pin LOW and Trigger_state as false.

. if(Trigger_state == false && Current_time - Last_trigger > 100) gives 100 - 10 = 90 gaps since the last condition
  It calculates duration through determining how much time is the Echo pin was HIGH, meaning how much time is the signal out and did not return,
  The sound wave returned, Echo is set to LOW. The distance = (Speed of the sound wave )*(Duration)/2, it is divided by 2 as the sound wave move
  a distance and hit by the object and reflect back to the ultrasonic sensor, moving the distance twice.

. Inside the same condition, 
  if the distance less than 15, return true
  if the distance more than 15, return false
  This is crucial conclusion, based on it, the the other sensor will behave according to that decision

###LCD_Display### function

. it takes an input bool:
  if input bool = false, print "OFF"
  if input bool = true, print "ON"  

. But instead of continuous clearing of the display upon switching from ON to OFF, using similar boolean variables
  Static bool Prev_sign is the previous boolean input.
  bool Sign_1 is not static, it is memoryless, just like the Current_time logic.

. In the case that either there is nothing close to the ultrasonic sensor, it output false, and vice versa when speaking about the "ON"
  state. In each one, there is a continuous stream of boolean conclusions/decisions, 0 0 0 0 0 0 0, or 1 1 1 1 1 1 1 1
  The critical point is to detect a shift or change, 0 0 0 0 0 1 1 1 1 1
                                                             ---
  The LCD does not clear except once at that specific shift

. If Sign_1 = 0 and Prev_sign = 0, then the second condition is executed: if(sign_1 == true)
  and a nested condition if Sign_1 != Prev_sign, it will clear the LCD and prints the "ON", and will continue
  without the nested condition as long the Prev_sign = Sign_1 = 1|
  The same logic but inverted if Sign_1 = 0.

##RGB_LED_state_indicator()## & ##Water_motor_dispenser()## functions

. Their logic is simple, 
  if the input decision is true, turn the pumper ON and RGB is set to green
  if the input decision is false, turn the pumper OFF and RGB is set to red

##Buzzer_warning(bool state)## function

. This function for buzzer could be made simple, but pragmatically, it would be annoying and redundantly repulsive
  because the buzzer when buzzing at a constant frequency makes it sound like a wasp, in addition to the
  continuous state of buzzing as long as the decision is still 1.

. The logic used has similar correlations with those in previous functions and some are new, 
  static bool previous_state stores the last state of the input
  input decision which is bool state is used, rather than a new parameter that is assigned to it
  const int melody[] is the selected frequencies that the buzzer can buzz.
  static int note is variable that helps in identifying which array placeholder in the melody[], whcih are the specific frequecncy
  static unsigned long last_change acts the same as the timming logic used before, it gives a space for each frequency to be outputted from the buzzer
  static bool playing is used to halt the process of continuous buzzing or permit it continuation.

. if(state && ! preious_state) is a logical operation condition, if condition is excecuted only is the premise is true
  state && ! previous_state must be true, as an example, in a continuous decision state = false 0 and previous_state = 0
  if(state) is executed onlt if state = 1, it is the same as if(state == 1)
  if(!previous_state) is the NOT Gate for a boolean value, meaning it inverts the value of the bool, as an example 0 to 1 and 1 to 0
  if previous_state is true (1) !previous_state = 0
  if(state && !previous_state) is executed when state = 1 and preious_state = 0. That physically mean there is a change from "ON" to "OFF"

. in the first if condition, note place holder is set to zero, playing is set true to signal that the buzzer should be currently playing or should not
  last_change is assigned to the current millis(), the first frequency is to be release.

. Then the previous_state is updated.

. in the second condition, if(playing) is same logic as condition to indicate whether the following
  should be executed based on whether buzzer should play or not (playing = 1 or 0), Last_change logic is used to give a gap for each buzzing frequency if(millis() - last_change) >= 200, iterate the note
  and update the last_change
  one nested if conditions, to allow buzzing from the first zeroth note to the last fifth note, excceding that, will cause the execution of the else condition which entail
  no frequency should outputted and set playing to false.

. in the third condition is executed only when playing is flase and state is false, which eventually set the buzzer to not all any buzzing sound


##Integrating_the_project()## function

. Combining, integrating, or unifying the functions in a one function.

##setup()## function

. assigning the pins as inputs or outputs

##loop()## function

. The essential function that the Arduino compiler runs, which contains the Integrating_the_project() function



Thank you for your patience!

Hyperlink texts for:

1) [TinkerCAD](https://www.tinkercad.com/things/eZvYrkw7wTM-water-dispenser-/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard) Circuit design for the water dispenser project:

2) [YT video](https://studio.youtube.com/channel/UCjv-M0RC4VAx9AhodaJHAgA):


  

  

  
