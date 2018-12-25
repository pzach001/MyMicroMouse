#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int PWM, int DIR){
    pinMode(PWM, OUTPUT);
    pinMode(DIR, OUTPUT);
    digitalWrite(PWM, LOW);
    digitalWrite(DIR, LOW);
    MotorPWMPin = PWM;
    MotorDIRPin = DIR;  
    Motorspeed  =  0; 
    MotorDIR    =  0;
}
void Motor::set_motor_speed(int speedVal){
     analogWrite(MotorPWMPin,speedVal);
     Motorspeed = speedVal;
}
void Motor::set_motor_DIR(int DIRval){
     analogWrite(MotorDIRPin,DIRval);
     MotorDIR  = DIRval;
}
