// File: BogSolver.h 
// Last Date Edited: December 12, 2013
// Purpose: Header for BogSolver.cpp
//			-finds all valid words on the bog Board



#include <iostream>
#include "BogWordList.h"
#include "dictionary.h"

using namespace std;

class BogSolver
{
    public:
    	// Default Constructor
    	BogSolver();
    	// Destructor
    	~BogSolver();

		int numWords(); // returns number of words found
		int numWords(int len); // number of words of length len
		BogWordList* getWords(); // returns all words found
		BogWordList* getWords(int len); // returns words of len len
		void printWords(); // print all words in HBF
		void printWords(int len); // print len-length words in HBF
		void listWords(); // print just the text, no coords
		void listWords(int len); // just the text, no coords
		bool readDict(); // reads in the user dictionary
		bool addToDict( string s ); // adds the dict member
		bool readBoard(); // reads the user board
		bool isWord( string y ); // checks if a string is on the board


		bool solve();
	
    private:
		Dictionary dict; // all the words the user wants to find
		Dictionary noRepeats; // holds the words found already
		void addLetts( char s); // adds letters to the bogBoard
		int qCount( BogWord s);	// function which counts q's in a word
		void solveHelp( int start, BogWord s ); // recursive help solve
		void solveHelp2( int start, BogWord s ); // second recursive help
		void addToFound( BogWord s ); // adds to the found a word
		void initEverything( int width, int height ); // inits the board w/o
		bool valid( int check, int start );	//checks the neighbor // letters
		void expandLetts( BogWord s );	// expands the letters ( SEG FAULT)
		string toString( BogWord s );	// converts the word to a string
		void initFound(); // initializes the space for found words
		void expandFound();	// expands the BogWordList
		void unmarkAll();	// unmarks all the spots on the board
		void initLetters(); // sets the letters and coordinates from user in

		//string temp;

		BogLett** letters; 

		// a found list of words
		BogWordList found;
		// capacity of the found list
		//int foundCount;
		int foundCap;

		// total letters on the board
		int numBoardLetts;

		int currentLett;
		// number of columns on the board
		int x;

		// number of rows on the board 
		int y;
	
};
