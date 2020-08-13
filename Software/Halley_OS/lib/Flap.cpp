#include "Flap.h"
#include <arduino.h>

Flap::Flap(int minAngle, int maxAngle, int servoNumber)
{
    this->minAngle = minAngle;
    this->maxAngle = maxAngle;
    this->servoNumber = servoNumber;
}

void Flap::servoBegin()
{
    servo.attach(servoNumber);
    servo.write(pos);
}
int Flap::getPos(){
    return pos;
}

void Flap::drive(int input, int minInputPWM, int maxInputPWM)
{
    pos = map(input, minInputPWM, maxInputPWM, minAngle, maxAngle);
    if (pos >= minAngle && pos <= maxAngle && pos != 0)
    {
        servo.write(pos);
    }
}
