/*
*-------------------------------------------
*         For: Comp 15 HW 1
*   Edited On: Sept 17, 2013
* Description: Implementation for a Dynamic
*		Array to take in a sequence 
*		of ElementTypes
*--------------------------------------------
*/
#include "sequenceA.h"
#include <iostream>
using namespace std;


int main()
{
    
    
    sequence s1;
    sequence s2('a');
    sequence* temp = &s2;
    s1.concatenate( temp );
    s1.print();
    cout << endl;
    sequence s3('c');
    sequence* temp2 = &s3;
    s1.concatenate( temp2 );

    return 0;
}