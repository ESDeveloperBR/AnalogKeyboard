/*
Author: Eder Joao Santini
Library Download: https://github.com/ESDeveloperBR/AnalogKeyboard
Example of using the LIB AnalogKeyboard.
- Release key.
*/
#include <Arduino.h>
#include <AnalogKeyboard.h>

AnalogKeyboard keyboard(33);

// ********************************************************************************************************
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< SETUP >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// ********************************************************************************************************
void setup() {
  Serial.begin(115200);

}

// ********************************************************************************************************
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LOOP >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// ********************************************************************************************************
void loop() {
  if(keyboard.release(0)){
    Serial.println("Key 0 - RELASE");
  }
  if(keyboard.release(1)){
    Serial.println("Key 1 - RELASE");
  }
  if(keyboard.release(2)){
    Serial.println("Key 2 - RELASE");
  }
  if(keyboard.release(3)){
    Serial.println("Key 3 - RELASE");
  }
  if(keyboard.release(4)){
    Serial.println("Key 4 - RELASE");
  }
}