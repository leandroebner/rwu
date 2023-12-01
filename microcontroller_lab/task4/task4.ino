#define DECODE_NEC
#include <IRremote.hpp>;
#include <Servo.h>
Servo myservo;

void setup() {
  
IrReceiver.begin(2);
myservo.attach(9);

}

void loop() {

if (IrReceiver.decode()){
  if (IrReceiver.decodedIRData.command == 0x45) {myservo.write(5);}
  if (IrReceiver.decodedIRData.command == 0x46) {myservo.write(175);}
  if (IrReceiver.decodedIRData.command == 0x47) {}
IrReceiver.resume();}

}
