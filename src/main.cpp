#include <Arduino.h>
#include <Servo.h>
#include <lock/lock.h>
#include <rfid/rfid.h>


void setup() {
	Serial.begin(9600);	
	setupRfid();
	setupLock();
}

void loop(){

	if(userRFID == ""){
		configureRfidUser();
		lockAction(close);
	} else {
		boolean isValidUser = checkRfidUser();
		triggerLock(isValidUser);
	}
}