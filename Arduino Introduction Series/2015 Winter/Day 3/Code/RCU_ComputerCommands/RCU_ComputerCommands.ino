/*
Serial Communication with a Computer
March 2015
Nick McComb 
[mccombn@onid.oregonstate.edu]

Description:
This program turns on the on-board LED when the Arduino receives a 'y' over serial, and turns the LED off when it receives a 'n'.

Pseudocode:

-Check if there is an incoming data from the computer
  -If there is,
    -Check if the byte is a 'y'
	  -If it is,
	    -Turn the LED On
		-Output a message to the screen
	  -Else, do nothing
	-Check if the byte is a 'n'
	  -If it is, 
	    -Turn the LED On
		-Output a message to the screen
  -Else, do nothing
  
*/

const int ledPin = 13;  //Sets the pin that the LED is using
char incomingByte;      //Character to hold the incoming byte

void setup(){
  Serial.begin(9600);          //Initializes the Serial object at 9600 baud
  pinMode(ledPin, OUTPUT);     //Sets the LED pin as an output
  digitalWrite(ledPin, LOW);   //Initializes the LED as off
}


void loop(){
  if (Serial.available()) {  //If we need to check anything
	incomingByte = Serial.read();  //Store the incoming byte in a variable
	if ( incomingByte == 'y' ) {   //Check if command to turn on
	  digitalWrite(ledPin, HIGH);  //Turn LED on
	  Serial.println("Turned LED on.");
	}
	else if (incomingByte == 'n'){ //Check if command to turn off led
	  digitalWrite(ledPin, LOW);   //Turn LED off
	  Serial.println("Turned LED off.");
	}
	else {
		//Do nothing
	}
  }
}