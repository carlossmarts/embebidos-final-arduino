#include <Arduino.h>
#include <rfid/rfid.h>


void setup() {
	Serial.begin(9600);		
	while (!Serial);		
	SPI.begin();			
	mfrc522.PCD_Init();		


	userRFID = "";
}

void loop(){
	if(userRFID == ""){
		configureRfidUser();
	} else {
		checkRfidUser();
	}
}