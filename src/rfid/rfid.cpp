#include <SPI.h>
#include <MFRC522.h>
#include <rfid/rfid.h>

MFRC522 mfrc522(SS_PIN, RST_PIN);

String userRFID = "";

void setupRfid(){
	while (!Serial);		
	SPI.begin();			
	mfrc522.PCD_Init();		
	userRFID = "";
}

void configureRfidUser(){
	Serial.println("Setear nuevo usuario");
	while(userRFID == ""){
		String uid = readRFID();
		if(uid != ""){
			userRFID = uid;
			Serial.println("usuario seteado");
			Serial.println("...");
			delay(500);
		}
	}
}

boolean checkRfidUser(){
	Serial.println("Acercar tarjeta o llavero para validar usuario");
	String uid = "";
	boolean isValidUser;
	while(uid == ""){
		uid = readRFID();
		if(uid != ""){
			if(uid.compareTo(userRFID) == 0){
				isValidUser = true;
				Serial.println("Usuario valido");
			} else{
				isValidUser = false;
				Serial.println("Usuario incorrecto");
			}
		}
	}
	return isValidUser;
}

String readRFID (){
	String uid = "";
	if ( mfrc522.PICC_IsNewCardPresent()) {
	  if ( mfrc522.PICC_ReadCardSerial()) {
		uid = getAsString(mfrc522.uid.uidByte);
		Serial.print("UID leido: ");
		Serial.println(uid);
	  }
	  mfrc522.PICC_HaltA();
	}
	//delay(500);
	return uid;
}

String getAsString(byte uid[10]){
	String str = "";
	for(byte i=0; i < mfrc522.uid.size; i++){
		if(str.length() > 0)
			str += "-";
		str += mfrc522.uid.uidByte[i];
	}
	return str;
}