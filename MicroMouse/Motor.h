/*
     Motor.h - Library used to manage the motors used in project.
 */

#ifndef Motor_h
#define Motor_h
#include "Arduino.h"
class Motor{
    public:
       //void set_motor_pins();
       void set_motor_speed(int speedVal);
       void set_motor_DIR(int DIRVal);
       Motor(int PWM, int DIR);
    private:
        int MotorPWMPin;
        int MotorDIRPin;
        int Motorspeed;
        int MotorDIR;
       
};


#endif
