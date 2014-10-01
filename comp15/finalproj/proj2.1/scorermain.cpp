// scorermain.cpp
// computes the score from a list 
// inputted in a format outputted 
// by the validator

#include <iostream>
#include <cstdlib>
#include <string>
#include "dictionary.h"

using namespace std;

int checkScore( string );

int main()
{
	Dictionary alreadyIn;	// holds the words already inputted 
	string temp;			// stores user input 
	int score = 0;			// tally of the score
	int pts = 0;			// the pts for a certain word
	int wordCount =0;		// how many words are inputted

	cin >> temp;

	while( !cin.eof() )
	{
		if( temp == "OK" )
		{
			cin >> temp;
			if( !alreadyIn.isWord( temp )) // check if its in the dictionary
			{
				pts = checkScore( temp );
				cout << pts << "OK " << temp << endl;
				score += pts;	// add to score
				wordCount++;	// increment the number of words
				alreadyIn.insert(temp); // add to the dictionary
			}
		}
		else{
				cin >> temp;
				cout << 0 << "NO " << temp << endl;
		}
		cin >> temp;
	}

	cout << wordCount << " words " << score << " points" << endl;
	return 0;			// the correct output is from above
}

// based off of the boggle scores on wikipedia
 int checkScore( string temp )
{
	if( temp.length() <= 4 )
	{
		return 1;
	}
	else if( temp.length() == 5)
	{
		return 2;
	}
	else if( temp.length() == 6)
	{
		return 3;
	}
	else if( temp.length() == 7)
	{
		return 5;
	}
	else if( temp.length() >= 8)
	{
		return 11;
	}
	return 0;
}