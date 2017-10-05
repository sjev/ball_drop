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



//number of pulses to wait until drop
// 13.09 mm/count
#define DROP_AFTER 380 

volatile unsigned int encoderPulses = 0;
unsigned int oldCount = 0;

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
  digitalWrite(onboard_led, digitalRead(encoder));

   // reset counter
   if (digitalRead(sensor))
   {
     resetCount();
   }

   // toggle led if count incremented
   if (oldCount<encoderPulses){
     digitalWrite(led,!digitalRead(led));
     oldCount = encoderPulses;
   }


   //Serial.println(encoderPulses);
   
   if (encoderPulses >= DROP_AFTER){
     digitalWrite(relay, HIGH);
     delay(1000);
     digitalWrite(relay, LOW);
     resetCount();

     digitalWrite(led,HIGH);
     // wait for sensor to reset counts
     while (digitalRead(sensor)==0) {}
   }
   

 
}

void countPulse() {
// interrupt routine 
 encoderPulses++; 
  
}

void resetCount(){
// reset counters, prepare for start
 
     encoderPulses = 0;
     oldCount = 0;
     Serial.println("Resetting count");
     // blink led as confirmation
     digitalWrite(led,LOW);
     for (int i=0; i<2; i++){
        digitalWrite(led,!digitalRead(led));
        delay(100);
     }

}


