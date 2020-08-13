#ifndef _Flap_
#define _Flap_
#include <Servo.h>

class Flap{
    public:
        Flap(int minAngle,int maxAngle, int servoNumber);
        void drive(int input,int minInputPWM, int maxInputPWM);
        void servoBegin();
        int getPos();
        Servo servo;
    private:
        int minAngle;
        int maxAngle;
        int servoNumber;
        int pos=90;
};

#endif