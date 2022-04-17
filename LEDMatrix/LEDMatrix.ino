#include "apollo_eifel.h"
#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>

#include <SPI.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup()
{
initializeApollo();
SPI.begin();
mfrc522.PCD_Init();
pinMode (2, OUTPUT); // Der Pin 2 ist jetzt ein Ausgang (Hier wird eine LED angeschlossen)
}

void loop()
{
  marsLaufschrift();
  if (mfrc522.PICC_IsNewCardPresent()) {
    rocket();
    if (mfrc522.PICC_IsNewCardPresent()) {
      delay(2000);
      mars();
    }
    delay(2000);
  }
if ( ! mfrc522.PICC_IsNewCardPresent())
{
return;
}

if ( ! mfrc522.PICC_ReadCardSerial())
{
return;
}

long code=0;

for (byte i = 0; i < mfrc522.uid.size; i++)
{
code=((code+mfrc522.uid.uidByte[i])*10);
}

if (code==1393250) // Wenn der Zahlencode 1031720 lautet...

{ 

  eifelLaufschrift();
  rocket();
  delay(2000);
  earth();
  delay(2000);

} // Programmabschnitt schließen

} 
