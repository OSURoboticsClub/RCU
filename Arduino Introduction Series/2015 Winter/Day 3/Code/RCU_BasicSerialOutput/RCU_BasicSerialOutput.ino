/*
Basic Serial Communication
March 2015
Nick McComb 
[mccombn@onid.oregonstate.edu]

Description:
This program outputs it's current iteration to a Serial terminal

Pseudocode:

-Iterate I from 0 to 20
  -Run function doSomething()
  -Output the current iteration to the terminal
  -Wait a second
-Infinite loop

*/

//Sets up the serial object with a 9600 Baud Rate
void setup() {
  Serial.begin(9600);
}

//Main Program, see Pseudocode
void loop() {
  //Loop from 0 to 20
  for (int i = 0; i <= 20; ++i){
	doSomething();  //Placeholder function
	Serial.print("Current Iter: "); //Output string to terminal
	Serial.println(i);              //Output the iteration to the terminal
	delay(1000);                    //Wait for 1 second
  }
  
  while(1);    //We're done, infinite loop
}

//Placeholder, empty function
void doSomething(){
	
}