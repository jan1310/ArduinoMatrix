#ifndef CONTROL_LED_H
#define CONTROL_LED_H

void initializeStrip();
void oneLED(int x, int y, int r, int g, int b);
void eraseAll();
void allRandomColor();
void allColorTransition();
void character(char a, int x, int y);

#endif
