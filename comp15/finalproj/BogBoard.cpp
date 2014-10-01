#include <iostream>
#include <queue>
#include <stack>
#include "BogBoard.h"
#include <string>
#include <cmath>

using namespace std;

BogBoard::BogBoard()
{
    letters = NULL;
    word = NULL;
    foundCap = 0;
    numBoardLetts = 0;
    x = 0;
    y = 0;
}

void BogBoard::initDict( Dictionary dictionary )
{
    dict = dictionary;
}

// initializes the bogboard
// takes in the width and the height of the board
BogBoard::BogBoard( int width, int height )
{
    x = width; 		// housekeeping x 
    y = height;		//		y
    // // // cerr    << " here 2 " << endl;
    letters = new BogLett*[x*y];// creates an array of 
    // // // cerr    << " here 4 " << endl;
    numBoardLetts = x*y;   // sets the numwords in the aray to zero
    initLetters();		// of BogLetts
    // // // cerr    << " here 3 " << endl;
    currentLett = 0;
    initFound();

}

void BogBoard::addToDict( string add )
{
   // // cerr  << add;
   if( !dict.insert( add ) )
    {
        cerr << " word not added " << endl;
    }
}


BogWordList* BogBoard::getFound()
{
    return found;
}

// adds the array of words to the boggle board
// takes in an array of strings all of length x
void BogBoard::addLetts( char s )
{
    letters[currentLett]->c = s;
    currentLett++;
}

bool BogBoard::solve()
{
    BogWord s;

    if( !dict.isWord("AARDVARK") )
    {
        cerr << "AARDVARK" << endl;
    }

    for( int i = 0; i < numBoardLetts; i++ )
    {
        // // cerr   << " before unmarkAll " << endl;
        // unmarksAll the spaces
        unmarkAll();

        // // cerr   << " here " << endl;
        s.letts = new BogLett[INITSIZE];
	    s.lettsCap = INITSIZE;
    	s.numLetts = 1;
	
    	// copy over all the members of the Boglett 
    	// into the first array space in s
        s.letts[0].c = letters[i]->c;
	    s.letts[0].row = letters[i]->row;
    	s.letts[0].col = letters[i]->col;
        // // cerr   << " fuck year" << endl;
    	// calls the recursive helper function
        //solveHelp( i, s );
    	delete [] s.letts;
    }
}

void BogBoard::solveHelp( int start, BogWord s)
{
     
    // // cerr   << " here " << endl;
    if( s.numLetts >= s.lettsCap - 1  )
    {
        cerr << " expanded letters " << endl;
	   expandLetts(s);
	   s.lettsCap = s.lettsCap * EXPAND;
    }
    // // cerr   << " after " << endl;

    // copy over all the members of the current Boglett 
    // into the next array space in the BogWord 
    s.letts[s.numLetts-1].c = letters[start]->c;
    s.letts[s.numLetts-1].row = letters[start]->row;
    s.letts[s.numLetts-1].col = letters[start]->col;
    cerr << s.letts[s.numLetts-1].c << "< " << s.letts[s.numLetts].row;
    cerr << " " <<  s.letts[s.numLetts-1].col << " > " << endl;
    s.numLetts++;

    // // cerr   << " after fuck " << endl;
    // base case when the string being checked is not a prefix
    // if this happens the recurssion ends
    if( !dict.isPrefix(toString(s) ) )
    {
        cerr << " NOT PREFIX " << endl;
        return;
    }
    else{
	// incremenets the number of letter
        // // cerr   << " maybe? " << endl;

        cerr << "s.numLetts" << s.numLetts << endl;
        // cerr  << s.curLett;
    	letters[start]->mark = true;
        // cerr  << "here" << endl;
	
	// if what you found is a word add it to the list
	if( ( s.numLetts >= 3 ) && dict.isWord( toString(s) ) )
	{
        // cerr  << " HERE ??? ";

        addToFound( s );
	} 
    	
    // cerr   << " here fnial ";
	solveHelp2( start, s );   
    // cerr  << "fuck first recurseive" << endl;
    }
    letters[start]->mark = false;
    s.numLetts--;
}

void BogBoard::solveHelp2( int start, BogWord s )
{
    int spotChecked;

    for( int i = -1; i < 2; i++ )
    {
        // cerr  << i << endl;
	   for( int t = -1; t < 2; t++ )
	   {
	       spotChecked = start + i + (t* x);
           cerr << spotChecked << " ";
	       if( valid(spotChecked, start) )
	       {
	            solveHelp( spotChecked, s );
	       }
	   }
    }
}

void BogBoard::addToFound( BogWord s )
{
    found->words[found->numWords] = s;

    found->numWords++;
    cerr << " FOUND ONE BITCH " << endl;
    //// cerr  << found->numWords;
    // // // cerr    << " in here " << endl;
    if( found->numWords >= foundCap - 1)
    {
	   expandFound();
    }


}

bool BogBoard::valid( int check, int start ) 
{
    if( (check < 0) || (check >= numBoardLetts ) ||
            ( letters[check]->mark == true ) ) 
    {
        cerr << " dont check 1 " << endl;
        return false;
    }
    int distanceY = letters[check]->row - letters[start]->row;

    int distanceX = letters[check]->col - letters[start]->col;


    if( ( check == start ) || ( distanceY > 1 ) || ( distanceY < -1 ) 
            || ( distanceX > 1 ) || ( distanceX < -1 ) ) 
    {

                cerr << " dont check 2" << endl;

	   return false;
    }

    else{ 
                cerr << " check " << endl;

        return true;
    }

}


void BogBoard::expandLetts( BogWord s )
{
    BogLett* temp = new BogLett[ s.lettsCap * EXPAND ];

    for( int i = 0; i < numBoardLetts; i++ )
    {
	   temp[i].c = s.letts[i].c;
	   temp[i].row = s.letts[i].row;
	   temp[i].col = s.letts[i].col;
    }
    
    delete [] s.letts;
    s.letts = temp;

}

string BogBoard::toString( BogWord s )    
{
    string temp;
    // // cerr   << " fucking fuck you " << endl;
    for( int i = 0; i < s.numLetts ; i++ )
    {
        temp += s.letts[i].c; 
    }
    cerr << " temp.length() : " << temp.length() << endl;

    return temp;


}


void BogBoard::initFound()
{
    found = new BogWordList;
    found->numWords = 0;
    found->words = new BogWord[INITSIZE];
    foundCap = INITSIZE; 
}

void BogBoard::expandFound()
{
    BogWordList* temp = new BogWordList;

    for(int i = 0; i < found->numWords; i++ )
    {
        temp->words[i] = found->words[i];
    }

    temp->numWords = found->numWords;
    delete[] found->words;
    delete found;
    found = temp;
}

void BogBoard::initLetters()
{

    // // // cerr    << " here 5 " << endl;
    for( int i = 0; i < numBoardLetts; i++ )
    {
       letters[i] = new BogLett;
	   letters[i]->col = i % x;
	   letters[i]->row = (i / x) ;
    }
    // // // cerr    << " past loop " << endl;
    unmarkAll();
}
void BogBoard::unmarkAll()
{
    for( int i = 0; i < numBoardLetts; i++ )
    {
//        // // cerr   << i << endl;
	   letters[i]->mark = false;
    }
 //   // // cerr   << " done " << endl;
}

////
// IGNORE THIS BELOW 
// JUST IN CASE 
//
/*


bool BogBoard::cornerCase( int i, BogWord s )
{
    // calls the recursive function for the top left corners 
    // neighbors
    if( ( letters[i]->col == 1 ) && ( letters[i]->row == 1 ) )
    {
        solveHelp( i+1, addToWord( s, letters[i+1]->char ) );
        solveHelp( i+row, addToWord( s, letters[i+row]->char ) );
        solveHelp( i+1+row, addToWord( s, letters[i+1+row]->char));
    }

    // calls the recursive function for the bottom right 
    // corners neighbors
    if( ( letters[i]->col == y ) && ( letters[i]->row == x ) )
    {
        solveHelp( i-1, addToWord( s, letters[i-1]->char ) );
        solveHelp( i+row, addToWord( s, letters[i+row]->char ) );
        solveHelp( i-1+row, addToWord( s, letters[i-1+row]->char));
    }

    // bottom right corner
    if( ( letters[i]->col == 1 ) && ( letters[i]->row == x ) )
    {
        solveHelp( i+1, addToWord( s, letters[i+1]->char ) );
        solveHelp( i-row, addToWord( s, letters[i-row]->char ) );
        solveHelp( i+1-row, addToWord( s, letters[i+1-row]->char));
    }

    // bottom left corner 
    if( ( letters[i]->col == y ) && ( letters[i]->row == 1 ) )
    {
        solveHelp( i-1, addToWord( s, letters[i-1]->char ) );
        solveHelp( i-row, addToWord( s, letters[i-row]->char ) );
        solveHelp( i-1-row, addToWord( s, letters[i-1-row]->char));
    }
}

bool BogBoard::edgeCase( Dictionary dict, int i)
{
    if( ( letters[i]->col == 1 ) )
    {
        solveHelp( i-row, addToWord( s, letters[i-row]->char ) );
        solveHelp( i-row+1, addToWord( s, letters[i-rohttp://geekhack.org/index.php?board=31.0w+1]->char ) );
        solveHelp( i+1, addToWord( s, letters[i+1]->char));
        solveHelp( i+1+row, addToWord( s, letters[i+1+row]->char ) );
        solveHelp( i+row, addToWord( s, letters[i+row]->char ) );
        return true;
    }init BogBoard::initWord()
{


}

    if( ( letters[i]->col == col ) )
    {
        solveHelp( i-row, addToWord( s, letters[i-row]->char ) );
        solveHelp( i-row-1, addToWord( s, letters[i-row-1]->char ) );
        solveHelp( i-1, addToWord( s, letters[i-1]->char));
        solveHelp( i-1+row, addToWord( s, letters[i-1+row]->char ) );
        solveHelp( i+row, addToWord( s, letters[i+row]->char ) );
        return true;
    }

    if( ( letters[i]->row == 1 ) )
    {
        solveHelp( i+row, addToWord( s, letters[i+row]->char ) );
        solveHelp( i+row-1, addToWord( s, letters[i+row-1]->char ) );
        solveHelp( i-1, addToWord( s, letters[i-1]->char));
        solveHelp( i+1+row, addToWord( s, letters[i+1+row]->char ) );
        solveHelp( i+1, addToWord( s, letters[i+1]->char ) );
        return true;
    }

    if( ( letters[i]->row == row ) )
    {
        solveHelp( i-row, addToWord( s, letters[i-row]->char ) );
        solveHelp( i-row-1, addToWord( s, letters[i-row-1]->char ) );
        solveHelp( i-1, addToWord( s, letters[i-1]->char));
        solveHelp( i+1-row, addToWord( s, letters[i+1-row]->char ) );
        solveHelp( i+1, addToWord( s, letters[i+1]->char ) );
        return true;
    }
    else{
        return false;
    }
}

bool BogBoard::normalCase( int i )
{
    solveHelp( i++, addToWord( s, letters[i++]->char ) );
    solveHelp( i--, addToWord( s, letters[i--]->char ) );
    solveHelp( i-1-row, addToWord( s, letters[i-1-row]->char));
    solveHelp( i+1-row, addToWord( s, letters[i+1-row]->char ) );
    solveHelp( i+1+row, addToWord( s, letters[i+1+row]->char ) );
    solveHelp( i-1+row, addToWord( s, letters[i-1+row]->char));
    solveHelp( i+row, addToWord( s, letters[i+row]->char ) );
    solveHelp( i-row, addToWord( s, letters[i-row]->char ) );
    return true;
}

queue BogBoard::findLetters( char y )
{
    queue<int> q1;
    unmarkAll();

    for( int i = 0; i < curLett; i++ )
    {
        if( letters[i]->c == y)
        {
            q1.push(i);
        }
    }

}



// bool BogBoard::isAdjacent( Boglett* x, BogLett* y)
// {
//     int disx = x->row - y->row;
//     int disy = x->col - y->col;
// 
//     if( ( abs(disy) <= 1 ) || ( abs(disx) <= 1 ) )
//     {
//         return true;
//     }
// 
//     else{
//         return false;
//     }
// }


bool BogBoard::isWordHelp( string y, i )
{


}*/

