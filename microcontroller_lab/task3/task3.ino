int dir;                      //variable for brightness ramping direction
int pwm;                      //variable for pwm brightness
int state;                    //main virtual toggle variable
int sample;                   //sample input of button
const int led = 5;            //maps led pin
const int button = 2;         //maps button pin
const int inbuilt_led = 13;   //maps inbuilt led pin
unsigned long ref1;           //time stamp for ramping speed
unsigned long ref2;           //time stamp for heartbeat
unsigned long ref3;           //time stamp for debouncing the button

void setup() {

pinMode(led, OUTPUT);                                             //defines led as an output
pinMode(inbuilt_led, OUTPUT);                                     //defines inbuilt led as an output
pinMode(button, INPUT_PULLUP);                                    //defines button as input
attachInterrupt(digitalPinToInterrupt(button), isr, FALLING);      //set up interrupt routine, pin and mode

}

void loop() {

analogWrite(led, pwm);

if(state == 1 && dir == 0 && millis() - ref1 >= 5){               //ramping up the brightness of the led
  pwm++;
  ref1 = millis();}

if(state  == 1 && dir == 1 && millis() - ref1 >= 5){              //ramping down the brightness of the led
  pwm--;
  ref1 = millis();}

if(pwm == 0){dir = 0;}                                            //checks in which direction to cycle through the brightness levels
if(pwm == 255){dir = 1;}                                          //change direction as soon as the led is at its full brightness


if(millis() - ref2 >= 250){                                       //implements the heartbeat functionality
  digitalWrite(inbuilt_led, !digitalRead(inbuilt_led));   
  ref2 = millis();}

}

void isr() {


if(millis() - ref3 > 100){state = !state;}                        //toggle main variable and check for debounce conditions

}