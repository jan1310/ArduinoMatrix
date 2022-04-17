#include "apollo_eifel.h"
#include "rfid.h"


void setup()
{
  initializeApollo();
  initializeRFID();
}

void loop()
{
  marsLaufschrift();
  rocket();
  wait(2000);
  mars();
  wait(2000);
} 
