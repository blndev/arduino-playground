/*
  Blink

  Turns an LED on 3 times for 100 ms and then off for one second.

  based on Example of Arduino IDE

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

const int LEDBAR_1 = 2;
const int LEDBAR_10 = LEDBAR_1 + 9;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  for (int ledbar = LEDBAR_1; ledbar <= LEDBAR_10; ledbar++) pinMode(ledbar, HIGH);
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
  // wait for a second
  //delay(900);                       // wait for a second
  setBar(LOW);
}
