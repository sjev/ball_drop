/*
  Voorbeeld code voor jetnet slinger
 */
 
// aansluitingen
byte led = 9;  // groene led
byte sensor = 12; // optocoupler sensor
byte relay = 4; // actuator
byte encoder = 2;
byte onboard_led = 13; // led op arduino zelf
volatile unsigned int encoderPulses = 0;


// deze functie wordt altijd uitgevoerd nadat de arduino opgestart is
void setup() {                
  // configureer de pinnen
  pinMode(led, OUTPUT);     
  pinMode(relay, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(encoder, INPUT);
  Serial.begin(19200); // start seriele poort
  
  attachInterrupt(0,countPulse, RISING); 
  
 
}
// hoofdprogramma, wordt herhaald
void loop() {
  
   // set current state to the leds
   digitalWrite(led,digitalRead(sensor));
   digitalWrite(onboard_led, digitalRead(encoder));
   
   Serial.println(encoderPulses);
   
   delay(1000);
   

 
}

void countPulse() {
 
 encoderPulses++; 
  
}
