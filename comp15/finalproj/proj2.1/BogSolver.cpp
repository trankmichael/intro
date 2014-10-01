// File: BogSolver.cpp 
// Last Date Edited: December 12, 2013
// Purpose: Implementation for BogSolver.h
//          -solves the board
//          -finds all legal words on the board

#include <iostream>
#include <queue>
#include <cctype>
#include <stack>
#include <cstdlib>
#include "BogSolver.h"
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

// default constructor 
BogSolver::BogSolver()
{
    letters = NULL;     // does not know how many letters there are yet
    foundCap = 0;       // capacity is zero to start
    numBoardLetts = 0;  // zero letters
    x = 0;
    y = 0;              // board dimensions are zero
}

// destructor
BogSolver::~BogSolver()
{
    for( int i = 0; i < found.numWords; i++ )
    {
        for( int t = 0; t < found.words[i].numLetts; i++)
        {
            delete[] found.words[i].letts;  // deletes the dynamic array of
        }                                   // letts
        delete[] found.words;               // deletes the dynamic array of
                                            // found words 
    }

    delete[] letters;                       // finally deletes al lthe letters
                                            // on the board

}

// reads in the dictionary and stores it in the 
// dict member of the object
//      - calls the dict member function insert to add words to
//        the dictionary
bool BogSolver::readDict()
{
    string temp;        // string inputted

    cin >> temp;        // first input
    while(temp != ".")  // catches sentinel value
    {
        dict.insert( temp );    // inserts the word in the dictionary
        cin >> temp;            // next input
    }

    return true;        // returns true once it is succesful
}

// add to the dictionary
//      - this is called in bogValidator
//      - adds words to the dictionary member 
//        in the solver object
bool BogSolver::addToDict( string s )
{
    dict.insert(s); // insert function takes in a string
    return true;    // true if possible
}

// checks if the string is a word on the board
// the noRepeats dictionary holds all the found words
bool BogSolver::isWord( string s)
{
    if( noRepeats.isWord(s) )
    {
        return true;        // it is in the dictionary
    }  
    else
    { 
        return false;       // it is not in the dictionary
    }
}

// reads the board
// called by main
// initiallized the boggle board simulation
// if there are not enough letters the program exits
bool BogSolver::readBoard()
{
    int numRows, numCols;       // ints for dimensions
    string temp;                // inputted string 

    cin >> numRows;         // height
    cin >> numCols;         // width


    // helper function which initializes each of the letters
    // on the board
    initEverything(  numCols, numRows );

    // loop throughs horizontally then vertically 
    // the strings are read through horizontally 
    for( int i = 0 ; i < numRows; i++ )
    {
        cin >> temp;    // first input
        for( int t = 0; t < numCols; t++ ) // goes the rows
        {
            if( cin.eof() )   // if the end of the file is reached 
            {                 // before the board is filled 
                cerr << "PROGRAM TERMINATED: BOARD NOT FILLED";
                exit(1);
            }
            addLetts(temp[t]); // adds the char from the temp
        }                      // temp string 
    }

    return true;    // true if successful
}

//  INITIALIZES EVERYTHING 
//  runs once the user has inputted the information 
//      calls helpers to initialize each letter
//                  and the found list 
void BogSolver::initEverything( int width, int height )
{
    x = width; 		// housekeeping x 
    y = height;		//		y
    letters = new BogLett*[x*y];// creates an array of 
    numBoardLetts = x*y;   // sets the numwords in the aray to zero
    initLetters();		// of BogLetts
    currentLett = 0;
    initFound();

}

// adds the array of words to the boggle Solver
// takes in an array of strings all of length x
void BogSolver::addLetts( char s )
{
    letters[currentLett]->c = s; // adds the character s to
    currentLett++;               // the first open space in the boglett
    // incremenets the number of letters 
}

// solves the board calls a recursive helper function
bool BogSolver::solve()
{
    BogWord s;      // a bogWord to use

    for( int i = 0; i < numBoardLetts; i++ )
    {
        // unmarksAll the spaces
        unmarkAll();
        s.letts = new BogLett[INITSIZE]; // initilizes the 
	    s.lettsCap = x*y;           // members of the BogWord
    	s.numLetts = 0;
	
    	// calls the recursive helper function
        solveHelp( i, s );      
    	delete [] s.letts;     // deletes the array of letters 
    }

    return true;
}

// Solve Help recursive function
// takes in an index "start" and a BogWord s
// adds to s the letter in start and then checks 
// if it is a prefix then checks if its children 
// prefixes . continues recursion marking visited
void BogSolver::solveHelp( int start, BogWord s)
{
    // if the numLetts exceeds the capacity of the
    // Bogletts array the expand function on s will 
    // called
            //NOTE: FOUND A SEG FAULT IN THIS EXPAND
            //      FUNCTION BUT COULD NOT FIX IT 
    if( s.numLetts >= s.lettsCap  )
    {
        cerr << " EXPANDED " <<endl;
	   expandLetts(s);
    }
    // copy over all the members of the current Boglett 
    // into the next array space in the BogWord 
    s.letts[s.numLetts].c = letters[start]->c;
    s.letts[s.numLetts].row = letters[start]->row;
    s.letts[s.numLetts].col = letters[start]->col;
    letters[start]->mark = true;

    // base case when the string being checked is not a prefix
    // if this happens the recurssion ends
    if( !dict.isPrefix(toString(s) ) )
    {
        letters[start]->mark = false; // resest the start 
        s.numLetts--;   // moves the count back one
        return;
    }
    else{
	    s.numLetts++;      // incremenets the numLetts

	   // if what you found is a word add it to the list
	   if( ( s.numLetts >= 3 ) && dict.isWord( toString(s) ) &&
            ( !noRepeats.isWord( toString(s) )) )
	    {
            noRepeats.insert( toString(s) );    // to prevent
            addToFound( s );                    // repeats
	    }  // adds to the found 
    	

	    solveHelp2( start, s ); // second recursive helper function   
    }

    letters[start]->mark = false; // sets the start marked as false
    s.numLetts--;                 // decrements s.numLetts
}

// the second recursive helper function
// just checks validity of the the neighbors and calls
// the solveHelp on each of its valid neighbors 
void BogSolver::solveHelp2( int start, BogWord s )
{
    int spotChecked;        // check 

    for( int i = -1; i < 2; i++ )
    {
	   for( int t = -1; t < 2; t++ )
	   {
	       spotChecked = start + i + (t* x); // calculate the spots relation
	       if( valid(spotChecked, start) )   // calls isValid to check if it 
	       {                                 // is indeed a neighbor
	            solveHelp( spotChecked, s ); // calls the original recursive 
	       }                                 // function
	   }
    }
}

// checks if the space is valid aka an existing neighbor
// on the board
bool BogSolver::valid( int check, int start ) 
{
    // if the neighbor to check is out of the array bounds
    // or it is marked it returns false
    if( (check < 0) || (check >= numBoardLetts ) || 
            ( letters[check]->mark == true ) )  
    {
        return false;
    }

    // the x and y distance from the index to its neighbor is 
    // computed
    int distanceY = letters[check]->row - letters[start]->row;
    int distanceX = letters[check]->col - letters[start]->col;

    // the neighbor to visit cannot be:
    //          - yourself
    //          - more than 1 away from you 
    if( ( check == start ) || ( distanceY > 1 ) || ( distanceY < -1 ) 
            || ( distanceX > 1 ) || ( distanceX < -1 ) ) 
    {
       return false;
    }

    // if it was not caught
    // it is a valid neighbor and true is returned
    // to SolveHelp2()
    else{ 
        return true;
    }

}

//  returns the number of words found by the 
//  solver 
int BogSolver::numWords()
{
    return found.numWords;  // already held as a stored 
}                           // private member

// overloaded numWords function
// Argument: the word length 
//          NOTE: takes in to account Q
//                which has a length of two 
int BogSolver::numWords( int len )
{
    // count of words
    int count = 0;

    // increments through the found list of all the words
    for( int i = 0; i < found.numWords; i++ )
    {   
        // checks the length of the word
        // this comparison is used in other functions relating to lenght
        // of the word
        if( len == ( found.words[i].numLetts + qCount(found.words[i]) ))
        {                           // Q is treated as QU so two letters not 
            count++;      // adds to the count
        }
    }
    return count;         // returns the total number of words 
                          // found by the funciton
}

// returns a new pointer to new BogWordList
// with all the found words in it
BogWordList* BogSolver::getWords()
{
    // allocates new memory for the BogWordList
    BogWordList* temp = new BogWordList;
    temp->numWords = found.numWords;    // same number of Words
    for( int i = 0; i < found.numWords; i++ )
    {
        for( int t = 0; t < found.words[i].numLetts; t++ )
        {
            temp->words[i].letts[t] = found.words[i].letts[t];
        }                               // copies over each
    }                                   // element

    // returns the copy pointer
    return temp;
}

// same as above
// overloaded function which takes in the length
// only difference is that it checks length using qCount
// before copying
BogWordList* BogSolver::getWords(int len)
{
    BogWordList* temp = new BogWordList;
    temp->numWords = found.numWords;
    for( int i = 0; i < found.numWords; i++ )
    {
        if( len == ( found.words[i].numLetts + qCount(found.words[i]) ))
        {
            for( int t = 0; t < found.words[i].numLetts; t++ )
            {
                temp->words[i].letts[t] = found.words[i].letts[t];
            }                               // copies over each
        }                                   // element
        
    }

    return temp;
}


// SEG FAULTS IN HERE //
// this function was meant to expand the array
// of letters if the word ever became more than 25
// but I never was able to get it working
void BogSolver::expandLetts( BogWord s )
{
    int newCap = s.lettsCap * 2;

    BogLett* temp = new BogLett[newCap];

    for( int i = 0; i < s.numLetts; i++ )
    {
	   temp[i].c = s.letts[i].c;
	   temp[i].row = s.letts[i].row;
	   temp[i].col = s.letts[i].col;
       delete s.letts;
    }
    s.letts = temp;     // seg fault here 
    s.lettsCap = newCap;

}

// converts the BogWord to its string equivalent
// replaces Q with QU when doing so 
string BogSolver::toString( BogWord s )    
{
    std::string temp;

    // loops through each letter adding to a string
    for( int i = 0; i < s.numLetts ; i++ )
    {
        temp += s.letts[i].c;     // adds the letters
        if( s.letts[i].c == 'Q') 
        {
            temp += 'U'; // adds an extra U if its a Q 
        } 
    }

    return temp; 


}


// initalizes found 
// found is empty but has space for 
// INITSIZE words after this function runs
void BogSolver::initFound()
{
    found.numWords = 0;
    found.words = new BogWord[INITSIZE];
    foundCap = INITSIZE; 
}


// Adds the BogWord s to found and its 
// array of BogWords
void BogSolver::addToFound( BogWord s )
{
    // copies the upper layers of BogWord s
    found.words[found.numWords].numLetts = s.numLetts;
    found.words[found.numWords].lettsCap = s.lettsCap;
    found.words[found.numWords].letts = new BogLett[s.numLetts];

    // loops through al lthe letts in s to deep copy 
    // BogLetts
    for( int i = 0; i < s.numLetts; i++ )
    {
        found.words[found.numWords].letts[i].c = s.letts[i].c;
        found.words[found.numWords].letts[i].row = s.letts[i].row;
        found.words[found.numWords].letts[i].col = s.letts[i].col;
    }

    // incremenets how many found holds
    found.numWords++;

    // if necessary call expand on the list
    if( found.numWords >= (foundCap-4) )
    {
       expandFound();
    }


}

// expands the array of words in found
// may be a misnomer
void BogSolver::expandFound()
{
    // creates space for a new array of BogWords
    BogWord* temp = new BogWord[foundCap*EXPAND];
    foundCap = foundCap * EXPAND;   // sets the new
                                    // foundCap
    for(int i = 0; i < found.numWords; i++ )
    {
        temp[i] = found.words[i]; // copies each word
    }

    delete[] found.words;         // deletes the og array
    found.words = temp;     // the expanded array is kept
}


// initializes all the spaces on the board 
// with coordinates and a new BogLett;
void BogSolver::initLetters()
{
    for( int i = 0; i < numBoardLetts; i++ )
    {
       letters[i] = new BogLett;
	   letters[i]->col = i % x;
	   letters[i]->row = (i / x) ;
    }
    unmarkAll();    // sets the default mark to False
}

// prints the all words
// in HBF format
// Algorithm:
//      - loops through all the words
//      - loops through each letter
//      - if it is Q be sure to add the letter U
// HBF Format < QU 0 0 I 0 1 C 0 2 K 1 2 >
void BogSolver::printWords()
{
    
    for(int i = 0 ; i < found.numWords; i++ )
    {
         cout << " < ";
        for( int t = 0; t < found.words[i].numLetts; t++ )
        {
             cout << found.words[i].letts[t].c << " ";
             if( found.words[i].letts[t].c == 'Q' )
             {
                cout << 'U' << " ";
             }
             cout << found.words[i].letts[t].row << " ";
             cout << found.words[i].letts[t].col << " ";
        }
         cout << " > " << endl;
    }
}


// prints the worsds of a certain length 
// in HBF format
// Algorithm:
//      - loops through all the words
//      - if the word length is correct
//                 - loops through printing all that words 
//                   letters
//      -if it isnt the next word is checked
// HBF Format < QU 0 0 I 0 1 C 0 2 K 1 2 >
void BogSolver::printWords( int len )
{
        
    for(int i = 0 ; i < found.numWords; i++ )
    {
        if( len == ( found.words[i].numLetts + qCount(found.words[i]) ))
        {
            cout << " < ";
            for( int t = 0; t < found.words[i].numLetts; t++ )
            {
                cout << found.words[i].letts[t].c << " ";
                if( found.words[i].letts[t].c == 'Q' )
                {
                    cout << 'U' << " ";
                }
                cout << found.words[i].letts[t].row << " ";
                cout << found.words[i].letts[t].col << " ";
            }
            cout << " > " << endl;
        }
    }
}

// prints a simple list of all the words with no 
// coordinates and not in HBF format
void BogSolver::listWords()
{
    
    for(int i = 0 ; i < found.numWords; i++ )
    {
        for( int t = 0; t < found.words[i].numLetts; t++ )
        {      // prints the letter
             cout << found.words[i].letts[t].c;
               // if its Q
             if( found.words[i].letts[t].c == 'Q' )
             {
                cout << 'U';    // the U is paired 
             }
        }
        cout << endl;
    }
}

// lists all the words in not HBF format
// overloaded function this one only outputs 
// strings with a certain length
void BogSolver::listWords( int len )
{
    // increments through all the words
    for( int i =0 ; i < found.numWords; i++ )
    {   // checks the length
        if( len == ( found.words[i].numLetts + qCount(found.words[i])) )
        {   // prints the letters with QU 
            for ( int t = 0; t < found.words[i].numLetts; t++)
            {
                cout << found.words[i].letts[t].c;
                if( found.words[i].letts[t].c == 'Q' )
                {
                    cout << 'U';
                }
            }
        cout << endl;
        }
    }
}

// increments through the bogword
// counts how many q's are in the word
int BogSolver::qCount( BogWord s)
{
    int count = 0;      // keeps track

    // goes through each of the words letters
    for( int i = 0; i < s.numLetts; i++ )
    {
        if( s.letts[i].c == 'Q' )
        {
            count++;    // adds to the count
        }
    }
    return count;   // returns the final value
}

// function which marks all the board letter
// bool mark values to false 
//      - this resets the board for each letter 
//        starting point called by solve()
void BogSolver::unmarkAll()
{
    for( int i = 0; i < numBoardLetts; i++ )
    {
	   letters[i]->mark = false;
    }
}

