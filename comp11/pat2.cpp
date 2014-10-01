//
//  pat.cpp  -- draw a checkerboard pattern
//  version1: draws 8 rows of 8 chars alternating X and -
//  Goal: allow user to enter two strings and 
//		the number of pairs per line
//		the number lines per set
//		the number sets per image
//
//  tools: loops and functions(with arguments)
//

#include <iostream>

using namespace std;

void twolines( string s1 , string s2 );		// <-- declaration

int main()
{
      int how_many = 100;
      int counter = 0;
      
      while (counter < how_many) 
      {
	    twolines( "===" , "---" );
	    counter++;
      }
    
    return 0;

}

void twolines(string s1, string s2)
{

      cout << s1 << s2
	   << s1 << s2
	   << s1 << s2
	   << endl;
	    
      cout << s2 << s1
	   << s2 << s1
	   << s2 << s1
	   << endl;
}

