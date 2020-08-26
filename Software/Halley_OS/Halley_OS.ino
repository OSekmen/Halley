
//#include <Servo.h>
#include <arduino.h>
#include <RF24.h>
#include <SPI.h>
#include "lib\Halley.h"
#include "lib\Halley.cpp"

#define THROTTLE_PIN 18
#define ROLL_PIN 21
#define PITCH_PIN 20
#define YAW_PIN 19

#define SERVO_1 9
#define SERVO_2 6
#define SERVO_3 5
#define SERVO_4 3

#define CHANNEL_NUMBER 4           //set the number of chanels
#define CHANNEL_DEFAULT_VALUE 1500 //set the default servo value
#define FRAME_LENGTH 15000         //set the PPM frame length in microseconds (1ms = 1000µs)
#define PULSE_LENGTH 100           //set the pulse length
#define onState 1                  //set polarity of the pulses: 1 is positive, 0 is negative
#define sigPin 3                   //set PPM signal output pin on the arduino

Flap Flap1(45, 135, SERVO_1);
Flap Flap2(63, 145, SERVO_2);
Flap Flap3(40, 130, SERVO_3);
Flap Flap4(45, 135, SERVO_4);
RF24 radio(10, 9);

//nRF24 adresses
byte addresses[][6] = {"1Node", "2Node"};
int ppm[CHANNEL_NUMBER];

void setup()
{
  Serial.begin(115200);
  //Controller.begin();
pinMode(sigPin, OUTPUT);
  digitalWrite(sigPin, !onState);
  radio.begin();

  Flap1.begin();
  Flap2.begin();
  Flap3.begin();
  Flap4.begin();

  radio.setPALevel(RF24_PA_LOW);
  radio.openWritingPipe(addresses[0]);
  radio.openReadingPipe(1, addresses[0]);
  radio.startListening();

  cli();
  TCCR1A = 0;
  TCCR1B = 0;

  OCR1A = 100;
  TCCR1B |= (1 << WGM12);  // enable CTC mode
  TCCR1B |= (1 << CS11);   // 8 prescaler: 0.5 microseconds pet tick at 16mhz
  TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt
  sei();
}

void loop()
{
  int throttle;
  int data[4];
  //Flap1.drive(Controller.getYaw(), 0, Controller.maxYaw);
  //Flap2.drive(Controller.getPitch(), 0, Controller.maxPitch);
  //Flap3.drive(-Controller.getYaw()+Controller.maxYaw, 0, Controller.maxYaw);
  //Flap4.drive(-Controller.getPitch()+Controller.maxPitch, 0, Controller.maxPitch);
  

    if (radio.available())
  {
    // Variable for the received timestamp
    while (radio.available())
    {                                  // While there is data ready
      radio.read(&data, sizeof(data)); // Get the payload
    }
  }

  Serial.println("Sent: ");
  for (int i = 0; i < 4; i++)
  {

    int temp = map(data[i],0,730,1000,2000);
    Serial.println(temp);

    ppm[i]=temp;
  }
  
}

ISR(TIMER1_COMPA_vect)
{ //leave this alone
  static boolean state = true;

  TCNT1 = 0;

  if (state)
  { //start pulse
    digitalWrite(sigPin, onState);
    OCR1A = PULSE_LENGTH * 2;
    state = false;
  }
  else
  { //end pulse and calculate when to start the next pulse
    static byte cur_chan_numb;
    static unsigned int calc_rest;

    digitalWrite(sigPin, !onState);
    state = true;

    if (cur_chan_numb >= CHANNEL_NUMBER)
    {
      cur_chan_numb = 0;
      calc_rest = calc_rest + PULSE_LENGTH; //
      OCR1A = (FRAME_LENGTH - calc_rest) * 2;
      calc_rest = 0;
    }
    else
    {
      OCR1A = (ppm[cur_chan_numb] - PULSE_LENGTH) * 2;
      calc_rest = calc_rest + ppm[cur_chan_numb];
      cur_chan_numb++; 
    }
  }
}
