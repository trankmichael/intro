#include <iostream>
//
// avg2.cpp -- compute average of three numbers
//             demonstrates:
//		  input, output
//		  variables, assignment
//		  operations: +, / with ints, %, / with floats
//		  comments
// modified by:Michael Tran
//          on:Jan 23, 2013
//

using namespace std;

int main()
{
	double	a,b,c,d;	// creates three storage boxes for ints
	double	sum;		// sum goes here
	double	quotient;
	//int	remainder;
	int	num;

	num = 4;		// number of values to average

	cout << "Please enter three numbers: ";

	cin  >> a;
	cin  >> b;
	cin  >> c;
	cin  >> d;
	
	// do the processing part now
	
	sum = a + b + c + d;	// add and store

	quotient  = sum / num;
	//remainder = sum % num;

	// output the result

	cout << "The average is " << quotient << " " ;
	//cout << remainder << "/" << num << endl;
	//cout << "In decimal form: " << sum/3.0 << endl;
}
