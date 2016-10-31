/*  myoware_serial.ino
*   Sketch by George Marzloff
*   george@marzloffmedia.com
*/

int onboardLED = 13;            // Arduino onboard LED (pin 13) you can control
int voltageThreshold = 400;     // any reading higher will trigger an action

void setup() {
  // put your setup code here, to run when Arduino is powered on:
  Serial.begin(9600);
  pinMode(onboardLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int currentVoltage = analogRead(A0);  // store the incoming voltage 
  Serial.print(currentVoltage);         // prints voltage to monitor
  
  if(currentVoltage > voltageThreshold){
     // trigger actions
     Serial.println(" CONTRACTION!"); // prints string + new line
     digitalWrite(onboardLED, HIGH);  //this sends 5V, turning on LED
  } else {
      Serial.println("");             //adds a new line
     digitalWrite(onboardLED, LOW); 
     // turn off the light as threshold is not met
  }
}
