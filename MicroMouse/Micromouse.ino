#include "Motor.h"
#include "Sensor.h"

void setup()
{
  Serial.begin(9600);
  Serial.print(" starting serial Monitor \n");
   pinMode(13,OUTPUT); // LEDPIN

}

void loop()
{
  static int maxDistance = 5;
  static Motor leftMotor(3,2);
  static Motor rightMotor(11,4);

  static Sensor frontSensor(8,9,maxDistance);
  static Sensor leftSensor(6,7,maxDistance);
  static Sensor rightSensor(5,10,maxDistance);

  bool frontsensevalue  = frontSensor.IsObjectdistanceClose();
  bool leftsensevalue   = leftSensor.IsObjectdistanceClose();
  bool rightsensorvalue = rightSensor.IsObjectdistanceClose();
  Serial.print("\n");

  if(frontSensor.IsObjectdistanceClose())
  {
     /*
     if(rightsensorvalue &&  leftsensevalue){
          // tell micromouse to stop first. We'll chang it to reverse back later 
          Serial.print("sensor Left and right flagged\n");
          leftMotor.set_motor_DIR(LOW);
          rightMotor.set_motor_DIR(LOW);
          leftMotor.set_motor_speed(255);
          rightMotor.set_motor_speed(255);

          digitalWrite(13, HIGH); //LED
          delay(500);
     }
     */
     if(rightsensorvalue)
     {
          Serial.print("sensor right flagged\n");
          leftMotor.set_motor_DIR(LOW);
          rightMotor.set_motor_DIR(HIGH);
          leftMotor.set_motor_speed(255);
          rightMotor.set_motor_speed(255);

          digitalWrite(13, HIGH); //LED
          delay(500);
     }
     else if(leftsensevalue)
     {
          Serial.print("sensor left flagged\n");
          leftMotor.set_motor_DIR(HIGH );
          rightMotor.set_motor_DIR(LOW );
          leftMotor.set_motor_speed(255);
          rightMotor.set_motor_speed(255);

          digitalWrite(13, HIGH); //LED
          delay(500);
     }
     else
     {
          Serial.print("Only sensor front flagged\n");
          leftMotor.set_motor_speed(0);
          rightMotor.set_motor_speed(0);
          leftMotor.set_motor_DIR(LOW);
          rightMotor.set_motor_DIR(LOW);
          digitalWrite(13, HIGH); //LED
          delay(500);
     }
  }
  else{
          leftMotor.set_motor_speed(255);
          rightMotor.set_motor_speed(255);
          leftMotor.set_motor_DIR(HIGH);
          rightMotor.set_motor_DIR(HIGH);;
          digitalWrite(13, LOW);//LED
  }
  
   Serial.print(frontsensevalue);
   Serial.print(leftsensevalue);
   Serial.print(rightsensorvalue);
   Serial.print("\n");
}
   
/*
----------map function------------the above funtion scales the output of adc, which is 10 bit and gives values btw 0 to 1023, in values btw 0 to 255 form analogWrite funtion which only receives  values btw this range
*/
