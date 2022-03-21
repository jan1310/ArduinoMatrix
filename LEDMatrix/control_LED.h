#ifndef CONTROL_LED_H
#define CONTROL_LED_H
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

void oneLED(int x, int y, int r, int g, int b, Adafruit_NeoPixel strip);
void eraseAll(Adafruit_NeoPixel strip);
void allRandomColor(Adafruit_NeoPixel strip);
void allColorTransition(Adafruit_NeoPixel strip);

#endif
