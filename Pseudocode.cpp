/*
* ***************************************************
* 
* Class: CS-210-T5548 Programming Languages 22EW5
* 3-2 Assignment: Designing Your Code
*
* Name: Adrian Sanchez
* Date: May 24, 2022
* 
*****************************************************
* 
* SOFTWARE PROGRAMS FOR ELECTRIC COFFEE MAKER
* 
* USER SETS TIME PROGRAM
* Program starts when "ON" is pressed twice within 1.5 seconds of each press
* Factory default time appears by default
* If user wants to change CoffeeMakerTime
*	then user presses "ON" button twice within 1.5 seconds of each press
* If user presses "ON" button twice within 1.5 seconds of each press
*	Then user selects their local time into the ElectricCoffeeMaker
*	While the user is inputting CoffeeMakerTime
*		User exits CoffeeMakerTime setup by pressing the "ON" button once
* When user exits by pressing the "ON" button once
* CoffeeMakerTime displays local time set by user
* Program ends and ElectricCoffeeMaker is set to "OFF"
* 
* 
* PRE-SET TIME TO BREW COFFEE PROGRAM
* Program starts by user pressing "PROGRAM" button once
* User inputs pre-set time to begin brewing
* While user selecting a pre-set time to brew
*	User must press "PROGRAM" once more to finish their confirmed selection
* Program will run BREW COFFEE PROGRAM when the user input pre-set time is reached
* Program ends
* 
* 
* DISPLAY TIME WHEN ELECTRIC COFFEE MAKER IS OFF PROGRAM
* Program starts when "OFF" is pressed
* ElectricCoffeeMaker display shows
* While ElectricCoffeeMaker is "OFF"
*	No other function other than the display will work
*	Program ends when ElectricCoffeeMaker is "ON"
* 
* 
* AUTOMATIC WATER SENSOR PROGRAM
* Program starts if BREW COFFEE PROGRAM is running
* Checks water reservoir for water
* If water reservoir has no water
*	StopsBrewingCoffee
*	Displays a "fill water" message to user
*	Program ends and turns ElectricCoffeeMaker "OFF"
* Else
*	Continues running BREW COFFEE PROGRAM until
*		no water is left in the water reservoir
*		OR
*		User presses the "OFF" button
* Programs ends
* 
* 
* HEATING SENSOR PROGRAM
* If ElectricCoffeeMaker is "ON"
*	Program starts
*	Hot plate where coffee is output turns on
*	Program ends when ElectricCoffeeMaker is "OFF"
* 
* 
* BREW COFFEE PROGRAM
* While ElectricCoffeeMaker is not "OFF"
*	If program starts by user pressing "ON" once
*		Program runs AUTOMATIC WATER SENSOR PROGRAM
*		Hot water is funneled through the ElectricCoffeeMaker from the water reservoir
*		Hot water is mixed with coffee grounds
*		HEATING SENSOR PROGRAM starts
*		Coffee exits the ElectricCoffeeMaker into a cup
*		Programs ends when user presses the "OFF" button once
* 
*	else
*		program starts from the PRE-SET TIME TO BREW COFFEE PROGRAM
*		While ElectricCoffeeMaker is not "OFF"
*		Program runs AUTOMATIC WATER SENSOR PROGRAM
*		Hot water is funneled through the ElectricCoffeeMaker from the water reservoir
*		Hot water is mixed with coffee grounds
*		HEATING SENSOR PROGRAM starts
*		Coffee exits the ElectricCoffeeMaker into a cup
*		Programs ends when user presses the "OFF" button once
* 
*/