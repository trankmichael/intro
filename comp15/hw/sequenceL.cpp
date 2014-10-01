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
#include "sequenceL.h"


//------------------------------------------------------------------------------
// Default Constructor
//------------------------------------------------------------------------------
Sequence::Sequence()
{
    head = NULL;
}

//------------------------------------------------------------------------------
// Constructor which takes in an element
// and makes a new list with just that element
//------------------------------------------------------------------------------
Sequence::Sequence( ElementType x )
{
    Node* nodeX = new Node;
    nodeX->value = x;
    nodeX->next = NULL;
    head = nodeX;
}

//------------------------------------------------------------------------------
//   Purpose: counts the size of the sequence
// Arguments: n/a
//     Calls: n/a
//     Notes: -functions by incremening through until 
//	       NULL is reached by a temp pointer
//	      -returns a bool
//------------------------------------------------------------------------------
int Sequence::size()
{
    Node* temp;
    temp = head;
    int length;
    
    for( int i = 0; temp != NULL; i++){
	temp = temp->next;
	length++;
    }
    
    return length;
}

//------------------------------------------------------------------------------
//   Purpose: checks if the list is empty
// Arguments: n/a
//     Calls: n/a
//     Notes: returns a bool
//------------------------------------------------------------------------------
bool Sequence::isEmpty()
{
    if( head == NULL ){
	return true;
    }
    
    else{
	return false;
    }
    
}

//------------------------------------------------------------------------------
//   Purpose: adds a copy of the new sequence to the original
// Arguments: a pointer to the sequence to be added
//     Calls: another similar function to handle adding to an empty list
//------------------------------------------------------------------------------
void Sequence::concatenate( Sequence* sequenceAdded )
{
    //prevents seg fault if there is nothing in the first list
    if( head == NULL ){
	concatenateToEmpty(sequenceAdded);
	return;
    }
    
    Node* ogListPtr;
    Node* newListPtr;
    ogListPtr = head;
    newListPtr = sequenceAdded->head;

    // Corner case where nothing is done 
    if ( sequenceAdded == NULL )
    {
	return;
    }

    //increments though the original until the end is reached at a a NULL 
    while( ogListPtr->next != NULL ){
	{
	    ogListPtr = ogListPtr->next;
	}
    }
    // adds the new list to the orignal : does so by incrementing through
    // the list-to-be-added and adding a node to the orignal with the same 
    // value each time : ends when NULL is reached in the list-to-be-added-
    for( int i = 0; newListPtr != NULL ; i++ )
    {
	ogListPtr->next = new Node;
	ogListPtr->next->value = newListPtr->value;
	newListPtr = newListPtr->next;
	ogListPtr = ogListPtr->next;
    }
    
}

//------------------------------------------------------------------------------
//   Purpose: to handle concatenating to an empty list
// Arguments: the sequence to be added
//     Calls: n/a
//     Notes: very similar to the method above, some minor changes to prevent
//	      seg fault
//------------------------------------------------------------------------------
void Sequence::concatenateToEmpty( Sequence* sequenceAdded )
{
    head = new Node;
    Node* ogListPtr;
    Node* newListPtr;
    ogListPtr = head;
    newListPtr = sequenceAdded->head;
    
    // Corner case where nothing is done 
    if ( sequenceAdded == NULL )
    {
	return;
    }
    
    // just copies the new list to the spot of the empty list
    // does so by creating new nodes starting at head
    for( int i = 0; newListPtr != NULL ; i++ )
    {
	ogListPtr->value = newListPtr->value;
	ogListPtr->next = new Node;
	newListPtr = newListPtr->next;
	ogListPtr = ogListPtr->next;
    }
}

//------------------------------------------------------------------------------
//   Purpose: returns the first
// Arguments: a pointer to the sequence to be added
//     Calls: n/a
//     Notes: -returns the ElementType
//	      -if its empty theres a cerr
//------------------------------------------------------------------------------
ElementType Sequence::first()
{
    if(head == NULL ){
	cerr << "cannot return a char from an empty sequence " << endl;
	exit(1);
    }
    else{
	return head->value;
    }
}

//------------------------------------------------------------------------------
//   Purpose: generates a new sequence of the old one without the first
// Arguments: n/a
//     Calls: n/a
//     Notes: -Returns a pointer to a new sequence without the first element
//------------------------------------------------------------------------------
Sequence* Sequence::rest()
{
    //returnedPointer does not change or move
    //just holds the place of the new Sequence
    Sequence* returnedPtr = new Sequence;
    Node* newListPtr = new Node;
    Node* ogListPtr = head;
    returnedPtr->head = newListPtr;
    
    //Checks cases where the list checked is empty or only has one element
    if( (ogListPtr == NULL ) || ( ogListPtr->next == NULL ) )
    {
	newListPtr->next = NULL;
	return returnedPtr;
    }

    //Skips the first element of the sequence
    ogListPtr = ogListPtr->next;		
    
    // incremenet through the original starting at the second and copies
    // it to a second sequence pointed to by 'returnedPtr'
    while( ogListPtr != NULL )
    {
	newListPtr->value = ogListPtr->value;
	ogListPtr  = ogListPtr->next;
	newListPtr->next = new Node;
	newListPtr = newListPtr->next;
    }
    
    return returnedPtr;

}

//------------------------------------------------------------------------------
//   Purpose: to print out a list
// Arguments: n/a
//     Calls: n/a
//     Notes: returns nothing just cout
//------------------------------------------------------------------------------
void Sequence::print()
{
    Node* temp;
    temp = head;
    
    
    if (head == NULL){
	return;
    }
    
    while( temp != NULL ){
	cout << temp->value;
	temp = temp->next;
    }
    
}





