const byte ledPin = 13; // the number of the LED pin
const byte interruptPin = 2; // the number of the pushbutton pin
volatile byte state = LOW;   // variable for reading the pushbutton status

void setup() {
  pinMode(ledPin, OUTPUT);  // initialize the LED pin as an output
  pinMode(interruptPin, INPUT_PULLUP);  // initialize the pushbutton pin as a Pull-Up input
  attachInterrupt(digitalPinToInterrupt(interruptPin), Pin_ISR, CHANGE);  // Attach an interrupt to the ISR vector
}

void loop() {
  digitalWrite(ledPin, state);// Toggle LED 
  int sensorValue = analogRead(A0); // Read the temperature Sensor Value 
  delay(3000);        // pauses for  3 seconds
  Serial.println(sensorValue);
}

void Pin_ISR() {
  state = !state;// Toggle State
  Serial.println("Pressed ");
  Serial.println("LED is \n"+ state);
}
