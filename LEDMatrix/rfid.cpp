#include <Arduino.h>
#include "apollo_eifel.h"
#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>
#include <SPI.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);


void initializeRFID() {
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode (2, OUTPUT);
}

void wait(int ms) {
  Serial.begin(9600);
  for (int i=0; i < ms; i = i+100) {
    Serial.print(i);
    if ( mfrc522.PICC_IsNewCardPresent())
{

if ( mfrc522.PICC_ReadCardSerial())
{
  long code=0;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
  code=((code+mfrc522.uid.uidByte[i])*10);
  }
  if (code==1393250)
  { 
      initializeApollo();
      win();
      }
  }
}
  delay(100);
  }
  
}
