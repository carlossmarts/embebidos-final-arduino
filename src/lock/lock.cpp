#include <Arduino.h>
#include <Servo.h>
#include <lock/lock.h>

boolean isOpen = false;
Servo myServo;

void setupLock(){
    pinMode(ledA, OUTPUT);
	pinMode(ledR, OUTPUT);
	digitalWrite(ledA, LOW);
	digitalWrite(ledR, LOW);

	myServo.attach(servoPin);
	lockAction(open);
}

void lockAction(int openOrClose){
	myServo.write(openOrClose);
}

void triggerLock(boolean isValidUser){
	if(isValidUser){
		if(isOpen){
			lockAction(close);
			digitalWrite(ledA, LOW);
			digitalWrite(ledR, LOW);
		}
		else{
			lockAction(open);
			digitalWrite(ledA, HIGH);
		}
		isOpen =!isOpen;
	} else{
		for(int i=0; i<3; i++){
			digitalWrite(ledR, HIGH);
			delay(1000);
			digitalWrite(ledR, LOW);
			delay(500);
		}
	}
}