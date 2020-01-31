#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctype.h>
#include "myLib.h"
#include <fstream>

using namespace std;

void initialize() // outputs the header when called
{
	cout << "EC327: Introduction to Software Engineering\n" <<
			"Fall 2013\n" <<
			"Programming Assignment 2\n" <<
			"Maximum computation is: " << ENTRIES << endl << endl;
}

bool checkCode(char choice) // returns true is command choice is a valid option, false if not 
{
	if (choice=='s' || choice == 'c' || choice == 'r' || choice =='e' || choice == 'l' || choice == 'n' || choice == 'i' || choice == 'o' || choice =='q') return true;
	else return false;
}
	
void readDataFromFile(const char * fileName) // reads Data from a file using fstream library
{
	ifstream input;
	input.open(fileName);
 	input >> first >> last >> delta;
 	for (double i=first; ( i <= last ); i = i+delta) // performs NyanCatValue function on data from file
	{	
		cout << "findNyanCatValue(" << i << ") = " << findNyanCatValue(i) << endl;
	}
}	

void writeDataToFile(const char * fileName) // writes random data to file (meets parameters given)
{
	first = rand()%11; // generate random # between 1 and 10
	last = 20 + (rand()%11); // generate random # between 20 and 30
	delta = 5 + (rand()%6); // generates a random # between 5 and 10
	
	ofstream output;
	output.open(fileName);
	
	//Write the lines below into the file instad of console
	
	for (double i=first; ( i <= last ); i = i+delta)
	{	
		output << "findNyanCatValue(" << i << ") = " << findNyanCatValue(i) << endl;
	}
	
	output.close();
	cout << "File has been written.\n" << endl;
}

double findNyanCatValue(double num) // perform NyanCatValue calculation and return value
{
	return pow((2 * num),num);
}
	
	
	
	
bool askValidateInput() // returns true if first, last, delta parameters are valid
{
	cout << "Please enter command parameters (first, last, delta): ";
	cin >> first >> last >> delta;
	if (first > last || delta <= 0) 
	{
		cout << "No computation needed." << endl;
		return false;
	}
	else	return true;
}


// when called, the user is prompted for a calculation choice. 
//this functions is called within checkCode so the input can be checked immediately
char selectProgram() 
{
	do 
	{
	cout << "\n\nWelcome to your personal calculator.\n"
		<< "Select an option:\n" 
		<< "s: Compute sine values\n" 
		<< "c: Compute cosine values\n"
		<< "r: Compute square roots\n"  
		<< "e: Compute exponentials\n" 
		<< "l: compute natural logs\n" 
		<< "n: compute NyanCat value\n" 
		<< "i: read from an input file\n" 
		<< "o: write to an output file\n" 
		<< "q: Terminate program\n\n" 
		<< "Enter selection:  ";
	cin >> choice;
	} while(!isalpha(choice)); // make sure the user input is a character
	
	choice = tolower(choice); 
	cout << endl;
	return choice;
}
