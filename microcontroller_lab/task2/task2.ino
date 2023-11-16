int sample;                        //current value reading of input
int memory;                        //stores previous sample input value for toggle mechanism
int output;                        //main variable which should be toggled, virtual output of logic
int counter;                       //counter variable for pwm control
unsigned long ref1;                //time stamp for referencing debouncing
unsigned long ref2;                //time stamp for pwm 
unsigned long ref3;                //time stamp for heartbeat
const int led = 3;                 //defines the led pin
const int button = 4;              //defines the button pin
const int inbuilt_led = 13;        //defines the inbuilt led pin for the arduino nano board
const int pwm_input = 7;           //defines the analog input for adc measurements
unsigned long debounce = 100;      //defines cooldown in ms for toggle and to avoid false triggering

void setup(){

pinMode(led, OUTPUT);              //maps the led to physical output pin
pinMode(button, INPUT_PULLUP);     //maps the button to physical input pin with internal pullup potential
pinMode(inbuilt_led, OUTPUT);      //maps the inbuild led of the arduino nano as an output (heartbeat function)
pinMode(pwm_input, INPUT);         //maps the pwm signal at led as input
Serial.begin(9600);                //opens serial connection to computer
counter = 130;

}

void loop(){

memory = sample;                                                     //updates memory for toggle logic
sample = digitalRead(button);                                        //read the sensor or input data
if(sample == 0 && memory == 1 && millis() - ref1 >= debounce){       //triggers on falling edge of push button input signal while confirming cooldown
  output = !output;                                                  //toggles the virtual output
  ref1 = millis();}                                                  //creates timestamp to keep track of upcoming debouncing

if(millis() - ref2 >= 10){                                           //triggers counter if time increment has passed
  if(output == 1 && counter < 255){counter++;}                       //if ramping conditions are met, increase the brightness
  else{counter = 0;}                                                 //reset brightness if necessary
  ref2 = millis();}                                                  //creates timestamp to time couning

analogWrite(led, counter);                                           //set led output with calc pwm value
Serial.println(analogRead(pwm_input), DEC);                          //send analog value of led voltage back to pc                            

if(millis() - ref3 >= 250){                                          //implements the heartbeat functionality
  digitalWrite(inbuilt_led, !digitalRead(inbuilt_led));
  ref3 = millis();}
  
  
}

