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
		Factory( int LineNumber, double* ratesIn );
		
		~Factory();

		// Simulates a factory run
		int run();

	private:
		// reads in the input file and stores the important data
		void readin();

		// the work step in the assembly line of the factory 
		void work();

		int dispatcherP();
		int dispatcherU();
		int dispatcherT();

		// expand the number of packages held in the factory 
		void expand();

		// array of packages to be added to the assembly line
		Package* packages; 
		
		// assembly line where work is done
		AssemblyLine* lines;

		// number of packages the factory can store
		int capacity;

		int lineCount;
		double* rates;

		// number of packages that arrived to the factory 
		int nbrPackages;
};

#endif
