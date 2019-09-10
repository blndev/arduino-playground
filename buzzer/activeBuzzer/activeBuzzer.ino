int buttonPin = 12; // the number of the push button pin
int buzzerPin = 9; // the number of the buzzer pin
void setup() {
  pinMode(buttonPin, INPUT);

  // Set push button pin into input mode
  pinMode(buzzerPin, OUTPUT); // Set Buzzer pin into output mode
}
void loop() {
  if (digitalRead(buttonPin) == HIGH)
  {
    digitalWrite(buzzerPin, LOW); // Turn off Buzzer
  }
  else // The button is pressed, if the pin is low level
  {

    for (int i = 0; i <= 3; i++) {
      digitalWrite(buzzerPin, HIGH);
      delay(50);
      digitalWrite(buzzerPin, LOW);
      delay(50);
      digitalWrite(buzzerPin, HIGH);
      delay(150);
      digitalWrite(buzzerPin, LOW);
      delay(150);
    }
  }
}
