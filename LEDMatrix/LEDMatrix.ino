#include "apollo_eifel.h"

void setup() {
  initializeApollo();
}

void loop() {
  eifelLaufschrift();
  rocket();
  delay(1000);
  earth();
  delay(1000);
  marsLaufschrift();
  rocket();
  delay(1000);
  mars();
  delay(1000);
  countdown();
}
