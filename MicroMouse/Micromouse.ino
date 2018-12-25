//Analog pins
const int pwmA = 3 ;    //naming pin 2 as ‘pwm’ variable 
const int pwmB = 11;
const int adcVert = 0 ; 
const int adcHoriz = 1 ; //naming pin 0 of analog input side as ‘adc’
//digital pins
//Pins for front sensor
int trigPinFront = 8;    // Trigger
int echoPinFront = 9;    // Echo
//Pins for Left sensor
int trigPinLeft = 2;    // Trigger
int echoPinLeft = 7;    // Echo
//Pins for Right sensor
int trigPinRight = 5;    // Trigger
int echoPinRight = 10;    // Echo
long durationFront, cmFront,inchesFront, durationLeft,cmLeft,inchesLeft, durationRight, cmRight,inchesRight;
// Motor definitions to make life easier:
#define MOTOR_A 0
#define MOTOR_B 1

// Pin Assignments //
//Default pins:
#define DIRA 2 // Direction control for motor A
#define PWMA 3  // PWM control (speed) for motor A
#define DIRB 4 // Direction control for motor B
#define PWMB 11 // PWM control (speed) for motor B
#define LEDPIN 13 // pin for button
////Alternate pins:
//#define DIRA 8 // Direction control for motor A
//#define PWMA 9 // PWM control (speed) for motor A
//#define DIRB 7 // Direction control for motor B
//#define PWMB 10 // PWM control (speed) for motor B


void setupArdumoto()
{
  // All pins should be setup as outputs:
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  

  // Initialize all pins as low:
  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
} 
void setupSensor()
{
  //setting up pins for three sensors
  // 
  pinMode(trigPinFront, OUTPUT);
  pinMode(echoPinFront, INPUT);
  
  pinMode(trigPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);
  
  pinMode(trigPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);  
}
void setupLED()
{
   //pinMode(BUTTONPIN,INPUT);
   pinMode(LEDPIN,OUTPUT);
}
void setup()
{

  //Serial Port begin
  Serial.begin(9600);
  Serial.print("testing serial\n");
  setupArdumoto();
  setupSensor();
  setupLED();
}

void loop()
{
  /*
   int buttonval = 0;
   if(digitalRead(BUTTONPIN) == HIGH){
       if(buttonval == 1)
       {
          buttonval = 0;
       }
       buttonval = 1;       
   }
   if(buttonval == 0){
            digitalWrite(DIRB,LOW);
            digitalWrite(DIRA,LOW);
            analogWrite(pwmB,0);
            analogWrite(pwmA,0);
            Serial.print("Button is off\n");
   }
   else{
 */
 //long durationFront, cmFront, durationLeft,cmLeft, durationRight, cmRight
 //--------------------Front sensor code ------//
          // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
          // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
          digitalWrite(trigPinFront, LOW);
          delayMicroseconds(5);
          digitalWrite(trigPinFront, HIGH);
          delayMicroseconds(10);
         digitalWrite(trigPinFront, LOW);  
         // Read the signal from the sensor: a HIGH pulse whose
         // duration is the time (in microseconds) from the sending
         // of the ping to the reception of its echo off of an object.
         pinMode(echoPinFront, INPUT);
         durationFront = pulseIn(echoPinFront, HIGH);  
         cmFront = (durationFront/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
         Serial.print("This is frontcm: ");
         Serial.print(cmFront);
         Serial.print("\n");
         inchesFront = (durationFront/2) / 74; 
 //--------------------Front sensor code ------// 
 //--------------------Left sensor code ------//
           // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
          // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
          digitalWrite(trigPinLeft, LOW);
          delayMicroseconds(5);
          digitalWrite(trigPinLeft, HIGH);
          delayMicroseconds(10);
         digitalWrite(trigPinLeft, LOW);  
         // Read the signal from the sensor: a HIGH pulse whose
         // duration is the time (in microseconds) from the sending
         // of the ping to the reception of its echo off of an object.
         pinMode(echoPinLeft, INPUT);
         durationLeft = pulseIn(echoPinLeft, HIGH);  
         cmLeft = (durationLeft/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
         Serial.print("This is left cm: ");
         Serial.print(cmLeft);
         Serial.print("\n");
         inchesLeft = (durationLeft/2) / 74; 
 //--------------------Left sensor code ------//
 //--------------------right sensor code ------//    
           // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
          // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
          digitalWrite(trigPinRight, LOW);
          delayMicroseconds(5);
          digitalWrite(trigPinRight, HIGH);
          delayMicroseconds(10);
         digitalWrite(trigPinRight, LOW);  
         // Read the signal from the sensor: a HIGH pulse whose
         // duration is the time (in microseconds) from the sending
         // of the ping to the reception of its echo off of an object.
         pinMode(echoPinRight, INPUT);
         durationRight = pulseIn(echoPinRight, HIGH);  
         cmRight = (durationRight/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
         Serial.print("This is rightcm: ");
         Serial.print(cmRight);
         Serial.print("\n");
         Serial.print("\n");
         Serial.print("---------------\n");
         Serial.print("\n");
         inchesRight = (durationRight/2) / 74;  
 //--------------------right sensor code ------//
  // Convert the time into a distance
         char currtargetDistance =10;
         if(cmFront < currtargetDistance)
         {
                if(cmLeft < currtargetDistance ){
                   Serial.print("sensor Left and Front flagged\n");
                   digitalWrite(DIRA,HIGH);
                   digitalWrite(DIRB,LOW);
                   analogWrite(pwmA,255);
                   analogWrite(pwmB,255);
                   digitalWrite(13, HIGH); //LED
                   delay(500);
                }
                else if(cmRight < currtargetDistance){
                  Serial.print("sensor Rightand Front flagged\n");
                  digitalWrite(DIRB,HIGH);
                  digitalWrite(DIRA,LOW);
                  analogWrite(pwmA,255);
                  analogWrite(pwmB,255);
                  digitalWrite(13, HIGH); //LED
                  delay(500);
                }
                else{
                   Serial.print("sensor front flagged\n");
                   digitalWrite(DIRA,LOW);
                    digitalWrite(DIRB,LOW);
                   analogWrite(pwmA,0);
                   analogWrite(pwmB,0);
                   digitalWrite(13, HIGH); //LED
                   delay(500);
                }

         }
         else{
                digitalWrite(DIRB,LOW);
                digitalWrite(DIRA,LOW);
                analogWrite(pwmB,255);
                analogWrite(pwmA,255);
                digitalWrite(13, LOW);//LED
       }    
 }
   
/*
----------map function------------the above funtion scales the output of adc, which is 10 bit and gives values btw 0 to 1023, in values btw 0 to 255 form analogWrite funtion which only receives  values btw this range
*/
