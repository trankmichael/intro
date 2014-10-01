#ifndef INTLIST_H
#define  INTLIST_H

#include<iostream>


const int INIT_CAPACITY = 5;
const int EXPAND_FACTOR = 2;

class IntList{
    
    public:
	IntList();
	IntList( int ID );
	bool assignNewInt( int ID );
	void printIntList();
	
    private:
	int* ints;
	int count;
	int capacity;
	bool expandList();

};