#include <iostream>
#include <queue>
#include <stack>
#include "BogSolver.h"

using namespace std;

class BogValidator
{
	public:
		BogValidator();
		~BogValidator();
		bool readDict();
		bool readBoard();
		bool isValid( string s );
		void checkWords();

	private:
		Dictionary dict;
		BogSolver solved;

};
