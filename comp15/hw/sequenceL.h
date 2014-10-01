/*
*-------------------------------------------
*         For: Comp 15 HW 1
*   Edited On: Sept 17, 2013
* Description: Implementation for a Dynamic
*		Array to take in a sequence 
*		of ElementTypes
*--------------------------------------------
*/

typedef char ElementType;

#include <cstdlib>
#include <iostream>
using namespace std;

struct Node
{
    ElementType value;
    Node* next;
};


class Sequence
{

  public:
    
    Sequence();
    Sequence( ElementType x );
    bool isEmpty();
    int size();
    void concatenate( Sequence* sequenceAdded );
    ElementType first( );
    Sequence* rest();
    void print();

    
  private:
    Node* head;
    void concatenateToEmpty( Sequence* sequenceAdded );



};
