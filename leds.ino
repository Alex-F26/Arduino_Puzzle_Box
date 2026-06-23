int blueLED = 9;
int yellowLED = 10;
int redLED = 11;

void setup() {

  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {

  digitalWrite(redLED, HIGH);
  delay(1000);
  digitalWrite(redLED, LOW);

  digitalWrite(yellowLED, HIGH);
  delay(1000);
  digitalWrite(yellowLED, LOW);

  digitalWrite(blueLED, HIGH);
  delay(1000);
  digitalWrite(blueLED, LOW);
  delay(1000);
}
