// File: BogValidator.cpp 
// Last Date Edited: December 12, 2013
// Purpose: Implementation for BogValidator.h
//			-checks to see if the user input
// 			 words are legal on the boggle board

#include <iostream>
#include <queue>
#include <cctype>
#include <stack>
#include "BogValidator.h"
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

// Default Constructor 
BogValidator::BogValidator()
{
	check = new string[INITSIZE];	// initializes the dynamic array
	checkCap = INITSIZE;			// sets the current capacity 
	count = 0;			// the current count is zero
}

// Destructor
BogValidator::~BogValidator()
{
	delete[] check; 	// deletes the dynamic array 
}

// Reads in the user inputted dictionary
// - these values are stored in the dictionary in the solver 
// 	 object as well as the validator object 
bool BogValidator::readDict()
{
    string temp;		

    cin >> temp;				  // reads in the first input
    while(temp != ".")			  // catch sentinel value
    {
        dict.insert( temp );	  // adds to the validator's dictionary
        solved.addToDict( temp ); // adds to the solver's dictionary
        cin >> temp;			  // reads in next input
    }

    return true;		// returns true if successful
}

// reads the user inputted board
// - actually calls the read board of the solver
//   to accept the user inputs
// - not there is no physical board stored in the validator
bool BogValidator::readBoard()
{
	solved.readBoard();		// calls read board in solver object
	solved.solve();		    // solves the board 
	return true;			// returns true if successful 
}

// checks if a string is valid
// - passes the string the solved board to check
bool BogValidator::isValid( string s )
{
	return solved.isWord( s );	// if the string is on the solved board
}								// returns true; false if otherwise


// checks all the words by reading in a file of words
// to be validated
//		- adds to the array of strings " check "
//		- loops through calling addToCheck
void BogValidator::checkWords()
{
	string temp; 

	cin >> temp;		// first input
	while( !cin.eof() ) // stops at eof
	{
		addToCheck(temp);	// adds to "check"
		cin >> temp;		// next input
	}

	printResults();	// calls a function to pring 
}

// adds to the array of strings to be checked by the validator
// - calls expand if necessary 
void BogValidator::addToCheck( string s )
{
	check[count] = s;	// sets the current word to the word addded
	count++;			// increments number of words in the array
	if( count >= checkCap - 1 )	// expand condition
	{							
		expandCheck();			// calls the expand function 
	}							// if space is running low
}

// prints all the results in the correct format
// sample output:
//		" OK DOG "
//		" NO PWQ "
void BogValidator::printResults()
{
	for( int i = 0; i < count ; i++ )	// loops through all spaces in 
	{									// the check array
		if( isValid(check[i]))			// calls a function to to see if 
		{								// the word is actually present
			cout << "OK " << check[i] << endl;
		}					// prints the output if it is 
		else{
			cout << "NO " << check[i] << endl;
		}					// prints the output if it isnt 
	}
}

// expands the array of all the strings
// standard expansion of a dynamic array 
void BogValidator::expandCheck()
{
	// creates a temp which points to a new array 
	// larger than the old one by a factor of "EXPAND"
	string* temp = new string[ checkCap* EXPAND ];

	// each string in the original array
	// is copied over to the new temp array 
	for( int i = 0; i < count ; i++)
	{
		temp[i] = check[i];		// copy
	}

	checkCap = checkCap * EXPAND; // update housekeeping variable
	delete[] check;				  // deletes the old array
	check = temp;				  // private member gets new array 
}