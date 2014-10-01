/*
  Tufts University
  Comp 15 HW 3
  Factory Object Implementation
  Due: October 22, 2013
*/

#include "factory.h"

/*
	Default Constructor
*/
Factory::Factory()
{
	capacity = INITIAL_SIZE;		// INITIAL_SIZE 
	nbrPackages = 0;				// declared in AssemblyLine.h
	packages = new Package[INITIAL_SIZE];
	line = new AssemblyLine;

}

/*
	Default Constructor
*/
Factory::~Factory()
{
	delete[] packages;
	delete line;
}

/*
	called By facmain.cpp
	Purpose: -calls a readin() function to read in data 
			  from an input file
			 -calls the work() function to simulate work
			  as time passes in the factory
  Arguments: -int: number of workers in the factory
  			 -an array array of rates for each worker
*/
int Factory::run( int numWorkers, double* rates )
{
	readin();
	work( numWorkers, rates );
	return 0;

}

/*
	private function called by run
	Purpose: -calls a function workUnits() to compute the 
			  total work possible in the factory
			 -calls an AssemblyLine member function work()
			  to do work on the first package in line
			 -enqueues packages at the appropriate time
  Arguments: -int: number of workers in the factory
  			 -an array array of rates for each worker
*/
void Factory::work( int numWorkers, double* rates )
{
	int time = 0; int countFinished = 0;

	// loops until the number of packages finished
	// is equal to the initial number of packages
	while( countFinished < nbrPackages ){

		// calls the work function in AssemblyLine if the 
		// package is finished the conditional will be true
		// and the time the package leaves will be printed
		if ( line->work( workUnits( numWorkers, rates ) ) )
		{
		    cout << time << endl;
		    countFinished++;
		}

		// loops through the package array and finds packages
		// that arrives during the present time and enqueues it
		for( int i = 0; i < nbrPackages; i++ )
		{
			
			if( time == packages[i].timeArrived )
			{
				line->enqueue( packages[i] );
			}
		}
		time++; // after work, and packages are added, time++
	}
}
/*
	private function called by workUnits
	Purpose: -computes the total amount of work possible 
			  given a number of workers and an array of 
			  rates, does so by summation
  Arguments: -int: number of workers in the factory
  			 -an array array of rates for each worker
 */
double Factory::workUnits( int numWorkers, double* rates) const
{
	double workFac = 0 ; 
	for( int i = 0; i < numWorkers; i++ )
	{
		workFac = workFac + rates[i];
	}
	return workFac;
}

/*
	private function called by readIn
	Purpose: -expands the dynamic array
 */
void Factory::expand()
{
	int newSize = capacity * EXPAND_FACTOR;
	Package* temp = new Package[newSize];

	for( int i = 0; i < capacity ; i++ ){
		temp[i] = packages[i];
	}

	delete[] packages;
	packages = temp;

	capacity = newSize;
}

/*
	private function called by run 
	Purpose: -reads the normal text input and stores 
			  important information in the array of Packages
			 -calls expand if necessary
  Arguments: -none
 */
void Factory::readin()
{
	int tempTimeArrived, tempUnits; 
	string tempOrderNbr, ignore;

	while( !cin.eof() )		// reads until the end of file
	{						// + one more line 
		cin >> ignore >> ignore >> ignore;
		cin >> tempOrderNbr;
		cin >> ignore;
		cin >> tempUnits;
		cin >> ignore >> ignore >> ignore >> ignore;
		cin >> tempTimeArrived;

		// stores the temps into the array space
		packages[nbrPackages].units = tempUnits;
		packages[nbrPackages].orderNbr = tempOrderNbr;
		packages[nbrPackages].timeArrived = tempTimeArrived;
		nbrPackages++; 		// increments the array space
		if ( nbrPackages >= capacity )
		{
			expand();		//calls expand if necessary
		}
	}
	nbrPackages--; // to adjust since !cin.eof() reads one extra package
				   // with "" OrderNbr, 0 units, and 0 time arrived; 	

}

