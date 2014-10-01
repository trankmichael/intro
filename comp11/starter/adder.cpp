//
//adder c.pp
//	purpose: add two numbers
//	     by: Michael Tran
//	   date: January 29, 2013
//

#include <iostream> 

using namespace std;

int main()
{ 
    double a, b, sum;

    cout << "Enter two numbers: ";
    cin >> a;
    cin >> b;
    sum = a + b;
    cout << "This sum is " << sum << endl;

    return 0;

}
