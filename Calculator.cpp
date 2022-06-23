/*
 * Calculator.cpp
 *
 *  Date: [20 May 2022]
 *  Author: [Adrian Sanchez]
 */

// First thing I'm going to do is Build the Solution to see what errors come up.
// There was a lot of errors.
#include <iostream>

using namespace std;

int main() // main should be int not void
{
	char statement[100];
	int op1, op2;
	char operation;
	char answer = 'y'; // was missing semi-colon and realized Y needs to be lowercase for the while loop. Also, char is single quote, string is double... changed double to single.
	while (answer == 'y')
	{
		cout << "Enter expression" << endl;
		cin >> op2 >> operation >> op1;
		if (operation == '+')
		{ // got rid of ; and added brackets for readability and changed double quotes to single quotes for char operation
			cout << op1 << " + " << op2 << " = " << op1 + op2 << endl; // changed >> to <<
		}
		else if (operation == '-')
		{ // got rid of ; and added brackets for readability
			cout << op1 << " - " << op2 << " = " << op1 - op2 << endl; // cout was using cin arrows, changed >> to <<
		}
		
		else if (operation == '*')
		{ // added brackets for readability
			cout << op1 << " / " << op2 << " = " << op1 * op2 << endl; // missing semicolon
		}
		else if (operation == '/')
		{
			cout << op1 << " * " << op2 << " = " << op1 / op2 << endl;
		}
		// no need for an else statement? Maybe an else statement that catches miss-inputs?

			cout << "Do you wish to evaluate another expression? " << endl;
			cin >> answer;
	}
	return 0; // not sure if this matters, but I added a return for int main()
}


// no more error messages! Whoop!



