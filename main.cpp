/*
* Class: CS-210-T5548 Programming Languages 22EW5
* 3-1 Project: Chada Tech 12/24 Clock
*
* Name: Adrian Sanchez
* Date: May 23, 2022
*/

#include <iostream> // provides basic input/output features
#include "ChadaTechClock.h" // adds the header file I created
#include <stdlib.h> //necessary for the flowchart's clear screen function "system("CLS");"

using namespace  std; // uses the standard namespace so I don't have to type as much

int main()
{
	Clock time; //calls class Clock with object time
	int userInput; //user's input for userMenu();
	bool exit = false; //initializing exit as false for while loop

	while (exit != true) //loop will run as long as exit = false.
	{
		time.userMenu();
		cin >> userInput;
		system("CLS"); //clears the screen

		switch (userInput) //switch to quality check userInput
		{
			//all cases have a break statement to exit after input
			case 1:
				time.addOneHour();
				break;
			case 2:
				time.addOneMinute();
				break;
			case 3:
				time.addOneSecond();
				break;
			case 4:
				exit = true; //exit parameter
				break;
			default: //catches incorrect input.
				cout << "Wrong input. Try again with either 1, 2, 3, or 4." << endl;
				break;
		}

		time.waitOneSecond(); //adds a second to the clock
		time.displayClockTimes(); //displays clock
	}
}