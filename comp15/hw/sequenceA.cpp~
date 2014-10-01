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
#include "sequenceA.h"

//------------------------------------------------------------------------------
// Default Constructor of space five
//------------------------------------------------------------------------------
sequence::sequence()
{
	list = new ElementType[5];
	currentCapacity = 5;
	currentLength = 0;
}

//------------------------------------------------------------------------------
// Constructor which takes in an element
// and makes a new array with just that element
//------------------------------------------------------------------------------
sequence::sequence( ElementType character )
{
	list = new ElementType[1];
	list[0] = character;
	currentCapacity = 1;
	currentLength = 1;

}

//------------------------------------------------------------------------------
//   Purpose: checks if the list is empty
// Arguments: n/a
//     Calls: n/a
//     Notes: returns a bool
//------------------------------------------------------------------------------
bool sequence::isEmpty()
{
	if( currentLength == 1 ){
		return true;
	}
	else{
		return false;
	}

}

//------------------------------------------------------------------------------
//   Purpose: counts the size of the sequence
// Arguments: n/a
//     Calls: n/a
//     Notes: just returns the private variable currentLength
//------------------------------------------------------------------------------
int sequence::size()
{

	return currentLength;

}

//------------------------------------------------------------------------------
//   Purpose: adds a copy of the new sequence to the original
// Arguments: a pointer to the sequence to be added
//     Calls: two other functions to handle empty cases and normal cases
//------------------------------------------------------------------------------
void sequence::concatenate( sequence* listAdded)
{
	// The space needed is the sum of the two values above
	int spaceNeeded = listAdded->currentLength + currentLength;	
	int factorOfExpand;
	
	currentLength = spaceNeeded;
	
 	if(currentCapacity < spaceNeeded ){
	    factorOfExpand = spaceNeeded / currentCapacity + 1.5;
	    expand( factorOfExpand );

	}
		
	concatenateEmptyCases( listAdded );
	concatenateNormalCases( listAdded, spaceNeeded );
	

	
}

//------------------------------------------------------------------------------
//   Purpose: if the list added is empty nothing happens
// Arguments: a pointer to the sequence to be added
//     Calls: n/a
//------------------------------------------------------------------------------
void sequence::concatenateEmptyCases( sequence* listAdded ){
    if( listAdded->currentLength == 0 )
    {
	return;
    }
    
}

//------------------------------------------------------------------------------
//   Purpose: adds a copy of the new sequence to the original 
// Arguments: a pointer to the sequence to be added, and the spaceNeeded
//     Calls: n/a
//     Notes: -increments through the array starting at the end of the original
//	      -then starts adding things to the list
//------------------------------------------------------------------------------
void sequence::concatenateNormalCases( sequence* listAdded, int spaceNeeded ){
    
    int startPosition = currentLength-1;
    int positionOfAddedList = 0;
    
    for( int i = startPosition; i < spaceNeeded ; i++ )
    {
	list[i] = listAdded->list[positionOfAddedList];    
	positionOfAddedList++;
    }
}
//------------------------------------------------------------------------------
//   Purpose: expands the list by a factor determined in concatenate
// Arguments: int factor of multiplication
//     Calls: n/a
//      Note: the factor is determined by dividing the spaceNeeded size by the 
//            current space in the array
//------------------------------------------------------------------------------
void sequence::expand( int factor )
{
    int newCapacity = currentCapacity * factor;
    ElementType* temp = new ElementType[newCapacity];
    
    for( int i = 0;  i < currentLength ; i++ ){
	temp[i] = list[i];
    }
    
    delete[] list;
    list = temp;
    currentCapacity = newCapacity;

}

//------------------------------------------------------------------------------
//   Purpose: returns the first element in a sequence, if there is none a cerr
// 	      is outputed
// Arguments: n/a
//     Calls: n/a
//------------------------------------------------------------------------------
ElementType sequence::first()
{
    if( currentLength == 0 ){
	cerr << "cannot return a char from an empty sequence " << endl;
	exit(1);
    }
    
    ElementType firstLetter;
    firstLetter = list[0];
    return firstLetter;
}

//------------------------------------------------------------------------------
//   Purpose: a pointer to a copy of a new array that does not contain the first
//            element
// Arguments: n/a
//     Calls: n/a
//     Notes: if the list only has one element or none then a pointer to a new 
//            array is returned
//------------------------------------------------------------------------------
ElementType* sequence::rest()
{
    int copyLength = currentLength - 1;
    
    // if the list has less than two elements
    if( copyLength < 1 ){
	ElementType* tailCopy = new ElementType[1];
	return tailCopy;
    }
    
    // new array made with one less space than the length of the original
    ElementType* tailCopy = new ElementType[copyLength];
    
    for( int i = 0; i < currentLength ; i++ ){
	tailCopy[i - 1] = list[i];
    }
    
    return tailCopy;
    
}

//------------------------------------------------------------------------------
//   Purpose: prints out the array
// Arguments: n/a
//     Calls: n/a
//     Notes: n/a
//------------------------------------------------------------------------------
void sequence::print()
{
    for( int i = 0; i < currentLength ; i++ ){
	cout << list[i];
    }
    
}
