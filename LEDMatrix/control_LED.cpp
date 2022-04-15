#include "control_LED.h"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN      6
#define N_LEDS 144

bool charViewa[8][6] = { {0, 0, 1, 1, 0, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 1, 1, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 0, 0, 0, 0, 0} };
bool charViewb[8][6] = { {0, 1, 1, 1, 0, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 1, 0, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 1, 1, 0, 0} ,  {0, 0, 0, 0, 0, 0} };
bool charViewc[8][6] = { {0, 0, 1, 1, 1, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 0, 1, 1, 1, 0} ,  {0, 0, 0, 0, 0, 0} };
bool charViewd[8][6] = { {0, 1, 1, 1, 0, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 1, 1, 0, 0} ,  {0, 0, 0, 0, 0, 0} };
bool charViewe[8][6] = { {0, 1, 1, 1, 1, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 1, 1, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 1, 1, 1, 0} ,  {0, 0, 0, 0, 0, 0} };
bool charViewf[8][6] = { {0, 1, 1, 1, 1, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 1, 1, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 0, 0, 0, 0, 0} };
bool charViewg[8][6] = { {0, 0, 1, 1, 0, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 1, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 0, 1, 1, 1, 0} ,  {0, 0, 0, 0, 0, 0} };
bool charViewh[8][6] = { {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 1, 1, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 0, 0, 0, 0, 0} };
bool charViewi[8][6] = { {0, 0, 1, 1, 1, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 1, 1, 1, 0} ,  {0, 0, 0, 0, 0, 0} };
bool charViewj[8][6] = { {0, 1, 1, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 1, 1, 0, 0, 0} ,  {0, 0, 0, 0, 0, 0} };
bool charViewk[8][6] = { {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 1, 0, 0} ,  {0, 1, 1, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 1, 0, 0, 0} ,  {0, 1, 0, 1, 0, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 0, 0, 0, 0, 0} };
bool charViewl[8][6] = { {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 1, 1, 1, 0} ,  {0, 0, 0, 0, 0, 0} };
bool charViewm[8][6] = { {0, 1, 0, 0, 0, 1} ,  {0, 1, 1, 0, 1, 1} ,  {0, 1, 0, 1, 0, 1} ,  {0, 1, 0, 1, 0, 1} ,  {0, 1, 0, 1, 0, 1} ,  {0, 1, 0, 0, 0, 1} ,  {0, 1, 0, 0, 0, 1} ,  {0, 0, 0, 0, 0, 0} };
bool charViewn[8][6] = { {0, 1, 0, 0, 0, 1} ,  {0, 1, 0, 0, 0, 1} ,  {0, 1, 1, 0, 0, 1} ,  {0, 1, 0, 1, 0, 1} ,  {0, 1, 0, 0, 1, 1} ,  {0, 1, 0, 0, 0, 1} ,  {0, 1, 0, 0, 0, 1} ,  {0, 0, 0, 0, 0, 0} };
bool charViewo[8][6] = { {0, 0, 1, 1, 0, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 0, 1, 1, 0, 0} ,  {0, 0, 0, 0, 0, 0} };
bool charViewp[8][6] = { {0, 1, 1, 1, 0, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 1, 1, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 0, 0, 0, 0, 0} };
bool charViewq[8][6] = { {0, 0, 1, 1, 0, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 1, 1, 0} ,  {0, 0, 1, 1, 1, 1} ,  {0, 0, 0, 0, 0, 0} };
bool charViewr[8][6] = { {0, 1, 1, 1, 0, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 1, 1, 0, 0} ,  {0, 1, 1, 0, 0, 0} ,  {0, 1, 0, 1, 0, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 0, 0, 0, 0, 0} };
bool charViews[8][6] = { {0, 0, 1, 1, 0, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 0, 1, 1, 0, 0} ,  {0, 0, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 0, 1, 1, 0, 0} ,  {0, 0, 0, 0, 0, 0} };
bool charViewt[8][6] = { {0, 1, 1, 1, 1, 1} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 0, 0, 0} };
bool charViewu[8][6] = { {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 0, 1, 1, 0, 0} ,  {0, 0, 0, 0, 0, 0} };
bool charViewv[8][6] = { {0, 1, 0, 0, 0, 1} ,  {0, 1, 0, 0, 0, 1} ,  {0, 1, 0, 0, 0, 1} ,  {0, 1, 0, 0, 0, 1} ,  {0, 1, 0, 0, 0, 1} ,  {0, 0, 1, 0, 1, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 0, 0, 0} };
bool charVieww[8][6] = { {0, 1, 0, 0, 0, 1} ,  {0, 1, 0, 0, 0, 1} ,  {0, 1, 0, 1, 0, 1} ,  {0, 1, 0, 1, 0, 1} ,  {0, 1, 0, 1, 0, 1} ,  {0, 1, 1, 0, 1, 1} ,  {0, 1, 0, 0, 0, 1} ,  {0, 0, 0, 0, 0, 0} };
bool charViewx[8][6] = { {0, 1, 0, 0, 0, 1} ,  {0, 1, 0, 0, 0, 1} ,  {0, 0, 1, 0, 1, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 1, 0, 1, 0} ,  {0, 1, 0, 0, 0, 1} ,  {0, 1, 0, 0, 0, 1} ,  {0, 0, 0, 0, 0, 0} };
bool charViewy[8][6] = { {0, 1, 0, 0, 0, 1} ,  {0, 1, 0, 0, 0, 1} ,  {0, 0, 1, 0, 1, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 0, 0, 0} };
bool charViewz[8][6] = { {0, 1, 1, 1, 1, 1} ,  {0, 0, 0, 0, 0, 1} ,  {0, 0, 0, 0, 1, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 1, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 1, 1, 1, 1} ,  {0, 0, 0, 0, 0, 0} };
bool charView[8][6] = { {0, 0, 0, 0, 0, 0} ,  {0, 0, 0, 0, 0, 0} ,  {0, 0, 0, 0, 0, 0} ,  {0, 0, 0, 0, 0, 0} ,  {0, 0, 0, 0, 0, 0} ,  {0, 0, 0, 0, 0, 0} ,  {0, 0, 0, 0, 0, 0} ,  {0, 0, 0, 0, 0, 0} };
bool zero[8][6] = { {0, 0, 1, 1, 0, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 1, 0, 1, 0} ,  {0, 1, 0, 1, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 0, 1, 1, 0, 0} ,  {0, 0, 0, 0, 0, 0} };
bool one[8][6] = { {0, 0, 0, 1, 0, 0} ,  {0, 0, 1, 1, 0, 0} ,  {0, 1, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 0, 0, 0} };
bool two[8][6] = { {0, 0, 1, 1, 0, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 0, 0, 0, 1, 0} ,  {0, 0, 1, 1, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 1, 1, 1, 0} ,  {0, 0, 0, 0, 0, 0} };
bool three[8][6] = { {0, 0, 1, 1, 0, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 0, 0, 0, 1, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 0, 1, 1, 0, 0} ,  {0, 0, 0, 0, 0, 0} };
bool four[8][6] = { {0, 0, 0, 1, 0, 0} ,  {0, 0, 1, 0, 0, 0} ,  {0, 1, 0, 1, 0, 0} ,  {0, 1, 1, 1, 1, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 0, 0, 0, 0} };
bool five[8][6] = { {0, 1, 1, 1, 1, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 1, 1, 0, 0} ,  {0, 0, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 0, 1, 1, 0, 0} ,  {0, 0, 0, 0, 0, 0} };
bool six[8][6] = { {0, 0, 1, 1, 0, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 1, 1, 0, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 0, 1, 1, 0, 0} ,  {0, 0, 0, 0, 0, 0} };
bool seven[8][6] = { {0, 1, 1, 1, 1, 0} ,  {0, 0, 0, 0, 1, 0} ,  {0, 0, 0, 1, 0, 0} ,  {0, 0, 1, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 1, 0, 0, 0, 0} ,  {0, 0, 0, 0, 0, 0} };
bool eigth[8][6] = { {0, 0, 1, 1, 0, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 0, 1, 1, 0, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 0, 1, 1, 0, 0} ,  {0, 0, 0, 0, 0, 0} };
bool nine[8][6] = { {0, 0, 1, 1, 0, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 0, 1, 1, 1, 0} ,  {0, 0, 0, 0, 1, 0} ,  {0, 1, 0, 0, 1, 0} ,  {0, 0, 1, 1, 0, 0} ,  {0, 0, 0, 0, 0, 0} };

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void initializeStrip() {
  strip.begin();
}

void oneLED(int x, int y, int r, int g, int b) {
  int number;
  if (y%2 == 0) {
    number = y*12 + x;
  } else {
    number = y*12 + (11-x);
  }
    strip.setPixelColor(number, strip.Color(r/3, g/3, b/3));
}

void eraseAll() {
  for (int i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
}

void allRandomColor() {
  for (int x=0; x<=11; x++){
    for (int y=0; y<=11; y++){
      
      oneLED(x, y, random(0, 255), random(0, 255), random(0, 255));
    }
  }
  strip.show();
}

void showStrip() {
  strip.show();
}


void allColorTransition() {
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

void number(int a, int x, int y) {
  switch(a) {
    case 1:
      showChar(one, x, y);
      break;
    case 2:
      showChar(two, x, y);
      break;
    case 3:
      showChar(three, x, y);
      break;
    case 4:
      showChar(four, x, y);
      break;
    case 5:
      showChar(five, x, y);
      break;
    case 6:
      showChar(six, x, y);
      break;
    case 7:
      showChar(seven, x, y);
      break;
    case 8:
      showChar(eigth, x, y);
      break;
    case 9:
      showChar(nine, x, y);
      break;
    case 0:
      showChar(zero, x, y);
      break;
    default:
      showChar(charView, x, y);
      break;
  }
}

void character(char a, int x, int y) {
                                                                                                                                         
  switch(a) {
    case 'A':
    case 'a':
       showChar(charViewa, x, y);
      break;
    case 'B':
    case 'b':
       showChar(charViewb, x, y);
      break;
    case 'C':
    case 'c':
       showChar(charViewc, x, y);
      break;
    case 'D':
    case 'd':
       showChar(charViewd, x, y);
      break;
    case 'E':
    case 'e':
       showChar(charViewe, x, y);
      break;
    case 'F':
    case 'f':
       showChar(charViewf, x, y);
      break;
    case 'G':
    case 'g':
       showChar(charViewg, x, y);
      break;
    case 'H':
    case 'h':
       showChar(charViewh, x, y);
      break;
    case 'I':
    case 'i':
       showChar(charViewi, x, y);
      break;
    case 'J':
    case 'j':
       showChar(charViewj, x, y);
      break;
    case 'K':
    case 'k':
       showChar(charViewk, x, y);
      break;
    case 'L':
    case 'l':
       showChar(charViewl, x, y);
      break;
    case 'M':
    case 'm':
       showChar(charViewm, x, y);
      break;
    case 'N':
    case 'n':
       showChar(charViewn, x, y);
      break;
    case 'O':
    case 'o':
       showChar(charViewo, x, y);
      break;
    case 'P':
    case 'p':
       showChar(charViewp, x, y);
      break;
    case 'Q':
    case 'q':
       showChar(charViewq, x, y);
      break;
    case 'R':
    case 'r':
       showChar(charViewr, x, y);
      break;
    case 'S':
    case 's':
       showChar(charViews, x, y);
      break;
    case 'T':
    case 't':
       showChar(charViewt, x, y);
      break;
    case 'U':
    case 'u':
       showChar(charViewu, x, y);
      break;
    case 'V':
    case 'v':
       showChar(charViewv, x, y);
      break;
    case 'W':
    case 'w':
       showChar(charVieww, x, y);
      break;
    case 'X':
    case 'x':
       showChar(charViewx, x, y);
      break;
    case 'Y':
    case 'y':
       showChar(charViewy, x, y);
      break;
    case 'Z':
    case 'z':
       showChar(charViewz, x, y);
      break;
    default: 
       showChar(charView, x, y);
      break;
  }
}

void showChar(bool charView[8][6], int x, int y){
  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 6; column++) {
      if (charView[row][column] == true){ 
        oneLED(x + (7-row), y + column, 255, 255, 255);
      }
    }
  }
}

void laufschrift(char* text, int textLength) {
    for (int i = 0; i < textLength*6 + 12; i++) {
      eraseAll();
      for (int h = 0; h < textLength; h++) {
        character(text[h], 2, 12 + (h*6) - i);
      }
      strip.show();
      delay(100);
    }
  }
