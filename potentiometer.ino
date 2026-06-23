int r = 11;
int g = 10;
int b = 9;

int pot = A0;
int value;

void setup() {

  Serial.begin(9600);
  pinMode(pot, INPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {

  value = analogRead(pot)/4.5;
  //Serial.println(value);

if(value > 200){
  analogWrite(r, value/1.5);
  analogWrite(g, 0);
  analogWrite(b, 0);
}
else if(value > 150){
  analogWrite(r, 0);
  analogWrite(g, value/2);
  analogWrite(b, 0);
}
else if(value > 100){
  analogWrite(r, 0);
  analogWrite(b, value);
  analogWrite(g, 0);
}

}
