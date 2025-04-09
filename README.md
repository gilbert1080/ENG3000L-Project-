# ENG3000L-Project-
This is the code of a line following robot for a class project
IR Sensor Line Following Robot - README.txt
Overview
This document provides information on the line following robots software implementation. This robot primarily makes use of two IR sensors to detect a black line and adjust its movements with four motors. 
Hardware Requirements (Code is intended for these specific components):

-Arduino board
-2 IR sensors (connected to analog pins A0 and A1)
-2 L298N motor drivers
-4 DC motors (2 front, 2 rear)
-Power supply for motors
-Chassis and wheels

Pin Configurations ( Code is intended for these specifics configurations)
Motor Driver 1 (Right Motors)

-Enable Pin (Variable name: enA): Digital Pin 10
-Right Front Motor: Digital Pins 9 (in1) and 8 (in2)
-Right Rear Motor: Digital Pins 7 (in3) and 6 (in4)

Motor Driver 2 (Left Motors)

-Enable Pin (Variable name: enB): Digital Pin 5
-Left Front Motor: Digital Pins 4 (in5) and 3 (in6)
-Left Rear Motor: Digital Pins 2 (in7) and 1 (in8)

IR Sensors

-Right Sensor (Variable name: R_S ): Analog Pin A0
-Left Sensor (Variable name:L_S): Analog Pin A1

Software Description (How does the code work)
The software implements a simple line following system where:

When both sensors read white surface: Move forward
Right sensor reads black, left on white: Turn left
Left sensor read black, right on white: Turn right
Both sensors read black: Reverse slightly (likely off the line and the robot must readjust)

Functions

moveForward(): Sets all motors to move forward
slightLeft(): Reduces speed of left motors for a slight left turn
slightRight(): Reduces speed of right motors for a slight right turn
reverseSlightly(): Briefly moves backward then stops when both sensors are off-track
stopMotors(): Halts all motor movement

Installation Instructions

Connect the hardware according to the pin configurations
Install Arduino IDE ( https://www.arduino.cc/en/software )
Connect Arduino board to your computer
Open the Arduino IDE and create a new sketch
Copy and paste the provided code
Select the correct board and port from the Tools menu
Click the Upload button to upload code to the Arduino

Troubleshooting

If the robot is not properly line as intended following try this:

Check sensor connections listed above and positioning
Adjust motor speeds by changing the analogWrite values (currently set to 180)
Modify the delay value in the reverseSlightly() function if needed


If motors are unresponsive:

Check motor connections and driver wirings
Verify the power supply has enough charge for the robot



Modification Guide( How to adjust the values above)

To change motor speed: Adjust the analogWrite values (0-255) in each movement function
To adjust turn sensitivity: Modify the reduced speed values in slightLeft() and slightRight()
To change reverse behavior: Adjust the delay time in reverseSlightly()
