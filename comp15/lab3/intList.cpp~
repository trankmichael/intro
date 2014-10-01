#include "intList.h"


IntList::IntList()
{
    iList = new int[INIT_CAPACITY];
    capacity = INIT_CAPACITY;
}

IntList::IntList( int i )
{
    iList = new int[INIT_CAPACITY];
    iList[0] = i;
    capacity = INIT_CAPACITY;
}

bool IntList::assignNewInt( int add )
{
    if( capacity <= count ){
	if( !expandList() ){
	    return false;
	}
    }
    else{
	intList[count] = add;
	count++;
    }
}

bool IntList::expandList()
{
    int newSize = capacity * EXPAND_FACTOR;
    int* temp = new int[newSize];
    
    if(temp == NULL){
	return false;
    }

    for(int i = 0; i < capacity; i++){
	temp[i] = intList[i];	
    }
       
    delete[] intList;
    intList = temp;
    capacity = newSize;
    
}

void IntList::printIntList() const
{
    for(int i = 0; i < capacity; i++ )
    {
    
	cout << intList[i];

    }
    
}
