#ifndef _Halley_
#define _Halley_
//#include <Servo.h>

class Flap
{
public:
    Flap(int minAngle, int maxAngle, int servoNumber);
    void drive(int input, int minInputPWM, int maxInputPWM);
    void begin();
    int getPos();
    int getControlPos();
    //Servo servo;

private:
    int minAngle;
    int maxAngle;
    int servoNumber;
    int pos = 90;
    int controlPos;
};

#endif