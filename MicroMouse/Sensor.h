/*
     Motor.h - Library used to manage the Motion Sensors used in project.
 */

#ifndef Sensor_h
#define Sensor_h
#include "Arduino.h"
class Sensor{
   
    public:
         bool IsObjectdistanceClose();
         int  getdistanceSensed();
         Sensor::Sensor(int x,int y, int z);
    private:
      int TriggerPin;
      int EchoPin;
      long DurationSensing;
      long distanceSensed;
      int maxDistance;

       
};


#endif
