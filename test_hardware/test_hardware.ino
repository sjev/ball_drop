/*
  Voorbeeld code voor jetnet slinger
 */
 
// aansluitingen
byte led = 9;  // groene led
byte sensor = 12; // optocoupler sensor
byte relay = 2; // actuator
byte onboard_led = 13; // led op arduino zelf

// deze functie wordt altijd uitgevoerd nadat de arduino opgestart is
void setup() {                
  // configureer de pinnen
  pinMode(led, OUTPUT);     
  pinMode(relay, OUTPUT);
  pinMode(sensor, INPUT);
  
 
}
// hoofdprogramma, wordt herhaald
void loop() {
  
  for (int i=0; i<10; i++)
  {
    digitalWrite(led,HIGH);
    delay(50); 
    digitalWrite(led,LOW);
    delay(50);  
  }
  
 
  while (digitalRead(sensor)==1) {} // herhaal terwijl sensor = 1
 

  
  digitalWrite(relay, HIGH);    // laat bal los
  delay(500);               // wacht ingestelde tijd in ms
  digitalWrite(relay, LOW); // stop met actueren
  
}


