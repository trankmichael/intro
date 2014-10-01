#include <iostream>
#include <queue>
#include <stack>
#include "dictionary.h"

using namespace std;

const int INITSIZE = 25;
const int EXPAND = 2;

struct BogLett {
    char c;
    int row, col;
    bool mark;
};
struct BogWord {
    int numLetts;
    BogLett* letts;
    int lettsCap;
};
struct BogWordList {
    int numWords;
    BogWord* words;
};

class BogBoard
{
    public:
    	BogBoard();
		BogBoard( int width, int height);
		void initDict( Dictionary dict );
		void isWord( string y );
		void addLetts( char s);
		BogWordList* getFound();
		bool solve();
		void addToDict( string add );
	
    private:
		Dictionary dict;
		void solveHelp( int start, BogWord s );
		void solveHelp2( int start, BogWord s );
		void addToFound( BogWord s );
		bool valid( int check, int start );
		void expandLetts( BogWord s );
		string toString( BogWord s ); 
		void initFound();
		void expandFound();
		void unmarkAll();
		void initLetters();
		BogLett** letters; 

		// a found list of words
		BogWordList* found;

		// single temporary word member which stores a possible word
		BogWord* word;

		// capacity of the found list
		int foundCap;

		// total letters on the board
		int numBoardLetts;

		int currentLett;
		// number of columns on the board
		int x;

		// number of rows on the board 
		int y;
	
};
