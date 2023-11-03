int sample;                        //current value reading of input
int memory;                        //stores previous sample input value for toggle mechanism
int output;                        //main variable which should be toggled, virtual output of logic
unsigned long ref;                 //time stamp for referencing debouncing
unsigned long hb;                  //time stamp for timing heartbeat
const int led = 3;                 //defines the led pin
const int button = 4;              //defines the button pin
unsigned long debounce = 100;      //defines cooldown in ms for toggle 

void setup(){

pinMode(led, OUTPUT);              //maps the led to physical output pin
pinMode(button, INPUT_PULLUP);     //maps the button to physical input pin WITH INTERNAL PULLUP
pinMode(13, OUTPUT);               //declares the inbuild LED of the arduino nano as an output

}

void loop(){

memory = sample;                                                     //updates memory for toggle logic
sample = digitalRead(button);                                        //read the sensor or input data
if(sample == 0 && memory == 1 && millis() - ref >= debounce){        //triggers on falling edge of push button input signal while confirming cooldown
  output = !output;                                                  //toggles the virtual output
  ref = millis();}                                                   //creates timestamp to keep track of upcoming debouncing
if(output == 1 && millis() - ref >= 5000){output = 0;}               //checks for 5s timeout
digitalWrite(led, output);                                           //updates physical output pin in respect to virtual output AND timeout
if(millis() - hb >= 250){
  digitalWrite(13, !digitalRead(13));
  hb = millis();}
}

