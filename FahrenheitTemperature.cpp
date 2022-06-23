#include <iostream> //standard input/output
#include <fstream> //file stream for use of ifstream/ofstream class
#include <string> //iostream includes string, but apparently it's good practice to include it otherwise due to possible compiler issues?
#include <cmath> //including cmath for the round() function for proper integer values through proper rounding

using namespace std; //standard namespace

int main()
{
	ifstream inTxtFile; //uses ifstream to read data from a data file
	string fileCityName;
	int fileCityTemp_F, fileCityTemp_C;

	//Part 1: Develop code to read data from a text file
	//opening the provided file so it is ready to be read
	inTxtFile.open("FahrenheitTemperature.txt");
	if (!inTxtFile.is_open()) //logic = if CANNOT open, file doesn't exist or is in use by another program.
	{
		cout << "Could not open file: FahrenheitTemperature.txt" << endl;
		return 1; // 1 indicates error and terminates program
	}

	//Part 2: Develop code to write data to a text file
	ofstream outTxtFile; //declaring variable using ofstream to write to CelsiusTemperature.txt; creates file if non-existing
	outTxtFile.open("CelsiusTemperature.txt");

	//Reading file FahrenheitTemperature.txt and putting values in CityName and fileCityTemp_(C&F)
	//also converts values of fileCityTemp_F to fileCityTemp_C
	while (inTxtFile >> fileCityName >> fileCityTemp_F) //loops through Fahrenheit file until end of file
	{
		fileCityTemp_C = round((fileCityTemp_F - 32) * (double)5 / 9); //converts F to C and rounds to closest integer value
		outTxtFile << fileCityName << " " << fileCityTemp_C << endl; //building CelsiusTemperature.txt file
	}

	//closing files so it can be used again if needed
	inTxtFile.close();
	outTxtFile.close();
	
	return 0; //return 0 to main()
}