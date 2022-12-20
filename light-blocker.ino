#include <Servo.h>

Servo ser;
//Constants
const int pResistor = A0; // Photoresistor at Arduino analog pin A0
const int ledPin=9;       // Led pin at Arduino pin 9
int serPin = 13;
int serPos = 0; 

void setup() {
  Serial.begin(9600);
  pinMode(pResistor, INPUT);
  ser.attach(serPin);
  ser.write(serPos); 
}

void loop(){
    int value = analogRead(pResistor);
    Serial.println("Analog value : ");
    Serial.println(value);
    ser.write(serPos);
    if (value > 457) {
      // low light, so switch the light (LED) on
      serPos = 80; 
    }
    else {
      // light level high enough, so switch the light (LED) off
      serPos = 0;
    }
    // wait for ADC to settle before next reading
    delay(1500); 
}

