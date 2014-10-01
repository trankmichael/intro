/*
  Tufts University
  Comp 15 HW 4
  Assembly Line Queue Dynamic Array Object Header File
  Due: November 12, 2013
*/



#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;
const int INITIAL_SIZE = 5;
const int EXPAND_FACTOR = 2; 


struct Package {
  string orderNbr;     // Package Id
  int units;           // number of work units at Arrival
  int timeArrived;     // time the package arrived
  double unitsWorked;  // how much the package has been worked
};


class AssemblyLine{

public:

  // Default Constructor
  AssemblyLine();  
  ~AssemblyLine();

  // Adds to the front of the line
  void enqueue(Package added);

  // does work on the first package 
  bool work( double workUnits );

  // removes the first package from the queue
  bool dequeueFront();

  // print function just for testing in main.cpp
  void print() const;

  // computes the number of packages in queue
  int size() const;

  // computes the amount of work left in a queue
  double totLineWork() const;

private:

  //capacity is size of array, not amount stored in list
  int capacity;

  // dynamic array of packages
  Package* packages;

  // checks if the queue is empty
  bool isEmpty() const; 

  // expands the assembly while keeping the old items
  void expandLine();

  // prints out the first element in the proper format
  void printFront() const;

  // variables which store the start and end of the queue
  int front;    // first package in the queue
  int back;     // first empty space in the queue 

};

#endif
