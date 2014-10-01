/*
  Tufts University
  Comp 15 HW 3
  AssemblyLine Object Implementation
  Due: October 22, 2013
*/

#include "AssemblyLine.h"

/*
	Default Constructor
*/
AssemblyLine::AssemblyLine()
{
	capacity = INITIAL_SIZE;
	packages = new Package[INITIAL_SIZE];

	for( int i; i < INITIAL_SIZE; i++){
		packages[i].unitsWorked = 0;
	}

	back = 0;
	front = 0;
}

/*
	Default Destructor 
*/
 AssemblyLine::~AssemblyLine()
 {
	delete[] packages;
 }

/*
	called by work() and dequeueFront() 
	Purpose: -checks if the queue is empty by checking the 
			  if it is zero the queue is empty
			 -calls the size function
  Arguments: n/a
  	Returns: true if empty, false otherwise
*/
bool AssemblyLine::isEmpty() const
{
	if ( size() == 0 )
		return true;
	else
		return false;
}

/*
	called by isEmpty
	Purpose: -checks the size of the queue
  Arguments: n/a
  	Returns: int: how many packages in queue
*/
int AssemblyLine::size() const
{
	return ( back - front + capacity ) % capacity;
}

/*
	public function called in Factory::work()
	Purpose: -does work on the package at the front
  Arguments: double: workUnits which is the work done on the
  				     package
  	Returns: -true if the work was successful in finishing the
  			  order, false otherswise
*/
bool AssemblyLine::work( double workUnits )
{
	// work will be done iff the queue is not empty
	if( !isEmpty() )
	{	
		// adds to the unitsWorked member depending on the workUnits
		packages[front].unitsWorked = packages[front].unitsWorked + workUnits;

		// checks if the package is finished  
		if( packages[front].unitsWorked >= packages[front].units )
		{
			printFront();			// calls print functon
			dequeueFront();			// deques the package once finished 
			return true;			// returns true
		}
		else{
			return false;			// returns false if the package 
		}
	}

	return false;  // returns false for an empty queue
}

/*
	private function called in AssemblyLine::work()
	Purpose: -prints front package output in the correct format
			  once its finished
  Arguments: n/a
  	Returns: n/a
*/
void AssemblyLine::printFront() const
{
	// displays the required output 
	cout << "Package order number " << packages[front].orderNbr;
	cout << " with " << packages[front].units << " units arrived at time ";
	cout << packages[front].timeArrived << " and left at time ";
}

/*
	private function called in AssemblyLine::work()
	Purpose: -moves the front to the next package in the queue
  Arguments: n/a
  	Returns: n/a
*/
bool AssemblyLine::dequeueFront()
{
	if( !isEmpty() )
	{
		front = (front + 1) % capacity;		// front is moved
		return true; 						// returns true
	}											
	return false;					// returns false if empty
}

/*
	private function called in Factory::work()
	Purpose: -adds a new item to the queue
  Arguments: Package: the order added 
  	Returns: n/a
*/
void AssemblyLine::enqueue( Package added )
{
	packages[back] = added;	// adds the package to the back

	back = (back + 1 ) % capacity;

	if( back == front ){		// checks to see if the queue
		expandLine();			// is full, if so expands
	}
}

/*
	private function called in Factory::work()
	Purpose: expands the size of the queue and copies over
			 the old queue in the correct order
  Arguments: n/a 
  	Returns: n/a
*/
void AssemblyLine::expandLine()
{
	int newSize = capacity * EXPAND_FACTOR;
	Package* temp = new Package[newSize];

	for( int i = 0; i < capacity ; i++ ){				// copies the old to the 
		temp[i] = packages[ ( front + i ) % capacity ];	// new temp in order
	}

	for( int i = capacity; i < newSize; i++){   // initializes the blank spaces
		temp[i].unitsWorked = 0;				// member unitsWorked to zero
	}
	delete[] packages;							// deletes the old queue
	packages = temp;							// assigns the new queue

	front = 0;									// front is the first element
	back = capacity;							// back is the first empty 

	capacity = newSize;							// capacity is updated 
}

// 	print function just used for testing
// 	Purpose: prints the queue in order
void AssemblyLine::print() const
{

	for( int i = front; i < back ; i = (( i + 1 ) % capacity) ){
		cout << "ORDER NUMBER: " << packages[i].orderNbr << endl; ;
		cout << "       UNITS: " << packages[i].units << endl; ; 
	}
}

