/*
Basic Servo Control using a Potentiometer-based joystick
March 2015
Nick McComb 
[mccombn@onid.oregonstate.edu]

Description:
This program uses a basic potentiometer based joystick to move a servomotor. The joystick used was https://www.sparkfun.com/products/9032 .

The pot is attached to 5V, A0, Gnd (in that order)
The servo is attached to 5V, Gnd, Pin 9


Pseudocode:

-Store Analog Value
-Divide to get it into the range for the servo (0-170)
-Add offset to get it into final range (5-175)
-Write value to servo
-Rinse and repeat

*/
#include <Servo.h>

Servo myServo;   //Create servo object

void setup(){
  Serial.begin(9600);   //Begin Serial Communication
  
  myServo.attach(9);    //Attach the servo to Pin 9
  
  Serial.println("[Board Init]");  //Send init str
}


void loop(){
  short analogValue = analogRead(A0);  //Read in the analog value, store it in a variable
  short servoValue = analogValue / 6;  //Divide the value by 6 (1024/170) to get our value
                                       //into the range that we want it to be (0-170)
  servoValue = servoValue + 5;         //Add an offset of 5 to put it in the final range (5-175)
  Serial.print("Servo Value: ");       //Nice message
  Serial.println(servoValue);          
  
  myServo.write(servoValue);           //Write the value to the Servo
  
  delay(100);                          //Check the pot (& output to screen) @ 10Hz
}