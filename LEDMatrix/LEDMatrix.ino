#include "apollo_eifel.h"

void setup() {
  initializeApollo();
}

void loop() {
  rocket();
  delay(2000);
  earth();
  delay(2000);
}
