#include "control_button.h"

int BUTTONS[] = {7, 8, 9, 10, 11, 12};

bool isPressed(int i) {
  if (digitalRead(BUTTONS[i-1]) == HIGH){
    return true;
  } else {
    return false;
  }
}
