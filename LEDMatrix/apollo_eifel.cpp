#include "apollo_eifel.h"
#include "control_LED.h"
#include <Arduino.h>

void initializeApollo() {
  initializeStrip();
}

void countdown(){
  eraseAll();
  number(1,2,0,0,255,0);
  number(0,2,6,0,255,0);
  showStrip();
  delay(1000);
  eraseAll();
  number(9,2,3, 25, 225, 0);
  showStrip();
  delay(1000);
  eraseAll();
  number(8,2,3,50,200,0);
  showStrip();
  delay(1000);
  eraseAll();
  number(7,2,3,75,175,0);
  showStrip();
  delay(1000);
  eraseAll();
  number(6,2,3,100,150,0);
  showStrip();
  delay(1000);
  eraseAll();
  number(5,2,3,125,125,0);
  showStrip();
  delay(1000);
  eraseAll();
  number(4,2,3,150,100,0);
  showStrip();
  delay(1000);
  eraseAll();
  number(3,2,3,175,75,0);
  showStrip();
  delay(1000);
  eraseAll();
  number(2,2,3,200,50,0);
  showStrip();
  delay(1000);
  eraseAll();
  number(1,2,3,225,25,0);
  showStrip();
  delay(1000);
  eraseAll();
  number(0,2,3,255,0,0);
  showStrip();
  delay(1000);
}

void mars(){
  char* textMars = "Zielort Mars";
  laufschrift(textMars, 13);
}

void eifel(){
  char* textEifel = "Zielort Eifel";
  laufschrift(textEifel, 13);
}

void rocket(){
  oneLED(11, 5, 255, 0, 0);
  oneLED(11, 6, 255, 0, 0);
  oneLED(10, 4, 255, 0, 0);
  oneLED(10, 5, 255, 0, 0);
  oneLED(10, 6, 255, 0, 0);
  oneLED(10, 7, 255, 0, 0);
  oneLED(9, 4, 255, 255, 255);
  oneLED(9, 5, 255, 255, 255);
  oneLED(9, 6, 255, 255, 255);
  oneLED(9, 7, 255, 255, 255);
  oneLED(8, 3, 255, 255, 255);
  oneLED(8, 4, 255, 255, 255);
  oneLED(8, 5, 255, 0, 0);
  oneLED(8, 6, 255, 0, 0);
  oneLED(8, 7, 255, 255, 255);
  oneLED(8, 8, 255, 255, 255);
  oneLED(7, 2, 255, 0, 0);
  oneLED(7, 3, 255, 255, 255);
  oneLED(7, 4, 255, 0, 0);
  oneLED(7, 5, 0, 102, 204);
  oneLED(7, 6, 0, 102, 204);
  oneLED(7, 7, 255, 0, 0);
  oneLED(7, 8, 255, 255, 255);
  oneLED(7, 9, 255, 0, 0);
  oneLED(6, 2, 255, 0, 0);
  oneLED(6, 3, 255, 255, 255);
  oneLED(6, 4, 255, 0, 0);
  oneLED(6, 5, 0, 102, 204);
  oneLED(6, 6, 0, 102, 204);
  oneLED(6, 7, 255, 0, 0);
  oneLED(6, 8, 255, 255, 255);
  oneLED(6, 9, 255, 0, 0);
  oneLED(5, 3, 255, 255, 255);
  oneLED(5, 4, 255, 255, 255);
  oneLED(5, 5, 255, 0, 0);
  oneLED(5, 6, 255, 0, 0);
  oneLED(5, 7, 255, 255, 255);
  oneLED(5, 8, 255, 255, 255);
  oneLED(4, 3, 255, 255, 255);
  oneLED(4, 4, 255, 255, 255);
  oneLED(4, 5, 255, 255, 255);
  oneLED(4, 6, 255, 255, 255);
  oneLED(4, 7, 255, 255, 255);
  oneLED(4, 8, 255, 255, 255);
  oneLED(3, 3, 255, 0, 0);
  oneLED(3, 4, 255, 255, 255);
  oneLED(3, 5, 255, 0, 0);
  oneLED(3, 6, 255, 0, 0);
  oneLED(3, 7, 255, 255, 255);
  oneLED(3, 8, 255, 0, 0);
  oneLED(2, 2, 255, 0, 0);
  oneLED(2, 3, 255, 0, 0);
  oneLED(2, 4, 255, 255, 0);
  oneLED(2, 5, 255, 0, 0);
  oneLED(2, 6, 255, 0, 0);
  oneLED(2, 7, 255, 255, 0);
  oneLED(2, 8, 255, 0, 0);
  oneLED(2, 9, 255, 0, 0);
  oneLED(1, 1, 255, 255, 0);
  oneLED(1, 4, 255, 255, 0);
  oneLED(1, 5, 255, 0, 0);
  oneLED(1, 6, 255, 0, 0);
  oneLED(1, 7, 255, 255, 0);
  oneLED(1, 10, 255, 255, 0);
  oneLED(0, 2, 255, 255, 0);
  oneLED(0, 4, 255, 255, 0);
  oneLED(0, 5, 255, 255, 0);
  oneLED(0, 6, 255, 255, 0);
  oneLED(0, 7, 255, 255, 0);
  oneLED(0, 8, 255, 255, 0);
  showStrip();
}
