#include "Arduino.h"
#include "Sensor.h"

Sensor::Sensor(int x,int y, int z){    
      TriggerPin = x;
      EchoPin    = y;
      maxDistance = z;

}
bool Sensor::IsObjectdistanceClose(){
         pinMode(TriggerPin, OUTPUT);
         pinMode(EchoPin, INPUT);
        // Serial.print("EchoPin: ");
        // Serial.print(EchoPin);
        // Serial.print("\n");
         digitalWrite(TriggerPin, LOW);
         delayMicroseconds(5);
         digitalWrite(TriggerPin, HIGH);
         delayMicroseconds(10);
         digitalWrite(TriggerPin, LOW);  
         // Read the signal from the sensor: a HIGH pulse whose
         // duration is the time (in microseconds) from the sending
         // of the ping to the reception of its echo off of an object.
         pinMode(EchoPin, INPUT);
         DurationSensing = pulseIn(EchoPin, HIGH);  
         distanceSensed = (DurationSensing/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
         Serial.print("distanceSensed: ");
         Serial.print(distanceSensed);
         Serial.print("\n");
         if(distanceSensed < maxDistance){
            return true;
         }
         return false;   
}
int  Sensor::getdistanceSensed(){
     return distanceSensed;
}
