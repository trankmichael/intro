/* 		UTLN:
 *		  SMOTIA01
 * 		  QHOOD01 
 * 		  MTRAN04
 *
 * main.cpp -- test the Sequence implementations
 *
 * IMPORTANT: This file is generic and will be converted into two versions
 *  one version called mainL.cpp and one called mainA.cpp
 *
 *  Those two can be compiled with the specific header files
 *  and then linked with the implementation files
 *
 *  The conversion is simple, use SequenceX for sequenceA or sequenceX 
 *  ==== do not delete this line
 */

#include <iostream>
#include "sequenceX.h"	

using namespace std;

/* 
    Purpose: Test to see if we can print a single character. 
    Utilizes overloaded constructor.
    Pre-condition:
    Post-condition:
*/
void printTest1()
{
	cout << "test print for 1-item list" << endl;   // state purpose

	SequenceX s('a');				// make a sequence
	cout << "Expected: a returned: "; 		// what we want
	s.print();					// what we get
	cout << endl;
}

/* 
    Purpose: Test to see if we can concatenate with another 
	sequence N number of times
    Pre-condition:
    Post-condition:
*/
void expandTest1(int elements)
{
	cout << "test expand(concat another sequence n times" << endl;

	SequenceX* seq1 = new SequenceX('a');		// make a sequence
	SequenceX* seq2 = new SequenceX('b');		// and another

	for(int i = 0; i < elements; i++){		// add 'em on
		seq1->concatenate(seq2);
	}

	// report results
	cout << "expected: a followed by " << elements << " b's returned: "; 
	seq1->print();

	cout << endl;
}

void constructorTestSize( ElementType testChar )
{
	cout << "test print size for 1-item list" << endl;
	SequenceX s(testChar);
	cout << "Expected Size: 1 " << endl;
	cout << "Size: " << s.size() << endl;
}

void concatenateTestE2E()
{
    	cout << "test Concatenate Empty to Empty ";
	SequenceX* c1 = new SequenceX;
	SequenceX* c2 = new SequenceX;
	c1->concatenate(c2);
	cout << "Expected: empty " << endl;
	cout << "Result: "; 
	c1->print();
	cout << endl;
}

void concatenateTestE2R()
{
	cout << "test Concatenate Empty to Regular ( length 1 ) ";
	SequenceX* c1 = new SequenceX('a');
	SequenceX* c2 = new SequenceX;
	c1->concatenate(c2);
	cout << "Expected: a " << endl;
	cout << "Result: "; 
	c1->print();
	cout << endl;
}

void concatenateTestR2R()
{
	cout << "test Concatenate Regular to Regular ( lengths 1 ) ";
	SequenceX* c1 = new SequenceX('a');
	SequenceX* c2 = new SequenceX('b');
	c1->concatenate(c2);
	cout << "Expected: a b" << endl;
	cout << "Result: "; 
	c1->print();
	cout << endl;
}

void concatenateTestSelf()
{
	cout << "test Concatenate to ITSELF ";
	SequenceX* c1 = new SequenceX('a');
	c1->concatenate(c1);
	cout << "Expected: a a " << endl;
	cout << "Result: "; 
	c1->print();
	cout << endl;
}

void restTestEmpty()
{
	SequenceX s;
	cout << "Expected: 1 " << endl;
	cout << "Result: " << s.rest()->isEmpty();
}

void restTestOne()
{
	SequenceX s('s');
	cout << "Expected: 1 " << endl;
	cout << "Result: " << s.rest()->isEmpty();
}

void restTestRegular( int num )
{
	SequenceX s('a');
	SequenceX* c = new SequenceX('b');
	for( int i = 0 ; i < num ; i++ ){	
		s.concatenate(c);
	}
	cout << "Expected: "<< num << " b's" << endl;
	cout << "Result: ";
	s.rest()->print();

}

void IsEmptyTest()
{
     

}

int main(){

	cout << "==========v Constructor Tests v=======" << endl;
	constructorTestSize('m');
	cout << "==========^ Constructor Tests ^=======" << endl << endl;

	cout << "==========v isEmpty Tests v=======" << endl;
	cout << "==========^ isEmpty Tests ^=======" << endl << endl;

	cout << "==========v print() Tests v=======" << endl;
		printTest1();
	cout << "==========^ print() Tests ^=======" << endl << endl;
			
	cout << "==========v size() Tests v=======" << endl;
	cout << "==========^ size() Tests ^=======" << endl << endl;
	
	cout << "==========v first() Tests v=======" << endl;
	cout << "==========^ first() Tests ^=======" << endl;
	
	cout << "==========v rest() Tests v=======" << endl << endl;
	restTestEmpty();
	restTestOne();
	restTestRegular( 4 );
	cout << "==========^ rest() Tests ^=======" << endl << endl;

	cout << "==========v concatenate() Tests v=======" << endl;
	concatenateTestE2E();
	concatenateTestE2R();
	concatenateTestR2R();
	concatenateTestSelf();
	cout << "==========^ concatenate() Tests ^=======" << endl << endl;
		
	cout << "==========v expand Testsv=======" << endl;
		expandTest1(1000);
	cout << "==========^ expand Tests^=======" << endl << endl;;
	
	
	return 0;
}
