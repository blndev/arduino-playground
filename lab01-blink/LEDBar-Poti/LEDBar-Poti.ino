//https://github.com/JChristensen/JC_Button
#include <JC_Button.h>

/*
  LEDBar

*/


#define ON HIGH
#define OFF LOW
#define mode int
#define PRESSED LOW

// OUTPUT

//Array allows us to use ports which are not in the same order for the led bar
const int LEDBAR[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
//sample for smaller led bar
//const int LEDBAR[] = {2, 4, 6, 8, 10};
const int LEDBAR_MAX = sizeof(LEDBAR) / sizeof(LEDBAR[0]) - 1; //automatic determine size of led bar

// INPUT
const int SWITCH_GREEN = 12;
ToggleButton switch_green(SWITCH_GREEN);

const int POTI_SPEED = 1;

// Behavior
//const int WAVE_DELAY = 1000;
bool direction_right = true;

int adcValue = 0;
#define WAVE_DELAY (1024-adcValue)
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600); // initialize the serial port, set the baud rate to 9600
  Serial.println("UNO is ready!");
  for (int led = 0; led <= LEDBAR_MAX; led++) pinMode(LEDBAR[led], OUTPUT);
  switch_green.begin();
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, ON);
}

void measure() {
  adcValue = analogRead(A0); // Convert analog of A0 port to digital
  float voltage = adcValue * (5.0 / 1023.0);// Calculate voltage according to digital
  // Send the result to computer through serial
  Serial.print("convertValue:");
  Serial.println(adcValue);
  Serial.print("Voltage:");
  Serial.println(voltage);
}

void setBar(mode onoff, int pause)
{
  for (int led = 0; led <= LEDBAR_MAX; led++)
  {
    digitalWrite(LEDBAR[led], onoff);
    switch_green.read();
    if (switch_green.changed()) return;
    delay(pause);
  }
}

void setBarReverse(mode onoff, int pause)
{
  for (int led = LEDBAR_MAX; led >= 0; led--)
  {
    digitalWrite(LEDBAR[led], onoff);
    //if (check_button_green()) break;
    switch_green.read();
    if (switch_green.changed()) return;

    delay(pause);
  }
}


void waveBarRight(mode onoff)
{
  //turn on/off leds with 50ms delay for 10 led and longer for less (keep timing)
  setBar(onoff, WAVE_DELAY / LEDBAR_MAX + 1);
}


void waveBarLeft(mode onoff)
{
  //turn on/off leds with 50ms delay for 10 led and longer for less (keep timing)
  setBarReverse(onoff, WAVE_DELAY / LEDBAR_MAX + 1);
}

void blink(mode onoff) {
  digitalWrite(LEDBAR[0], onoff);
  digitalWrite(LEDBAR[LEDBAR_MAX], onoff);
  delay(100);
}


void loop() {
  measure();
  if (switch_green.changed()) {
    Serial.println("changed");
    digitalWrite(LED_BUILTIN, switch_green.toggleState());
  }

  switch_green.read();
  //delay(50);


  if (switch_green.toggleState())waveBarRight(ON);
  else waveBarLeft(ON);
  if (switch_green.toggleState())waveBarRight(OFF);
  else waveBarLeft(OFF);
  Serial.print(".");

  //Serial.print(switch_green.read());
}
