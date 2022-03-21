#include "control_LED.h"

void oneLED(int x, int y, int r, int g, int b, Adafruit_NeoPixel strip) {
  int number;
  if (y%2 == 0) {
    number = y*12 + x;
  } else {
    number = y*12 + (11-x);
  }
    strip.setPixelColor(number, strip.Color(r/3, g/3, b/3));
}

void eraseAll(Adafruit_NeoPixel strip) {
  for (int i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  strip.show();
  delay(250);
  strip.show();
}

void allRandomColor(Adafruit_NeoPixel strip) {
  for (int x=0; x<=11; x++){
    for (int y=0; y<=11; y++){
      
      oneLED(x, y, random(0, 255), random(0, 255), random(0, 255), strip);
    }
  }
  strip.show();
}


void allColorTransition(Adafruit_NeoPixel strip) {
for (float i=0; i<strip.numPixels(); i++) {
    float r = (255 - (255*(i/144)))/3;
    float g = 0;
    float b = (255*(i/144))/3;
    strip.setPixelColor(i, strip.Color(r, g, b));
    strip.show();
    delay(100);
  }
  for (float i=strip.numPixels(); i>=0; i--) {
    float r = 0;
    float b = (255*(i/144))/3;
    float g = (255 - (255*(i/144)))/3;
    strip.setPixelColor(i, strip.Color(r, g, b));
    strip.show();
    delay(100);
  }
  for (float i=0; i<strip.numPixels(); i++) {
    float r = (255*(i/144))/3;
    float g = (255 - (255*(i/144)))/3;
    float b = 0;
    strip.setPixelColor(i, strip.Color(r, g, b));
    strip.show();
    delay(100);
  }
  for (float i=strip.numPixels(); i>=0; i--) {
    float b = (255 - (255*(i/144)))/3;
    float g = 0;
    float r = (255*(i/144))/3;
    strip.setPixelColor(i, strip.Color(r, g, b));
    strip.show();
    delay(100);
  }
  for (float i=0; i<strip.numPixels(); i++) {
    float r = 0;
    float g = (255*(i/144))/3;
    float b = (255 - (255*(i/144)))/3;
    strip.setPixelColor(i, strip.Color(r, g, b));
    strip.show();
    delay(100);
  }
  for (float i=strip.numPixels(); i>=0; i--) {
    float g = (255*(i/144))/3;
    float r = (255 - (255*(i/144)))/3;
    float b = 0;
    strip.setPixelColor(i, strip.Color(r, g, b));
    strip.show();
    delay(100);
  }
}
