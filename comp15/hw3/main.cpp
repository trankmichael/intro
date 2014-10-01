/*
	main.cpp 
	Purpose: used for testing of the Assembly Line Object

	Tufts University Comp 15
	HW3 
	Last Edited On: October 18, 2013
*/

#include <cstdlib>		
#include "AssemblyLine.h"
using namespace std;

int main()
{
	const int numberOfPacks = 30;
	const int startIdNum = 29354; // just picked any start #
	const int dequeueFreq = 4; 	  
	stringstream ss;
	AssemblyLine* test1 = new AssemblyLine;
	Package testPackage; 



	for( int i = 0; i < numberOfPacks; i++ )
	{
		testPackage.units = i;
		ss.str("");
		ss << i + startIdNum; 
		testPackage.orderNbr = ss.str();

		// dequeue every 'dequeueFreq' times one is added
		if( i % dequeueFreq == 1 ){
			test1->dequeueFront();
		}

		test1->enqueue(testPackage);
	}
	test1->print();
}

