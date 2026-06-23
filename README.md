# Arduino_Puzzle_Box

Arduino Sketch that operates an interactive puzzle sequence involving two servos, three buttons, three LEDs and three light sensors.

This code was paried with the Arduino Uno and components to create a puzzle box
The box is a physical wooden box with slots for keys and opening doors

# Pin Mapping
- Servos: Pin 3 (Servo1) & Pin 2 (Servo2)
- Buttons: Pin 13 (Button 1), Pin 12 (Button 2), Pin 11 (Button 3)
- LEDs: Pins 8, 10, 9 (Blue LEDs - paired with 220 Ohm resistors)
- LEDs: Pins 7, 6 (Green LEDs - paired with 220 Ohm resistors)
- Sensors: A5 (Light Sensor 1), A4 (Light Sensor 2), A3 (Light Sensor 3)

# Logic
1. Reset at start: Servos are reset to position "5" (You would have Key 1 at this point)
2. Step 1: Pressing Button 1 turns on Blue LED 1 and sets Servo 1 to postion "150" (Door one opens and reveals the Key 2)
3. Step 2: Activating all three light sensors with values > 200 sets the "code" flag to "true", enabling the next steps (a small UV light was used for this step)
4. Step 3: Pressing Button 2 (While Servo 1 is active and code==True) turns on the Blue/Green Leds and moves servo 2 to position "150" (Door two opens and reveals Key 3)
5. Step 4: Pressing Button 3 (With all conditions met) triggers a looping, 15-step, alternating LED light show (It activates the Blue LEDs 1, 2, and 3 in different order)
