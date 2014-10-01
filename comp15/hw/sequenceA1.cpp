typedef char ElementType;
#include "sortedlistL.h"

sequence::sequence()
{
	list = new ElementType[1]
	list[0] = "";
	currentCapacity = 1;
}

sequence::sequence( ElementType character )
{
	list = new ElementType[1]
	list[1] = character;
	currentCapacity = 1;

}

bool sequence::isEmpty()
{
	if( list[0] == "" ){
		return true;
	}
	else{
		return false;
	}

}

int sequence::size( ElementType* listCounted )
{
	int size = 0;

	for( i = 0; ( i < currentCapacity ) && ( listCounted[i] != "" ) ; i++ ){
		size++;
	}
	
	return size;

}

void sequence::concatenate( ElementType* listAdded)
{

	int listAddedSize = size( listAdded );					// Counts how many characters are in the new list to be added
	int currentListSize = size ( list );					// Counts how many characters are already in the present list
	int spaceNeeded = listAddedSize + currentListSize;			// The space needed is the sum of the two values above
	int factor = spaceNeeded / 

	ElementType* temp = new ElementType[ listAddedSize ]; 	//Creates a new pointer where the list can be copied into


 	if(currentCapacity < spaceNeeded ){
	    expand();
	}





}

void sequence::expand( int factor )
{
    int newCapacity = currentCapacity * factor;
    ElementType* temp = new ElementType[newCapacity];
    
    for( i = 0; ( i < currentCapacity ) && ( list[i] != "" ) ; i++ ){
	temp[i] = list[i];
    }
    list = temp;
    delete [] list;
    currentCapacity = newCapacity;

}
