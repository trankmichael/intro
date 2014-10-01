//
// this must be in a file called solverMain.cpp
//

#include <iostream>
#include <queue>
#include <stack>
#include "BogSolver.h"

using namespace std;

int main()
{
	BogSolver solver;
	solver.readDict();
	cerr << " 1 " << endl;
	solver.readBoard();
	cerr << " 2 " << endl;
	solver.solve();
	cerr << " 3 " << endl;
	solver.printWords();
	return 0;
}