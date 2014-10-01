#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <stdexcept>
#include <string>
#include <ctype.h>

//
// wordfreq.cpp
//    Purpose:  takes in a text file of words and
//		sorts them alphabetically - also
//              outputs each words frequency 
//  Edited By:  Michael Tran
//         On:  April 21, 2013
//
//        For:  Tufts - Comp 11 
//              Project 3
//



using namespace std;
#include "FrequencyTable.h"

string lowercase( string );

int main(){

    string word;
    FrequencyTable table;
    string *p_word = new string;
    int    *p_frequency = new int;
    char letter;       

    cin >> word;
    while (!cin.eof())
    {
	word = lowercase( word );
	letter = word[0];
	if( ( letter >= 'a' ) && ( letter <= 'z' ) ){
	    table.insert(word);
	}
	cin >> word;   
    } 
   
    for (int i = 1; i <= table.size(); i++ ){
	table.get( i, p_word, p_frequency );
	cout << *p_frequency << " " << *p_word << endl;	
    }
    table.destroy();
}

// Purpose: converts any word to lowercase
// Arguments: a string word to be converted
// Returns: a string that is now lowercase
string lowercase( string word ){

    for( int i = 0; word[i]; i++ ){
	word[i] = tolower(word[i]);
    }

    return word;

}
