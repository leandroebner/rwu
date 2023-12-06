#define DECODE_NEC        //decode incoming ir-frames with the correct protocol being used by the ir-remote
#include <IRremote.hpp>;  //inlcude library for easy use and implementation of the ir sensor
#include <Servo.h>        //include library to control a servo motor
Servo myservo;            //set up an object called servo to adress the angle-commands later

int calibration;


void setup() {

  Serial.begin(9600);   //establish serial connection for debugging purposes
  pinMode(A0, INPUT);   //define cny70 sensor input
  pinMode(13, OUTPUT);  //define inbuilt led as output for debugging purposes
  IrReceiver.begin(2);  //start the ir-receiver on pin 2 of the arduino nano
  myservo.attach(9);    //control a servo motor attached to pin 9 of the arduino nano
  myservo.write(175);   //go to idle position after initilzing code after boot/reboot

}

void loop() {

  if (IrReceiver.decode()){
    if (IrReceiver.decodedIRData.command == 0x45) { myservo.write(175); }  //if button 1 of the remote is pressed, rotate servo to position 1
    if (IrReceiver.decodedIRData.command == 0x46) { myservo.write(5); }    //if button 2 of the remote is pressed, rotate servo to position 2
    if (IrReceiver.decodedIRData.command == 0x47) { button(); }
    IrReceiver.resume();}

  Serial.println(analogRead(A0));

}

void button() {

for (int pos = 0, diff = 0; diff < 20; pos = pos +1){
delay(10);
myservo.write(pos);
diff = calibration - analogRead(A0);}

}