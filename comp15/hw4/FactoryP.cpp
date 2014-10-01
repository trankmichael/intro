/*
  Tufts University
  Comp 15 HW 4
  Factory Object Implementation
  Due: November 12, 2013
*/

#include "Factory.h"

/*
	Default Constructor
*/
Factory::Factory( int LineNumber, double* ratesIn  )
{
	capacity = INITIAL_SIZE;		// INITIAL_SIZE 
	nbrPackages = 0;				// declared in AssemblyLine.h
	packages = new Package[INITIAL_SIZE];

	lines = new AssemblyLine[LineNumber];
	lineCount = LineNumber;
	rates = ratesIn;
}

/*
	Default Constructor
*/
Factory::~Factory()
{
	delete[] packages;
	delete[] lines;
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
int Factory::run()
{
	readin();
	work();
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
void Factory::work()
{
	int time = 0; int countFinished = 0;

	// loops until the number of packages finished
	// is equal to the initial number of packages
	while( countFinished < nbrPackages ){

		// calls the work function in AssemblyLine if the 
		// package is finished the conditional will be true
		// and the time the package leaves will be printed

		for( int i = 0; i < lineCount; i++)
		{
			if ( lines[i].work( rates[i] ) )
			{
		    	cout << time << " from " << i+1 << endl;
			    countFinished++;
			}
		}

		// loops through the package array and finds packages
		// that arrives during the present time and enqueues it
		for( int i = 0; i < nbrPackages; i++ )
		{
			
			if( time == packages[i].timeArrived )
			{
				
				lines[dispatcherP()].enqueue( packages[i] );
			}
		}
		time++; // after work, and packages are added, time++
	}
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

	/////////////////////////////////////////////////////////////
	///                                                       ///
	///														  ///
	///						DISPATCHERS                       ///
	/// 												      ///
	///														  ///
	/////////////////////////////////////////////////////////////


//	-returns the index of the first line found with the smallest
//   number of packages in it 
int Factory::dispatcherP()
{ 
	int whichLine = 0;
	int smallest = lines[0].size();

	for( int i = 0; i < lineCount; i++ )
	{
		if( lines[i].size() < smallest )
		{
			smallest = lines[i].size();
			whichLine = i;
		}	
	}

	return whichLine;
}

//  -returns the index of the first line found with the least 
//   amount of work left to be done
int Factory::dispatcherU()
{ 
	int whichLine = 0;
	double smallest = lines[0].totLineWork();

	for( int i = 0; i < lineCount; i++ )
	{
		if( lines[i].totLineWork() <= smallest )
		{
			smallest = lines[i].totLineWork();
			whichLine = i;
		}	
	}

	return whichLine;
}

//	-returns the index of the first line found which should be 
// 	 finished first
//	-this is found by dividing the total work units left by the
//	 lines work rate
int Factory::dispatcherT()
{ 
	int whichLine = 0;
	double smallest = lines[0].totLineWork() / rates[0] ;

	for( int i = 0; i < lineCount; i++ )
	{
		if( lines[i].totLineWork() / rates[i] < smallest )
		{
			smallest = lines[i].totLineWork() / rates[i];
			whichLine = i;
		}	
	}

	return whichLine;
}
