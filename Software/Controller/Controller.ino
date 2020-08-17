#include <Servo.h>
#include <arduino.h>
#include <RF24.h>
#include <SPI.h>
#include "lib\Controller.cpp"
#include "lib\Controller.h"

#define THROTTLE_PIN 18
#define ROLL_PIN 21
#define PITCH_PIN 20
#define YAW_PIN 19

Controller Controller(THROTTLE_PIN, YAW_PIN, PITCH_PIN, ROLL_PIN);

RF24 radio(7, 8);

byte addresses[][6] = {"1Node", "2Node"};

void setup()
{
  Serial.begin(115200);
  radio.begin();
  radio.setPALevel(RF24_PA_LOW);

  radio.openWritingPipe(addresses[0]);
  radio.openReadingPipe(1, addresses[1]);

  radio.startListening();
}

void loop()
{
  sendData(Controller.getThrottle(), Controller.getRoll(), Controller.getPitch(), Controller.getYaw());
}

void sendData(int _throttle, int _roll, int _pitch, int _yaw)
{
  int data[4];
  radio.stopListening(); // First, stop listening so we can talk.
  data[0] = _throttle;
  data[1] = _roll;
  data[2] = _pitch;
  data[3] = _yaw;

  if (!radio.write(&data, sizeof(data)))
  {
    Serial.println(F("failed"));
  }
  for (int i = 0; i <4; i++)
  {

    Serial.print("Sent: ");
    Serial.println(data[i]);
  }
  radio.startListening(); // Now, continue listening
}
