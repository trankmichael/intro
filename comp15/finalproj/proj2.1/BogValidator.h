// File: BogValidator.h 
// Last Date Edited: December 12, 2013
// Purpose: Header for BogValidator.cpp
//			-checks to see if the user input
// 			 words are legal on the boggle board


#include <iostream>
#include "BogSolver.h"

using namespace std;

class BogValidator
{
	public:
		// Default Constructor
		BogValidator();

		// Destructor 
		~BogValidator();

		// reads in the dictionary from the cin
		// stops at the sentinel value of "."
		bool readDict();

		// reads in the whole board of characters
		// if it does not work it will exit(1)
		bool readBoard();	// Note: this also calls the solver
							//       once everything is read in

		// checks if a string is a valid word on the board
		bool isValid( string s );

		// checks the user input words if theyre legal
		// prints out output depending on the results
		void checkWords();

	private:

		// adds to the string of words which must be checked
		void addToCheck( string s);

		// expands the 'check' dynamic array of strings 
		void expandCheck();

		// prints out the results in the given format
		// note: these results are then used by the scorer
		void printResults();

		// Dictionary of valid words
		Dictionary dict;

		// BogSolver class which is a board and its solved
		// words found 
		BogSolver solved;

		// dynamic array of strings which are to be checked
		// by the validator
		string* check;

		// housekeeping
		int checkCap;	// 'check' array capacity
		int count;		// number of strings in the array

};
