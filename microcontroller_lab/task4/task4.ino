#define DECODE_NEC
#include <IRremote.hpp>;
#include <Arduino.h>




void setup() {

Serial.begin(115200);
IrReceiver.begin(IR_RECEIVE_PIN); 


}

void loop() {

if (IrReceiver.decode()) {IrReceiver.printIRResultShort(&Serial);}
Serial.println();
IrReceiver.resume();

}
