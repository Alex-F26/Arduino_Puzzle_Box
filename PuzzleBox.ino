
#include <Servo.h>

Servo myservo1;
Servo myservo2;


boolean Key_1_on = false;
boolean Key_2_on = false;
boolean Key_3_on = false;
boolean code = false;

int button1 = 13;
int button2 = 12;
int button3 = 11;

int blueLED1 = 8;
int blueLED2 = 10;
int blueLED3 = 9;

int greenLED1 = 7;
int greenLED2 = 6;

int countCeleb = 10;


const int lightSensor1 = A5; 
const int lightSensor2 = A4; 
const int lightSensor3 = A3; 

const int motor = 5;

boolean analogValue1 = false;
boolean analogValue2 = false;
boolean analogValue3 = false;

int temp1 = 0;
int temp2 = 0;
int temp3 = 0;

void setup() {

  Serial.begin(9600);

  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);

  myservo1.attach(3, 500, 2400);
  myservo2.attach(2, 500, 2400);


}

void loop() {
  

  if(!Key_1_on && !Key_2_on){
    myservo1.write(5);
    myservo2.write(5);
  }


  if(digitalRead(button1) == 0){
   digitalWrite(blueLED1, HIGH);
    Key_1_on = true;
  }

  if(Key_1_on){
    myservo1.write(150);
  }

  if(digitalRead(button2) == 0 && Key_1_on){
   digitalWrite(blueLED2, HIGH);
   Key_2_on = true;
  }

  if(Key_2_on && Key_1_on && code){
    digitalWrite(greenLED2, HIGH);
    myservo2.write(150);
  }

  if(digitalRead(button3) == 0 && Key_2_on && Key_1_on && code){
   
   Key_3_on = true;
    delay(500);
  for(int i = 0; i < countCeleb; i++){
    digitalWrite(blueLED1, HIGH);
    digitalWrite(blueLED2, HIGH);
    digitalWrite(blueLED3, HIGH);
  delay(300);
    digitalWrite(blueLED1, LOW);
    digitalWrite(blueLED2, LOW);
    digitalWrite(blueLED3, LOW);
  delay(300);
    digitalWrite(blueLED1, HIGH);
    delay(300);
    digitalWrite(blueLED2, HIGH);
    delay(300);
    digitalWrite(blueLED3, HIGH);
  delay(300);
    digitalWrite(blueLED1, LOW);
    delay(300);
    digitalWrite(blueLED2, LOW);
    delay(300); 
    digitalWrite(blueLED3, LOW);
  delay(300);
    digitalWrite(blueLED3, HIGH);
    delay(300);
    digitalWrite(blueLED2, HIGH);
    delay(300);
    digitalWrite(blueLED1, HIGH);
  delay(300);
    digitalWrite(blueLED3, LOW);
    delay(300);
    digitalWrite(blueLED2, LOW);
    delay(300); 
    digitalWrite(blueLED1, LOW);
  delay(300);
  }

  digitalWrite(blueLED3, HIGH);
  digitalWrite(blueLED2, HIGH);
  digitalWrite(blueLED1, HIGH);

  }

  if(analogValue1 > 200 && analogValue2 < 200 && analogValue3 < 200){

  }

  temp1 = analogRead(lightSensor1); 

if(temp1 > 200){
  analogValue1 = true;
}

  temp2 = analogRead(lightSensor2); 

if(temp2 > 200){
  analogValue2 = true;
}

  temp3 = analogRead(lightSensor3); 

if(temp3 > 200){
  analogValue3 = true;
}

  if(analogValue1 && !analogValue2 && analogValue3){
    analogValue1 = false;
    analogValue3 = false;
  }

  if(!analogValue1 && (analogValue2 || analogValue3)){
    analogValue2 = false;
    analogValue3 = false;
  }  


  if(analogValue1 && analogValue2 && analogValue3){
    code = true;
  }

  
delay(0);
  }

    


    

  

 



// F609FF00
// F807FF00