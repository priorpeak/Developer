#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctype.h>
#include "myLib.h"

using namespace std;
const int ENTRIES = 10; // don't computer more than ENTRIES time
const char* inputFileName =  "myInput.txt";
const char* outputFileName = "myOutput.txt";
int counter = 0; // for comparing against ENTRIES
char choice;
double first, last, delta; // passed into askValidateInput() to validate user input


int main()
{
	initialize(); // print Header
	
	do 
	{
	
		// Ask the user for what calculation to make and verify the users choice	
		while (!checkCode(selectProgram())) cout << endl << "Your input is not a valid code. Please try again." << endl << endl;
	
		switch (choice) // Once the input code is validated, select the case corresponding to the users calculation code choice
		{
			case 's':
				if (askValidateInput()) // in each case, the user is prompted by askValidateInput() for parameters and they are validated
				{
					for (double i=first; ( i <= last && counter <= ENTRIES); i = i+delta)
					{	
						cout << "sin(" << i << ") = " << sin(i) << endl;
						counter++;
					}
					counter = 0;
				}
				break;
				
			case 'c':
				if (askValidateInput())
				{
					for (double i=first; ( i <= last && counter <= ENTRIES); i = i+delta)
					{	
						cout << "cos(" << i << ") = " << cos(i) << endl;
						counter++;
					}
					counter = 0;
				}
				break;
				
			case 'r':
				if (askValidateInput())
				{
					for (double i=first; ( i <= last && counter <= ENTRIES); i = i+delta)
					{	
						cout << "sqrt(" << i << ") = " << sqrt(i) << endl;
						counter++;
					}
					counter = 0;
				}
				break;
				
			case 'e':
				if (askValidateInput())
				{
					for (double i=first; ( i <= last && counter <= ENTRIES); i = i+delta)
					{	
						cout << "exp(" << i << ") = " << exp(i) << endl;
						counter++;
					}
					counter = 0;
				}
				break;
				
			case 'l':
				if (askValidateInput())
				{
					for (double i=first; ( i <= last && counter <= ENTRIES); i = i+delta)
					{	
						cout << "log(" << i << ") = " << log(i) << endl;
						counter++;
					}
					counter = 0;
				}
				break;
				
			case 'n':
				if (askValidateInput())
				{
					for (double i=first; ( i <= last && counter <= ENTRIES); i = i+delta)
					{	
						cout << "findNyanCatValue(" << i << ") = " << findNyanCatValue(i) << endl;
						counter++;
					}
					counter = 0;
				}
				break;		
			case 'i':
				readDataFromFile(inputFileName);
				break;
			case 'o':
				writeDataToFile(outputFileName);
				break;
			case 'q':
				break;
			default:
				cout << "If you can see this, checkCode(char) must have failed! Uh-oh.." << endl; 
		} 
	} while ( choice != 'q'); // this program loops allowing the user to perform multiple calculations until s/he (q)uits
	
	cout << endl << "Thank you for using this application. Goodbye. " << endl;
	return 0;
			
}
	
	
