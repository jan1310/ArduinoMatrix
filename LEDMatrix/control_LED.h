#ifndef CONTROL_LED_H
#define CONTROL_LED_H


#include <Arduino.h>

void initializeStrip();
bool getBit (byte byteArray[6], unsigned int absBitPos);
void oneLED(int x, int y, int r, int g, int b);
void eraseAll();
void allRandomColor();
void allColorTransition();
void character(char a, int x, int y);
void character(char a, int x, int y, int r, int g, int b);
void number(int a, int x, int y);
void number(int a, int x, int y, int r, int g, int b);
void showChar(byte charView[6], int x, int y);
void showChar(byte charView[6], int x, int y, int r, int g, int b);
void showStrip();
void laufschrift(char* text, int textLength);

#endif
