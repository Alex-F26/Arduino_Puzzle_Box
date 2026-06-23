
int blueLED = 11;
int yellowLED = 12;
int redLED = 13;
int whiteLED1 = 9;
int whiteLED2 = 10;

int button1 = 3;
int button2 = 4;

int buzzer = 7;

bool buttonPressed = 0;

#define NOTE_G3  196
#define NOTE_B0  31
#define NOTE_D8  4699

void setup() {
  
  pinMode(whiteLED1, OUTPUT);
  pinMode(whiteLED2, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);

  randomSeed(analogRead(A0));
  
  Serial.begin(9600);
}

void loop() {

  tone(buzzer, NOTE_G3, 1000);
  delay(1000);
  noTone(buzzer);

  digitalWrite(redLED, HIGH);
  delay(1000);
  digitalWrite(redLED, LOW);

  tone(buzzer, NOTE_B0, 1000);
  delay(1000);
  noTone(buzzer);

  digitalWrite(yellowLED, HIGH);
  delay(1000);
  digitalWrite(yellowLED, LOW);

  tone(buzzer, NOTE_D8, 1000);
  delay(1000);
  noTone(buzzer);

  digitalWrite(blueLED, HIGH);
  delay(random(900,4901));

  if(digitalRead(button1) == 0 && digitalRead(button2) == 0){
    digitalWrite(whiteLED1, LOW);
    digitalWrite(whiteLED2, LOW);
    buttonPressed = 1;
  }
  if(digitalRead(button1) == 0 && digitalRead(button2) != 0){
    digitalWrite(whiteLED1, LOW);
    digitalWrite(whiteLED2, HIGH);
    buttonPressed = 1;
  }
  if(digitalRead(button2) == 0 && digitalRead(button1) != 0){
    digitalWrite(whiteLED2, LOW);
    digitalWrite(whiteLED1, HIGH);
    buttonPressed = 1;
  }
  digitalWrite(blueLED, LOW);

  

  while(buttonPressed == 0){
    digitalWrite(whiteLED1, HIGH);
    digitalWrite(whiteLED2, HIGH);
    if(digitalRead(button1) == 0){
      buttonPressed = 1;
      digitalWrite(whiteLED2, LOW);
    }
    else if(digitalRead(button2) == 0){
      buttonPressed = 1;
      digitalWrite(whiteLED1, LOW);
    }
  }

  delay(1000);
  digitalWrite(whiteLED1, LOW);
  digitalWrite(whiteLED2, LOW);
  buttonPressed = 0;

}
