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


// Behavior
const int WAVE_DELAY = 1000;
bool direction_right = true;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600); // initialize the serial port, set the baud rate to 9600
  Serial.println("UNO is ready!");
  pinMode(SWITCH_GREEN, INPUT);
  for (int led = 0; led <= LEDBAR_MAX; led++) pinMode(LEDBAR[led], OUTPUT);
}


bool check_button_green() {
  bool pressed = false;
  if (digitalRead(SWITCH_GREEN) == PRESSED) {
    delay(10); //handle button flickering
    if (digitalRead(SWITCH_GREEN) == PRESSED) {

      pressed = true;
      setBar(OFF, 0);
      while (digitalRead(SWITCH_GREEN) == PRESSED) {
        blink(ON);
        blink(OFF);
      }
      Serial.println("Button released");
      // invert direction
      direction_right = !direction_right;
      //setBar(ON, 0);
    }
  }
  return pressed;
}


void setBar(mode onoff, int pause)
{
  for (int led = 0; led <= LEDBAR_MAX; led++)
  {
    digitalWrite(LEDBAR[led], onoff);
    //if (check_button_green()) break;
    delay(pause);
  }
}

void setBarReverse(mode onoff, int pause)
{
  for (int led = LEDBAR_MAX; led >= 0; led--)
  {
    digitalWrite(LEDBAR[led], onoff);
    //if (check_button_green()) break;
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
  if (direction_right)waveBarRight(ON);
  else waveBarLeft(ON);
  check_button_green();
  if (direction_right)waveBarRight(OFF);
  else waveBarLeft(OFF);
  Serial.print(".");
}
