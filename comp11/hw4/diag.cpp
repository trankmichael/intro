#include <iostream>
using namespace std;

/*
 *	   diag.cpp: takes in two strings and a height and prints
 *		     a pattern accordingly
 * last modified by: Michael Tran
 * last modified on: February 18, 2013
 *		for: Comp 11 HW 4
 *
 */

void line( string, string, int, int ); 
void draw_picture( string, string, int ); 

int main()
{
    int height;
    string s_1, s_2;


    cout << "First string? ";   	//Asks user for input and assigns
    cin >> s_1; 			//them to variables s_1, s_2, and 
    cout << "Second string? ";          //height
    cin >> s_2;
    cout << "Height? "; 
    cin >> height;


	    
    draw_picture( s_1, s_2, height );


	    return 0;
}

void draw_picture( string firstString, string secondString, int height )
{
    int first_length = height - 1; 
    int second_length = 0;


//prints first string a set number of times, then prints the second string
//after each line each string length is changed by the incrementing and decrementing

    while (second_length < height)
    {
	line(firstString, secondString, first_length, second_length);
	first_length--;
	second_length++;
	cout << endl;
    }


}

void line( string s_1, string s_2, int first_length, int second_length )
{

//prints the second string first then prints the first string
//based on the counters in the draw_picture function
//this function only prints one line

    for ( int n=0 ; n < second_length; n++ )
    {
	cout << s_2;
    }
    for ( int n=0 ; n < first_length; n++ )
    {
	cout << s_1;
    }

}
