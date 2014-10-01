#include <iostream>

/* 
      3wordsort.cpp -- program to print out three words in alpha order
     usage: ./3wordsort
     input: three words
    output: the three words in alphabetical order, separated by spaces
      note: no prompt for user, no explanation on output
    
    modified by: Michael Tran
    modified on: February 7
 */

using namespace std;

void printInOrder(string, string, string);	// tell compiler about this

int main()
{
	string	w1,w2,w3;		// input values
	
	cin >> w1 >> w2 >> w3;		// read in three values
	printInOrder(w1,w2,w3);		// function does not return anything
	return 0;
}

//
// printInOrder() prints out the three words in alpha order
//		  with spaces between them, no return value
//
void printInOrder(string x, string y, string z)	
{
    if ( ( x >= y ) && ( y >= z ) )
    {
	cout << z << " "  << y << " " << x << endl;
    }
    
    if ( ( y >= x ) && ( x >= z ) )
    {
	cout << z << " " << x << " " << y << endl;
    }

    if ( ( y >= z ) && ( z >= x ) )
    {
	cout << x << " " << z << " " << y << endl;
    }

    if ( ( x >= z ) && ( z >= y ) ) 
    {
	cout << y << " " << z << " " << x << endl;
    }

    if ( ( z >= x ) && ( x >= y ) )
    {
	cout << y << " " << x << " " << z << endl;
    }

    if ( ( z >= y ) && ( y >= x ) )
    {
	cout << x << " " << y << " " << z << endl;
    }

}
