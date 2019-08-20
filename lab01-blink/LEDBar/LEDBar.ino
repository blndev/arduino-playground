/*
  LEDBar 
  
*/

const int LEDBAR_1 = 2;
const int LEDBAR_10 = LEDBAR_1 + 9;

const int SWITCH = 12;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600); // initialize the serial port, set the baud rate to 9600
  Serial.println("UNO is ready!");
  pinMode(SWITCH, INPUT);
  for (int ledbar = LEDBAR_1; ledbar <= LEDBAR_10; ledbar++) pinMode(ledbar, OUTPUT);
}

void setBar(int status)
{
  for (int led = LEDBAR_1; led <= LEDBAR_10; led++)
  {
    digitalWrite(led, status);
    delay(50);                         // wait for a second
  }
}

// the loop function runs over and over again forever
void loop() {
  //for (int ledbar = LEDBAR_1; ledbar <= LEDBAR_10; ledbar++) digitalWrite(ledbar, LOW);
  setBar(HIGH);
  if (digitalRead(SWITCH)==LOW){
    delay(10); //handle flickering
    Serial.println("Button pressed");

    for (int ledbar = LEDBAR_1; ledbar <= LEDBAR_10; ledbar++) digitalWrite(ledbar, LOW);
    while (digitalRead(SWITCH)==LOW){
        digitalWrite(LEDBAR_1, LOW);
        digitalWrite(LEDBAR_10, LOW);
        delay(100);
        digitalWrite(LEDBAR_1, HIGH);
        digitalWrite(LEDBAR_10, HIGH);
        delay(100);
    }
    Serial.println("Button released");
    for (int ledbar = LEDBAR_1; ledbar <= LEDBAR_10; ledbar++) digitalWrite(ledbar, HIGH);
  }//else{
  // wait for a second
  //delay(900);                       // wait for a second
  setBar(LOW);
  //}
}
