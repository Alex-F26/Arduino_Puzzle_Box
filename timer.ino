int inputPin = 8;
int blueLED = 9;
boolean off = true;

void setup() {

  pinMode(inputPin, INPUT_PULLUP);
  pinMode(blueLED, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  int level;


  level = digitalRead(inputPin);
  Serial.println(level);
  delay(100);

if(off){
  if(level == 0){
    digitalWrite(blueLED, HIGH);
    for(int i = 0; i < 4; i++){
      delay(1000);

      if(i == 3){
        for(int j = 0; j < 10; j++){
          digitalWrite(blueLED, HIGH);
          delay(100);
          digitalWrite(blueLED, LOW);
          delay(100);
        }
        off = false;
        continue;
    }
    }
    
  }
}
  else{

    digitalWrite(blueLED, LOW);
    if(level == 1){
        off = true;
    }
  }

}
