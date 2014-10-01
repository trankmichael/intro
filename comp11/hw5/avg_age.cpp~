//
//	avg_age.cpp
//
//	  Purpose: Reads in a list of names and birthyears
//		   when given a specific name on the list prints 
//		   the average age
//		   stops at sentinel year -1
//	
//	edited by: Michael Tran
//	edited on: January 25, 2013
//
//	Comp 11 HW 5-4
//

#include <iostream>
using namespace std;

const int SPACE = 50000;
const int SENTINEL = -1;

void averageage( string names , int years[], string names[] );

int main()
{

    int years[SPACE];
    string names[SPACE];
    int pos = 0;
    string name;
    int y;

    do {
	
	if ( pos > SPACE ){			// Too much data prints error message
	    cerr << "too much data";
	    return 1;                        
	}

	cin >> years[pos]; 			// values are assigned to spaces 
	cin >> names[pos];			// two arrays - each space in the
	y = years[pos];				// 'names' array is paired with a
	pos++;					// value in the 'years' array

    }	while ( y != SENTINEL ); 

    cout << "Enter a name: ";			// Asks for the name to search
    cin >> name;

    averageage( name, years, names );		// calls the void function which prints
						// the average age

    return 0;

}

void averageage ( string name , int years[SPACE] , string names[SPACE] )
{
    int thisYear = 2013;
    int sum = 0;
    int pos = 0;
    int count = 0;
    double avg;
    int age;


    do {					
						//
	if ( names[pos] == name )		// Loop which goes through all the spaces in the array of names
	{					// by incrementing "pos".  When a value in the array is equal to 
	    age = thisYear - years[pos];	// the name were searching for, calculates its age and adds the age	
	    sum = sum + age;			// to sum.  also counts how many ages have been added with count
 	    count++;				//
	}

	pos++;

    } while ( years[pos] != SENTINEL );		// stops at the sentinel value


    if ( count == 0 ){				// If count is zero that means no matching name was found
	cout << "name not found";		
    }
    else {					// If there were matching names the average is found
						// and printed by dividing the sum by the number of ages  
	avg = sum / count;			// added.
	cout << avg;

    }


}
