#include <iostream>
using namespace std;
/*
 *     mirror.cpp: prints a pattern when given an integer
 *  date modified: February 18 2013
 *    modified by: Michael Tran
 *	           Comp 11 Tufts 		
 *
 */
void forward(int);
void backward(int);

int main()
{
    int max_value;

    cout << "Maximum value? ";  	//Asks user for value and stores value
    cin >> max_value;
    
    if ( max_value < 0 ){		//If it is negative --> end program
	return 0;
    }



    else {

	for (int i = 0; i < 4; i++) {   //for loop that prints four lines

	forward(max_value);		//Forward prints half of one line
	cout << "|";
	backward(max_value);		//backward prints last half of line
	cout << endl;
	}

    }

    return 0;

}

void forward(int max_value)		//counts up from 0 while printing each count 
{					//until it reaches the max_value

	int count = 0;

	while ( count <= max_value ){
	    cout << count;
	    count++;
	}

}
void backward(int max_value)		//counts down from max_value until it
{					//reaches 0

    while ( max_value >= 0 ){
	cout << max_value;
	max_value--;
    }

}
