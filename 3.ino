int ledPins[] = {15, 2, 4, 5, 18, 19, 21, 23}; // num leds esp32
int numLEDs = 8; // pcs ng lights

// Define buttons
int button1 = 12;
int button2 = 14; 
int button3 = 27;

void setup() {
  // Set LED pins as OUTPUT
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  // Set button pins as INPUT_PULLUP
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(button1) == LOW) {
    sequentialPattern();
  }
  if (digitalRead(button2) == LOW) {
    separatePattern();
  }
  if (digitalRead(button3) == LOW) {
    convergingPattern();
  }
}

void sequentialPattern() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(1000);
    digitalWrite(ledPins[i], LOW);
  }
}

void separatePattern() {
  for (int i = 0; i < numLEDs; i += 2) { 
    digitalWrite(ledPins[i], HIGH);
    delay(1000);
    digitalWrite(ledPins[i], LOW);
  }
  for (int i = 1; i < numLEDs; i += 2) {
    digitalWrite(ledPins[i], HIGH);
    delay(1000);
    digitalWrite(ledPins[i], LOW);
  }
}

void convergingPattern() {
  for (int i = 0; i < numLEDs / 2; i++) {
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[numLEDs - 1 - i], HIGH);
    delay(1000);
    digitalWrite(ledPins[i], LOW);
    digitalWrite(ledPins[numLEDs - 1 - i], LOW);
  }
}