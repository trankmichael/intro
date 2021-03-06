/* sandwichList.cpp
 * Comp 15 
 * Spring 2013 
 * Lab 3
 */

#include "sandwichList.h"


SandwichList::SandwichList()
{
	capacity = INITIAL_SIZE;
	orders = new Order[INITIAL_SIZE];

	back = 0;
	front = 0;
}

bool SandwichList::isEmpty()
{
	if (size() == 0)
		return true;
	else
		return false;
}


int SandwichList::size()
{
	return (back - front + capacity) % capacity;
}

//function to pop
Order SandwichList::getNext()
{
    if ( isEmpty() ){
	exit(1);
    }
    
    
    int temp = front;
    front = ( front + 1 ) % capacity;
    return orders[temp];

}

//add an element, make sure it is not full, if it is call expand funciton
void SandwichList::add(const Order& sw)
{
    orders[back] = sw;
    
    back = ( back + 1 ) % capacity;
    
    if ( back == front ){
	expandList();	
    }
    
}

//Double the queue size, copy the values, and reset back and front
void SandwichList::expandList()
{
    int newSize = capacity * 2; 
    Order* temp = new Order[newSize];
    
    for( int i = 0 ; i < capacity ; i++ ){
	temp[i] = orders[ (front + i ) % capacity ];
    }
    
    delete[] orders;
    orders = temp;
    
    front = 0;
    back = size();
    
    capacity = newSize;


}

void SandwichList::printOrder(Order s)
{
	cout << s.sandwich << " " << s.customerName << " " << s.orderNbr << " " << s.fries;
	cout << endl;
}



