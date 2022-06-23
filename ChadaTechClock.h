#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Clock //creates class Clock
{
	public: //members accessible from the user outside of the class
		int hr12, hr24, min12, min24, sec12, sec24; // integers for 2 clocks
		string AMPM; // AM vs PM for 12hr clock

	Clock() //Clock functions initialized with starting times of 12AM & 00
	{
		this->AMPM = " A M "; //starting hour is 12 AM
		this->hr12 = 12;
		this->hr24 = 00; //starting hour is 00
		this->min12 = 00;
		this->min24 = 00;
		this->sec12 = 00;
		this->sec24 = 00;
	}

	void correctClock(int t = 12) //corrects clock to make sense
	{
		if (t == 12)
		{
			if ((sec12 / 60) > 0) // checks if sec12 is >= 60
			{
				sec12 %= 60; // assigns left over to sec12
				++min12; // increments min12
			}
			if ((min12 / 60) > 0) // checks if min12 is >= 60
			{
				min12 %= 60; // assigns left over to min12
				++hr12; // increments hr12
			}
			if ((hr12 / 12) > 0) // checks if hr12 is >= 12
			{
				hr12 %= 12; // assigns left over to hr12
				if (hr12 == 0) // if h12 % 12 = 0
				{
					hr12 = 12; // assigns h12 = 12 to keep 12 hour format
					AMPM = " P M "; //changes AM to PM
				}
			}
		}
		if (t == 24)
		{
			if ((sec24 / 60) > 0) // checks if sec24 is >= 60
			{
				sec24 %= 60; // assigns left over to sec24
				++min24; // increments min24
			}
			if ((min24 / 60) > 0) // checks if min24 is >= 60
			{
				min24 %= 60; // assigns left over to min24
				++hr24; // increments hr24
			}
			if ((hr24 / 24) > 0) // checks if hr24 is >= 12
			{
				hr24 %= 12; // assigns left over to hr24
			}
		}
	}

	//function to wait 1 second
	void waitOneSecond()
	{
		//adds a second to the time on both clocks because we waited a second!
		//then checks to see if the clocks need to be corrected.
		++sec12;
		++sec24;
		correctClock(12);
		correctClock(24);
	}
	
	//function to add 1 second
	void addOneSecond()
	{
		//adds a second to the time on both clocks.
		//then checks to see if the clocks need to be corrected.
		++sec12;
		++sec24;
		correctClock(12);
		correctClock(24);
	}

	//function to add 1 minute
	void addOneMinute()
	{
		//adds a minute to the time on both clocks.
		// then checks to see if the clock need to be corrected.
		++min12;
		++min24;
		correctClock(12);
		correctClock(24);
	}

	//function to add 1 hour
	void addOneHour()
	{
		//adds an hour to the time on both clocks.
		//then checks to see if the clock needs to be corrected.
		++hr12;
		++hr24;
		correctClock(12);
		correctClock(24);
	}

	//function for the output of userMenu
	void userMenu()
	{
		cout << "**************************" << endl;
		cout << "* 1 - Add One Hour       *" << endl;
		cout << "* 2 - Add One Minute     *" << endl;
		cout << "* 3 - Add One Second     *" << endl;
		cout << "* 4 - Exit Program       *" << endl;
		cout << "**************************" << endl;
	}

	//function to output 12&24 hr clocks
	//the setw(2) sets the width to 2 for the hr, min, and sec integers
	//the setfill('0') fills the empty space (if there is any) with 0's
	void displayClockTimes()
	{
		cout << "***************************      ***************************" << endl;
		cout << "*      12-Hour Clock      *      *      24-Hour Clock      *" << endl;
		cout << "*      " << setw(2) << setfill('0') << hr12 << ":";
		cout << setw(2) << setfill('0') << min12 << ":";
		cout << setw(2) << setfill('0') << sec12 << AMPM;
		cout << "      *      *        " << setw(2) << setfill('0') << hr24 << ":";
		cout << setw(2) << setfill('0') << min24 << ":";
		cout << setw(2) << setfill('0') << sec24 << "         *" << endl;
		cout << "***************************      ***************************" << endl;
	}
};