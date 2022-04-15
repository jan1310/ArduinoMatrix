#ifndef CONTROL_LED_H
#define CONTROL_LED_H

void initializeStrip();
void oneLED(int x, int y, int r, int g, int b);
void eraseAll();
void allRandomColor();
void allColorTransition();
void character(char a, int x, int y);
void character(char a, int x, int y, int r, int g, int b);
void number(int a, int x, int y);
void number(int a, int x, int y, int r, int g, int b);
void showChar(bool charView[8][6], int x, int y);
void showChar(bool charView[8][6], int x, int y, int r, int g, int b);
void showStrip();
void laufschrift(char* text, int textLength);

#endif
