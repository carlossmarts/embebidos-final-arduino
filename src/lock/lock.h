#define servoPin    6
#define open        0
#define close       90
#define ledA        2
#define ledR        3

extern boolean isOpen;
extern Servo myServo;


void setupLock();

void lockAction(int openOrClose);

void triggerLock(boolean isValidUser);