#include <Adafruit_NeoPixel.h>
#include "control_LED.h"
#include "control_button.h"

#define PIN      6
#define N_LEDS 144

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
}

void loop() {  
  if (isPressed(1)) {
    allColorTransition(strip);
  }
}
