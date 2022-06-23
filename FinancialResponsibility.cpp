#include <iostream> //standard input/output
#include <iomanip> //for manipulating output

using namespace std; //standard namespace

//didn't want to use pointers/classes because this was a simple program
//only would have convoluted the program

int main()
{
	//initial investment, monthly deposit, annual interest, total investment, sum of interest
	double initialInvest, monthlyDeposit, annualInterest, annIntPercent, yearsInterest, totalInterest, totalInvest;

	//months for monthly deposit and years for user input
	int months, years;
	

	//Display to show what the user should input
	cout << "**********************************" << endl;
	cout << "*********** Data Input ***********" << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;

	//Waits for user to press any key
	system("pause");

	//Displays header and gets user input below
	cout << endl << "**********************************" << endl;
	cout << "*********** Data Input ***********" << endl;
	cout << "Initial Investment Amount: $";
	cin >> initialInvest;
	cout << "Monthly Deposit: $";
	cin >> monthlyDeposit;
	cout << "Annual Interest: %";
	cin >> annIntPercent;
	annualInterest = annIntPercent / 100; //gets a decimal value of percentage for calculations
	cout << "Number of years: ";
	cin >> years;
	months = years * 12; //12 months in a year

	//Waits for user to press any key
	system("pause");

	//update totalInvest with initialInvest amount
	totalInvest = initialInvest;

	//Display static report 1
	cout << endl << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "============================================================" << endl; //60 = signs
	//using setw(20) for 3 instances for 60 spaces total while hugging left to align columns
	cout << setw(20) << left << "Year" << setw(20) << left << "Year End Balance" <<setw(20) << left << "Year End Earned Interest" << endl;
	cout << "------------------------------------------------------------" << endl; //60 - signs

	//for loop to end at user input years
	for (int i = 0; i < years; ++i)
	{
		//calculation for totalInterest for "Year End Earned Interest" column
		totalInterest = totalInvest * annualInterest;

		//calculation for totalInvestment for "Year End Balance" column
		totalInvest = totalInvest + totalInterest;

		//output results with 2 decimal points; "Year" is output in first column corresponding to for loop
		//using setw(20) to align with columns
		cout << setw(20) << left << i + 1 << "$" << fixed << setprecision(2) << setw(20) << left << totalInvest << "$" << setw(20) << left << totalInterest << endl;
	}
	
	//reset totalInvest
	totalInvest = initialInvest;

	//Display static report 2
	cout << endl << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "============================================================" << endl;
	//using setw(20) for 3 instances for 60 spaces total while hugging left to align columns
	cout << setw(20) << left << "Year" << setw(20) << left << "Year End Balance" << setw(20) << left << "Year End Earned Interest" << endl;
	cout << "------------------------------------------------------------" << endl;

	//for loop to end at user input years
	for (int i = 0; i < years; ++i)
	{
		//setting yearsInterest to 0 for the start of every year
		yearsInterest = 0;

		//for loop to calculate the 12 monthly deposits per year
		for (int j = 0; j < 12; ++j) //j < 12 because there are 12 months in a year
		{
			//calculation for totalInterest for yearsInterest
			totalInterest = (totalInvest + monthlyDeposit) * (annualInterest / 12); //divide by 12 to get overall interest accumulated through 12 monthly iterations/year

			//calculation for totalInvestment for "Year End Balance" column
			totalInvest = totalInvest + monthlyDeposit + totalInterest;

			//calculation for yearsInterest for "Year End Earned Interest" column
			yearsInterest = yearsInterest + totalInterest; //calculates the current years earned interest
		}

		//output results with 2 decimal points; "Year" is output in first column corresponding to for loop
		//using setw(20) to align with columns
		cout << setw(20) << left << i + 1 << "$" << fixed << setprecision(2) << setw(20) << left << totalInvest << "$" << setw(20) << left << yearsInterest << endl;
	}

	return 0;
}