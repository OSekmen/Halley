
//zoomkat 7-30-10 serial servo test
//type servo position 0 to 180 in serial monitor
// Powering a servo from the arduino usually *DOES NOT WORK*.


#include <Servo.h>
Servo myservo;  // create servo object to control a servo
char buffer[6];
 
void setup() {
  Serial.begin(9600);
  myservo.attach(9);
 }

void loop() {
  int index; 
  while (Serial.available()) {
    index = Serial.readBytesUntil('\n', buffer, 5);  //newline or max of 5 chars
    buffer[index] = '\0';
 
    Serial.println(buffer);  //so you can see the captured String
    int n = atoi(buffer);  //convert readString into a number
    Serial.println(n); //so you can see the integer
    myservo.write(n);
    buffer[0] = '\0';
  }
}
