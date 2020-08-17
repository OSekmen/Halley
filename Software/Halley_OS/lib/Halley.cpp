//polymorphe controller lees functies maken.

#include "Halley.h"
#include <arduino.h>

Flap::Flap(int minAngle, int maxAngle, int servoNumber)
{
    this->minAngle = minAngle;
    this->maxAngle = maxAngle;
    this->servoNumber = servoNumber;
}

void Flap::begin()
{
    pinMode(servoNumber, OUTPUT);
    //servo.attach(servoNumber);
    //servo.write(pos);
}

int Flap::getPos()
{
    return pos;
}

int Flap::getControlPos()
{

    return controlPos;
}

void Flap::drive(int input, int minInputPWM, int maxInputPWM)
{
    pos = map(input, minInputPWM, maxInputPWM, minAngle, maxAngle);
    controlPos = pos - 90;
    if (pos >= minAngle && pos <= maxAngle && pos != 0)
    {
        //servo.write(pos);
    }
}
