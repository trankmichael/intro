#include <iostream>
#include "dictionary.h"

using namespace std;

const int INITSIZE = 25;
const int EXPAND = 2;

// a letter on the board
struct BogLett {
    char c;		// the letter
    int row, col; // its location
    bool mark;	// if its been visited
};

// a word on the board
struct BogWord {
    int numLetts;	// number of letters in the word
    BogLett* letts;	// the array of letters
    int lettsCap;	// the capacity of the letters
    int Qcount;
};

// a list of words 
struct BogWordList {
    int numWords;
    BogWord* words;
};

