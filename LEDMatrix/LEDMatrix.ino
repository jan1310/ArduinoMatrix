#include "control_LED.h"
#include "control_button.h"

void setup() {
  initializeStrip();
}

void loop() {  
  if (isPressed(1)) {
    oneLED(0, 0, 255, 255, 255);
  } else {
    oneLED(0, 0, 0, 0, 0);
  }
  if (isPressed(2)) {
    oneLED(1, 1, 255, 255, 255);
  } else {
    oneLED(1, 1, 0, 0, 0);
  }
  if (isPressed(3)) {
    oneLED(2, 2, 255, 255, 255);
  } else {
    oneLED(2, 2, 0, 0, 0);
  }
  if (isPressed(4)) {
    oneLED(3, 3, 255, 255, 255);
  } else {
    oneLED(3, 3, 0, 0, 0);
  }
  if (isPressed(5)) {
    oneLED(4, 4, 255, 255, 255);
  } else {
    oneLED(4, 4, 0, 0, 0);
  }
  if (isPressed(6)) {
    oneLED(5, 5, 255, 255, 255);
  } else {
    oneLED(5, 5, 0, 0, 0);
  }
}
