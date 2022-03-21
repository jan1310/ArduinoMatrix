#ifndef CONTROL_LED_H
#define CONTROL_LED_H
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

void initializeStrip();
void oneLED(int x, int y, int r, int g, int b);
void eraseAll();
void allRandomColor();
void allColorTransition();

#endif
