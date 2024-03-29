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


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  for (int i = 0; i <= 3; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(150);                       // wait for a second
    digitalWrite(12, HIGH);
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(150);
    digitalWrite(12, LOW);
  }
  // wait for a second
  delay(900);                       // wait for a second
}
