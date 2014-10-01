//
// read_years.cpp - demo of sentinel
//

#include <iostream>
using namespace std;

const int SPACE    =  1000;
const int SENTINEL = -1;

/////////////////////////////////////////////////////////////////////////
///////////////////////////   Interfaces  ///////////////////////////////
/////////////////////////////////////////////////////////////////////////

// print a sequence of numbers
// terminated by a sentinel
void   print_seq(int nums[]);

// returns the average (mean) value
// of the integers in the sequence
double average  (int nums[]);


/////////////////////////////////////////////////////////////////////////
/////////////////////////////   Client  /////////////////////////////////
/////////////////////////////////////////////////////////////////////////

int main()
{
        int years[SPACE];
        int pos = 0;
        int y;
        double avg;

        do {
            if ( pos > SPACE ){
		cerr << "too much input";
		return 1;
	    }
	        cin >> y;
                years[pos++] = y;
        }
        while (y != SENTINEL);

        print_seq(years);
        avg = average(years);
        cout << "avg=" << avg << endl;

        return 0;
}

/////////////////////////////////////////////////////////////////////////
///////////////////////////   Abstraction ///////////////////////////////
///////////////////////////     Barrier   ///////////////////////////////
/////////////////////////////////////////////////////////////////////////

//////////////////////////  Implementations /////////////////////////////

// print a sequence of numbers
// terminated by a sentinel
void print_seq(int nums[SPACE])
{
        int pos = 0;
        while (nums[pos] != SENTINEL) {
                cout << pos << " " << 
	        nums[pos] << endl;
                pos++;
        }
}

// returns the average (mean) value

// of the integers in the sequence
double average(int seq[SPACE])
{
    int sum = 0;
    double avg;
    int SPACE = 0;

    do {
	sum = seq[SPACE] + sum;
	SPACE++;
    }
    while ( seq[SPACE] != SENTINEL );

    	
	avg = sum / ( SPACE );
        return avg;
        
}
