#include "apollo_eifel.h"
#include "control_LED.h"

void mars(){
  initializeStrip();
  char* textMars = "Zielort Mars";
  laufschrift(textMars, 13);
}

void eifel(){
  initializeStrip();
  char* textEifel = "Zielort Eifel";
  laufschrift(textEifel, 13);
  allColorTransition();
}
