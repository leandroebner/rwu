int mem ;
int toggle ;
int output ;
unsigned long reference ;
const int led = 3 ;
const int button = 4 ;
unsigned long timer = 5000 ;
unsigned long debounce = 100 ;

void setup() {

pinMode(led, OUTPUT) ;
pinMode(button, INPUT_PULLUP) ;
digitalWrite(led, LOW) ;
mem = digitalRead(button) ;
toggle = !mem ;

}

void loop() {

// if(millis() - reference >= timer){digitalWrite(led, LOW) ;} 


