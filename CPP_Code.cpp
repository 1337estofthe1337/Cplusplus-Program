#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream> //including for ofstream and ifstream
#include <iomanip> //for setting up histogram


using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

/*
Description:
	This function displays a menu to the user and prompts the user for input
Example:
	menu();
Return:
	1. Produce a list of items purchased in a given day along with the number of times each item was purchased.
	2. Produce a number representing how many times a specific item was purchased in a given day.
	3. Produce a text-based histogram listing all items purchased in a given day, along with a representation of the number of times each item was purchased.
	4. Exits program

Notes:
	All other inputs are invalid and will bring the menu back up with a message telling the user to enter a valid input
*/
void menu()
{
	int menuSelect; //variable for users menu selection
	int itemCount; //need variable for printing in C++ (project guidelines)
	int sameItem = 0; //will iterate when same item is found
	string userItem;
	string itemName;
	ifstream inputFromFile;

	cout << "1. Produce a list of items purchased in a given day along with the number of times each item was purchased.\n";
	cout << "2. Produce a number representing how many times a specific item was purchased in a given day.\n";
	cout << "3. Produce a text-based histogram listing all items purchased in a given day, along with a representation of the number of times each item was purchased.\n";
	cout << "4. Exit program\n";

	cin >> menuSelect;
	switch (menuSelect)
	{
		//case that prints the groceryList of all items & number of times an item was purchased in a given day
		case 1:
		{
			CallProcedure("AllGroceryItems"); //calls the python function
			cout << endl;

			//loop back to menu
			menu();
			break;
		}
		//case that determines frequency of a specific item
		case 2:
		{
			cout << "Input the item you would like to look for: ";
			cin >> userItem;

			//passing userItem to Python for counting
			itemCount = callIntFunc("CountGroceryItem", userItem);
			cout << endl << userItem << ": " << itemCount << endl;

			//loop back to menu
			menu();
			break;
		}
		//case that prints the histogram
		case 3:
		{
			CallProcedure("text4Histogram"); //getting text for histogram

			//opens frequency.dat file
			inputFromFile.open("frequency.dat");
			inputFromFile >> itemName; //gets 1st item
			inputFromFile >> itemCount; //gets 1st items quantity

			//loops to print every line, but histogramofied
			while (!inputFromFile.fail()) //exits loop when fail
			{
				//formatting printed item name
				cout << setw(12) << left << itemName;

				//printing * for as many itemCount for that item
				for (int i = 0; i < itemCount; ++i)
				{
					cout << "*";
				}

				cout << endl;

				//gets next line input from frequency.dat
				inputFromFile >> itemName;
				inputFromFile >> itemCount;
			}

			//closes file
			inputFromFile.close();
			cout << endl;

			//loop back to menu
			menu();
			break;
		}

		case 4:
		{
			cout << "Goodbye";
			break;
		}

		default:
		{
			cout << "That was an invalid input.\nPlease input 1, 2, 3, or 4.\n";

			//loop back to menu
			menu();
			break;
		}
	}


}


int main()
{
	menu();

	return 0;
}