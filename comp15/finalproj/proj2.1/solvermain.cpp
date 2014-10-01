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
	solver.readBoard();
	solver.solve();
	solver.printWords();
	return 0;
}
