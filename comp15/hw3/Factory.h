/*
  Tufts University
  Comp 15 HW 3
  Factory Object Header File
  Due: October 22, 2013
*/



#ifndef FACTORY_H
#define FACTORY_H

#include "AssemblyLine.h"
#include <iostream>
#include <sstream>
#include <cstdlib>


class Factory{

	public:
		// Default constructor
		Factory();
		
		~Factory();

		// Simulates a factory run
		int run( int num_workers, double* rates );

	private:
		// reads in the input file and stores the important data
		void readin();

		// the work step in the assembly line of the factory 
		void work( int numWorkers, double* rates );

		// expand the number of packages held in the factory 
		void expand();

		// calculate the total amount of work that can be done 
		double workUnits( int numWorkers, double* rates) const;

		// array of packages to be added to the assembly line
		Package* packages; 
		
		// assembly line where work is done
		AssemblyLine* line;

		// number of packages the factory can store
		int capacity;

		// number of packages that arrived to the factory 
		int nbrPackages;
};

#endif
