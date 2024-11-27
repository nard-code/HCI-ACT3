//define functions
//pinMode
//digitalWrite
//delay
//digitalRead

#define ledRed 5
#define ledYellow 4
#define ledGreen 2
#define ledBlue 19
#define pushBtn 15
#define buzzer 18

//setup
void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(pushBtn, INPUT);
}

//loop
void loop() {
  if(digitalRead(pushBtn) == LOW){
    digitalWrite(ledRed, HIGH);
    delay(200);
    digitalWrite(ledRed, LOW);

    digitalWrite(ledYellow, HIGH);
    delay(200);
    digitalWrite(ledYellow, LOW);
    
    digitalWrite(ledGreen, HIGH);
    delay(200);
    digitalWrite(ledGreen, LOW);

    digitalWrite(ledBlue, HIGH);
    delay(200);
    digitalWrite(ledBlue, LOW);
  }
  else{
       digitalWrite(ledRed, LOW);
       digitalWrite(ledYellow, LOW);
       digitalWrite(ledGreen, LOW);
       digitalWrite(ledBlue, LOW);
       digitalWrite(buzzer, HIGH);
  }
}
