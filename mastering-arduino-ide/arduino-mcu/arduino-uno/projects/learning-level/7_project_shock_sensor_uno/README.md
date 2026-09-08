Shock-Sensor-as-an-Arduino-Project
Physical Explanation:

A shock sensor is a type of sensor that detects vibrations and transforms them into electrical signals.
There is a coil that vibrates/swing due to external intense shocks like hitting the desk or the breadboard.
Inside the sensor, there is a conductive spring and a central conductive rod. In normal condition, the shock sensor is HIGH,
but when the coil touches the rod due to vibration, it sets the shock sensor to LOW.

Theoretical Implementation:

A user would like to light and turn off an LED using knocking.

Code Explanation:

There are two functions:

State_Detector(), which is responsible for identifying whether the shock is for making the LED light up or for turning it off.
The boolean variables Current_State and Previous_State are helpful for solving that issue. At the moment when there is a discrepancy
between Previous_State and Current_State, that indicates that a shock has happened, then LED_pin should be assigned as HIGH or LOW
according to the value of Current_State.

Shock_sensor_analyzer(), its use is to calculate how many pulses (how many times it went LOW) occurred in a specific time range.
Due to the noisy and inconsistent behavior of the sensor (Shock Sensor KY-002 Module), the time should be small and
the number of pulses is set to be 1.

Setting the Start_Time from when the Arduino UNO board started functioning using millis(). The if condition checks whether
the new value of millis() minus the Start_Time is less than or equal to the constant time (Pulse_Time).

Then detecting how many times the coil makes contact with the conductive rod. Due to mechanical vibration, the signal is noisy
and produces multiple pulses from a single shock.

To detect the number of pulses, one should ensure that the Arduino UNO does not count the same LOW signal multiple times.
So a nested while loop is introduced:

while(digitalRead(Shock_pin) == LOW);

This ensures that each LOW signal is counted once by waiting until the signal returns to HIGH.

If the pulse count is more than or equal to 1 (threshold chosen experimentally due to sensor limitations),
then there is an indication that a shock occurred, meaning it is reasonable to change the state.
So using the logical NOT operator, the Current_State becomes the opposite of Previous_State.

Then using the State_Detector() to identify the state,
and finally assigning Previous_State as the Current_State.

(YouTube video)[https://www.youtube.com/shorts/B_wW2WJ-f0s]: