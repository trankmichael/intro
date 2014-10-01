#include "BogSolver.h"

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

BogSolver::BogSolver()
{
	found.numWords = 0;
}

bool BogSolver::readDict()
{
	string temp;

	cin >> temp;
    while(temp != ".")
    {
    	dict.insert( temp );
    	cin >> temp;
    }
}

bool BogSolver::readBoard()
{
	int numRows, numCols;
	string temp;

	cin >> numRows;
	cin >> numCols;

	// cerr << " here 1 " << endl;

	board = BogBoard( numCols, numRows );
	board.initDict( dict );

	// cerr << " here " << endl;
	for( int i = 0 ; i < numRows; i++ )
	{
		cin >> temp;
		for( int t = 0; t < numCols; t++ )
		{
			board.addLetts(temp[t]);
		}
	}
}

void BogSolver::printWords()
{
	cout << " < ";
	cerr << found.numWords;
	for(int i = 0 ; i < found.numWords; i++ )
	{
		for( int t = 0; t < found.words[i].numLetts; t++ )
		{
			cout << found.words[i].letts[t].c << " ";
			cout << found.words[i].letts[t].row << " ";
			cout << found.words[i].letts[t].col << " ";
		}
		cout << " > " << endl;
	}
}

bool BogSolver::solve()
{
//	cerr << " where im at " << endl;
	board.solve();
}