
#include <Servo.h>

Servo MyServo;
int pot = A0;
int value;
int angle;

void setup() {

  MyServo.attach(3, 500, 2400);


void loop() {

  value = analogRead(pot);
  angle = map(value, 0, 1023, 0, 180);

  MyServo.write(angle);

  
}
