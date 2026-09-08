# Tripwire-counter-for-object-detected
It is a simple Arduino IDE code for building a tripwire counter 
for the number of detections of objects that crossed the laser wire
set between the Laser Module and PhotoElectricResistor.

The idea is simply:
The PhotoElectricResistor long for (PER) has a resistance that is inversely
proportional with the light intensity, meaning that when light intensity increases
the resistance in PER decrease and vice versa.

Then there is a fixed resisor is added to help making a voltage division.
using "analogRead", one can measure the voltage (0 ~ 5V ) mapped into (0 ~ 1023).
Thus introducing a threshold as a standard level.

if the value excceded, then currentvalue becomes HIGH, otherwise LOW,
knowing the referencevalue, one can detect the edge change from HIGH to LOW by using
using the IF conditions mentioned in function " Detection() "

Then adding a buzzer for edge change detection

What is the purpose of this project?
Used for detecting moving objects and acts as a counter for counting
number of movements meaning, instead of counting down how many pushups
one makes, the project can do it instead.

(YouTube Video)[https://youtube.com/shorts/DwIPAKYMzIM]:

