int dir;
int pwm;
int state;
const int led = 3;
const int button = 2;
const int inbuilt_led = 13;
unsigned long ref;
unsigned long ref2;
unsigned long ref3;

void setup() {

pinMode(led, OUTPUT);
pinMode(inbuilt_led, OUTPUT);
pinMode(button, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(button), isr, FALLING);

}

void loop() {

analogWrite(led, pwm);

if(state == 1 && dir == 0 && millis() - ref >= 5){
  pwm++;
  ref = millis();}

if(state  == 1 && dir == 1 && millis() - ref >= 5){
  pwm--;
  ref = millis();}

if(pwm == 0){dir = 0;}
if(pwm == 255){dir = 1;}


if(millis() - ref2 >= 250){                                          //implements the heartbeat functionality
  digitalWrite(inbuilt_led, !digitalRead(inbuilt_led));
  ref2 = millis();}

}

void isr() {

if(millis() - ref3 > 150){state = !state;}

}