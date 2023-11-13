int sample;                        //current value reading of input
int memory;                        //stores previous sample input value for toggle mechanism
int output;                        //main variable which should be toggled, virtual output of logic
unsigned long ref1;                //time stamp for referencing debouncing
unsigned long ref3;                //time stamp for heartbeat
const int led = 3;                 //defines the led pin
const int button = 4;              //defines the button pin
const int inbuilt_led = 13;        //defines the inbuilt led for the arduino nano board
unsigned long debounce = 100;      //defines cooldown in ms for toggle and to avoid false triggering

void setup(){

pinMode(led, OUTPUT);              //maps the led to physical output pin
pinMode(button, INPUT_PULLUP);     //maps the button to physical input pin with internal pullup potential
pinMode(inbuilt_led, OUTPUT);      //maps the inbuild led of the arduino nano as an output (heartbeat function)

}

void loop(){

memory = sample;                                                     //updates memory for toggle logic
sample = digitalRead(button);                                        //read the sensor or input data
if(sample == 0 && memory == 1 && millis() - ref1 >= debounce){       //triggers on falling edge of push button input signal while confirming cooldown
  output = !output;                                                  //toggles the virtual output
  ref1 = millis();}                                                  //creates timestamp to keep track of upcoming debouncing

if(output == 0){analogWrite(led, 100);}
else{analogWrite(led, 255);}                                    //set led output                     

if(millis() - ref3 >= 250){                                          //implements the heartbeat functionality
  digitalWrite(inbuilt_led, !digitalRead(inbuilt_led));
  ref3 = millis();}
  



}

