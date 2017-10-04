/*
  Example code to test hardware
  used with Arduino Nano
 */
 
// connections
#define led 9  
#define sensor 12
#define relay 4
#define encoder 2
#define onboard_led  13

volatile unsigned int encoderPulses = 0;


void setup() {                
  // configuration
  pinMode(led, OUTPUT);     
  pinMode(relay, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(encoder, INPUT);
  Serial.begin(19200); // start seriele poort
  
  attachInterrupt(0,countPulse, RISING); 
  
 
}
// main loop
void loop() {
  
   // set current state to the leds
   digitalWrite(led,digitalRead(sensor));
   digitalWrite(onboard_led, digitalRead(encoder));
   
   if (digitalRead(sensor))
   {
     encoderPulses = 0;
   }
   
   Serial.println(encoderPulses);
   
   delay(1000);
   

 
}

void countPulse() {
// interrupt routine 
 encoderPulses++; 
  
}
