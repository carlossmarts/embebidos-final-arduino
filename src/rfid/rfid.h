#include <SPI.h>
#include <MFRC522.h>


#define RST_PIN         9       
#define SS_PIN          10

extern MFRC522 mfrc522;

extern String userRFID;

void setupRfid();

void configureRfidUser();

boolean checkRfidUser();

String readRFID ();

String getAsString(byte uid[10]);