#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;


//
//  ccts.cpp
// 	  Purpose: handles different requests for a 
//		   seating hall with different priced
//		   seats - includes discounds based on
//		   seating and saves names
//		   !!!maximizes revenue by avoiding the!
//		   !discount of seperate seats!!!!!!!!!!
// 	edited by: Michael Tran
// Last edited on: March 30, 2013
// 	      For: Comp11 - Tufts
//		   Project 2

#include "hall.h"

bool RQ( string, Hall events[] );
int string2int( string );
bool CA( string, Hall events[] );
void menu( Hall events[] );

const int week = 7;
const int maxPtSize = 12;
const int minPtSize = 1;
const int maxDay = 6;


int main()
{
    Hall events[week];
     
    menu( events );
    
    return 0; 
}

// =============================================================
//
//			    FUNCTION
//                 	   DEFINITIONS
//
// =============================================================

// ------------------------------------------------
// Purpose: handles all the different user inputes
// Argument: the array of events type hall
// Returns: n/a
// Effects: calls two different other functions 
//	    depending on the input
// ------------------------------------------------
void menu( Hall events[] ){
   
    string input, name;
    int day;
    bool req;
   
    for( int i = 0; input != "QU" ; i++ ){  
	cin >> input;
	if ( input == "RQ" ){
	    cin >> name;
	    req = RQ( name, events );
	    if ( !req ){
		cout << "    NO " << name << " not-available" << endl;
	    }
	}
	if ( input == "CA" ){
	    cin >> name >> day;
	    req = events[day].cancel( name );
	    if ( !req ){
		cout << "    NO " << name << " no-reservation" << endl;
	    }
	    else{
		cout << "    OK " << name << " cancelled" << endl;
	    }
	 
	}
	if ( input == "PR" ){
	    cin >> day;
	    events[day].print();
	}
    }        
}

// ------------------------------------------------
// Purpose: checks too if there are any errors if
//          the input is "RQ" if there are it 
//          outputs an error message 
// Arguments: the string name, the events array
// Returns: bool -- states whether or not seats were
//	    found
// Effects: changes/assigns names in the array
// Notes:   maximizes revenue by first searching
//	    for adjacent seats and avoiding the 
//	    discount
// -----------------------------------------------

bool RQ( string name, Hall events[] ){
    
    string price, day;
    int qty, dayInt;
    bool req = false;
    
    cin >> qty >> price >> day;
    if ( (qty > 12) || (qty < 1 ) ){
	cout << "    NO " << name << " bad-number" << endl;
	return req;
    }
    if ( day == "any" ){
	for( int i = 0; (i < 6) && !req; i++){ 
	   req = events[i].request( name, qty, price, i );
	}
	return req;
    }
    else{
	dayInt = string2int(day);
	req = events[dayInt].request( name, qty, price, dayInt );
	return req;
    }
	
    
	
}

// Purpose: converts string to int
// Arguments: string in question
// Returns: an int
int string2int(string s)
{
        stringstream ss(s);
        int result;

        ss >> result;
        if (ss.fail())
                throw(runtime_error("string2int: non-numeric value: " + s));

        return result;
}
