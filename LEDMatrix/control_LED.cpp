#include "control_LED.h"
#include <Adafruit_NeoPixel.h>

byte charViewAByte[6] = { 49 , 36 , 146 , 121 , 36 , 128 };
byte charViewBByte[6] = { 113 , 36 , 148 , 73 , 39 , 0 };
byte charViewCByte[6] = { 57 , 4 , 16 , 65 , 3 , 128 };
byte charViewDByte[6] = { 113 , 36 , 146 , 73 , 39 , 0 };
byte charViewEByte[6] = { 121 , 4 , 28 , 65 , 7 , 128 };
byte charViewFByte[6] = { 121 , 4 , 28 , 65 , 4 , 0 };
byte charViewGByte[6] = { 49 , 36 , 22 , 73 , 35 , 128 };
byte charViewHByte[6] = { 73 , 36 , 158 , 73 , 36 , 128 };
byte charViewIByte[6] = { 56 , 65 , 4 , 16 , 67 , 128 };
byte charViewJByte[6] = { 112 , 65 , 4 , 16 , 70 , 0 };
byte charViewKByte[6] = { 73 , 70 , 16 , 97 , 68 , 128 };
byte charViewLByte[6] = { 65 , 4 , 16 , 65 , 7 , 128 };
byte charViewMByte[6] = { 69 , 181 , 85 , 85 , 20 , 64 };
byte charViewNByte[6] = { 69 , 22 , 85 , 77 , 20 , 64 };
byte charViewOByte[6] = { 49 , 36 , 146 , 73 , 35 , 0 };
byte charViewPByte[6] = { 113 , 36 , 156 , 65 , 4 , 0 };
byte charViewQByte[6] = { 49 , 36 , 146 , 73 , 99 , 192 };
byte charViewRByte[6] = { 113 , 36 , 156 , 97 , 68 , 128 };
byte charViewSByte[6] = { 49 , 36 , 12 , 9 , 35 , 0 };
byte charViewTByte[6] = { 124 , 65 , 4 , 16 , 65 , 0 };
byte charViewUByte[6] = { 73 , 36 , 146 , 73 , 35 , 0 };
byte charViewVByte[6] = { 69 , 20 , 81 , 68 , 161 , 0 };
byte charViewWByte[6] = { 69 , 21 , 85 , 85 , 180 , 64 };
byte charViewXByte[6] = { 69 , 18 , 132 , 41 , 20 , 64 };
byte charViewYByte[6] = { 69 , 18 , 132 , 16 , 65 , 0 };
byte charViewZByte[6] = { 124 , 16 , 132 , 33 , 7 , 192 };
byte charViewByte[6] = { 0 , 0 , 0 , 0 , 0 , 0 };
byte zero[6] = { 49 , 36 , 154 , 89 , 35 , 0 };
byte one[6] = { 16 , 197 , 4 , 16 , 65 , 0 };
byte two[6] = { 49 , 32 , 140 , 65 , 7 , 128 };
byte three[6] = { 49 , 32 , 132 , 9 , 35 , 0 };
byte four[6] = { 16 , 133 , 30 , 16 , 65 , 0 };
byte five[6] = { 121 , 4 , 28 , 9 , 35 , 0 };
byte six[6] = { 49 , 36 , 28 , 73 , 35 , 0 };
byte seven[6] = { 120 , 33 , 8 , 65 , 4 , 0 };
byte eigth[6] = { 49 , 36 , 140 , 73 , 35 , 0 };
byte nine[6] = { 49 , 36 , 142 , 9 , 35 , 0 };

Adafruit_NeoPixel strip = Adafruit_NeoPixel(144, 6, NEO_GRB + NEO_KHZ800);

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
      showChar(charViewByte, x, y);
      break;
  }
}

void number(int a, int x, int y, int r, int g, int b) {
  switch(a) {
    case 1:
      showChar(one, x, y, r, g, b);
      break;
    case 2:
      showChar(two, x, y, r, g, b);
      break;
    case 3:
      showChar(three, x, y, r, g, b);
      break;
    case 4:
      showChar(four, x, y, r, g, b);
      break;
    case 5:
      showChar(five, x, y, r, g, b);
      break;
    case 6:
      showChar(six, x, y, r, g, b);
      break;
    case 7:
      showChar(seven, x, y, r, g, b);
      break;
    case 8:
      showChar(eigth, x, y, r, g, b);
      break;
    case 9:
      showChar(nine, x, y, r, g, b);
      break;
    case 0:
      showChar(zero, x, y, r, g, b);
      break;
    default:
      showChar(charViewByte, x, y, r, g, b);
      break;
  }
}

void character(char a, int x, int y) {
                                                                                                                                         
  switch(a) {
    case 'A':
    case 'a':
       showChar(charViewAByte, x, y);
      break;
    case 'B':
    case 'b':
       showChar(charViewBByte, x, y);
      break;
    case 'C':
    case 'c':
       showChar(charViewCByte, x, y);
      break;
    case 'D':
    case 'd':
       showChar(charViewDByte, x, y);
      break;
    case 'E':
    case 'e':
       showChar(charViewEByte, x, y);
      break;
    case 'F':
    case 'f':
       showChar(charViewFByte, x, y);
      break;
    case 'G':
    case 'g':
       showChar(charViewGByte, x, y);
      break;
    case 'H':
    case 'h':
       showChar(charViewHByte, x, y);
      break;
    case 'I':
    case 'i':
       showChar(charViewIByte, x, y);
      break;
    case 'J':
    case 'j':
       showChar(charViewJByte, x, y);
      break;
    case 'K':
    case 'k':
       showChar(charViewKByte, x, y);
      break;
    case 'L':
    case 'l':
       showChar(charViewLByte, x, y);
      break;
    case 'M':
    case 'm':
       showChar(charViewMByte, x, y);
      break;
    case 'N':
    case 'n':
       showChar(charViewNByte, x, y);
      break;
    case 'O':
    case 'o':
       showChar(charViewOByte, x, y);
      break;
    case 'P':
    case 'p':
       showChar(charViewPByte, x, y);
      break;
    case 'Q':
    case 'q':
       showChar(charViewQByte, x, y);
      break;
    case 'R':
    case 'r':
       showChar(charViewRByte, x, y);
      break;
    case 'S':
    case 's':
       showChar(charViewSByte, x, y);
      break;
    case 'T':
    case 't':
       showChar(charViewTByte, x, y);
      break;
    case 'U':
    case 'u':
       showChar(charViewUByte, x, y);
      break;
    case 'V':
    case 'v':
       showChar(charViewVByte, x, y);
      break;
    case 'W':
    case 'w':
       showChar(charViewWByte, x, y);
      break;
    case 'X':
    case 'x':
       showChar(charViewXByte, x, y);
      break;
    case 'Y':
    case 'y':
       showChar(charViewYByte, x, y);
      break;
    case 'Z':
    case 'z':
       showChar(charViewZByte, x, y);
      break;
    default: 
       showChar(charViewByte, x, y);
      break;
  }
}

void character(char a, int x, int y, int r, int g, int b) {
                                                                                                                                         
  switch(a) {
    case 'A':
    case 'a':
       showChar(charViewAByte, x, y, r, g, b);
      break;
    case 'B':
    case 'b':
       showChar(charViewBByte, x, y, r, g, b);
      break;
    case 'C':
    case 'c':
       showChar(charViewCByte, x, y, r, g, b);
      break;
    case 'D':
    case 'd':
       showChar(charViewDByte, x, y, r, g, b);
      break;
    case 'E':
    case 'e':
       showChar(charViewEByte, x, y, r, g, b);
      break;
    case 'F':
    case 'f':
       showChar(charViewFByte, x, y, r, g, b);
      break;
    case 'G':
    case 'g':
       showChar(charViewGByte, x, y, r, g, b);
      break;
    case 'H':
    case 'h':
       showChar(charViewHByte, x, y, r, g, b);
      break;
    case 'I':
    case 'i':
       showChar(charViewIByte, x, y, r, g, b);
      break;
    case 'J':
    case 'j':
       showChar(charViewJByte, x, y, r, g, b);
      break;
    case 'K':
    case 'k':
       showChar(charViewKByte, x, y, r, g, b);
      break;
    case 'L':
    case 'l':
       showChar(charViewLByte, x, y, r, g, b);
      break;
    case 'M':
    case 'm':
       showChar(charViewMByte, x, y, r, g, b);
      break;
    case 'N':
    case 'n':
       showChar(charViewNByte, x, y, r, g, b);
      break;
    case 'O':
    case 'o':
       showChar(charViewOByte, x, y, r, g, b);
      break;
    case 'P':
    case 'p':
       showChar(charViewPByte, x, y, r, g, b);
      break;
    case 'Q':
    case 'q':
       showChar(charViewQByte, x, y, r, g, b);
      break;
    case 'R':
    case 'r':
       showChar(charViewRByte, x, y, r, g, b);
      break;
    case 'S':
    case 's':
       showChar(charViewSByte, x, y, r, g, b);
      break;
    case 'T':
    case 't':
       showChar(charViewTByte, x, y, r, g, b);
      break;
    case 'U':
    case 'u':
       showChar(charViewUByte, x, y, r, g, b);
      break;
    case 'V':
    case 'v':
       showChar(charViewVByte, x, y, r, g, b);
      break;
    case 'W':
    case 'w':
       showChar(charViewWByte, x, y, r, g, b);
      break;
    case 'X':
    case 'x':
       showChar(charViewXByte, x, y, r, g, b);
      break;
    case 'Y':
    case 'y':
       showChar(charViewYByte, x, y, r, g, b);
      break;
    case 'Z':
    case 'z':
       showChar(charViewZByte, x, y, r, g, b);
      break;
    default: 
       showChar(charViewByte, x, y, r, g, b);
      break;
  }
}

void showChar(byte charView[6], int x, int y){
  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 6; column++) {
      if (getBit(charView, row*6 + column)){ 
        oneLED(x + (7-row), y + column, 255, 255, 255);
      }
    }
  }
}

void showChar(byte charView[6], int x, int y, int r, int g, int b){
  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 6; column++) {
      if (getBit(charView, row*6 + column)){ 
        oneLED(x + (7-row), y + column, r, g, b);
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
bool getBit (byte byteArray[6], unsigned int absBitPos) {
  unsigned int bytePos = absBitPos / 8;
  unsigned int bitPos = 7 - (absBitPos % 8);                         
  return (bool) ( byteArray[bytePos] & (1 << bitPos) ); 
}
