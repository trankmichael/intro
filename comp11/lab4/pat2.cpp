#include <iostream>
using namespace std;
//
// pat1.cpp  -- draw a checkerboard pattern
//  version1: draws 8 rows of 8 chars alternating X and -
//  Goal: allow user to enter two strings and 
//		the number of pairs per line
//		the number lines per set
//		the number sets per image
//
//  tools: loops and functions(with arguments)
//
void twolines(string, string, int);   		//DECLARATION

int main()
{

    string repeat_string1, repeat_string2;
    int number_of_pairs, how_many_rows;
    int counter = 0;

// Find out what strings to repeat
    cout << " Enter two strings to repeat ";

    cin >> repeat_string1 >> repeat_string2;

// How many pairs in each row
    cout << "Enter number of pairs per row ";

    cin >> number_of_pairs;
    
// How many sets of row pairs
    cout << "Enter number of pairs of rows";

    cin >> how_many_rows;

    while ( counter < how_many_rows ) 
    {
	twolines ( repeat_string1 , repeat_string2 , number_of_pairs );
	counter++;
    }
    
}

void twolines(string s1, string s2, int reps)
{
    int counter = 0;
    while ( counter < reps )
    {
	cout << s1 << s2;
        counter ++;
    }
    while ( counter < reps )
    {
        cout << s2 << s1;
        counter ++;
    }
    cout << endl;
}
