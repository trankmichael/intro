#ifndef INTLIST_H
#define  INTLIST_H

#include<iostream>

class intList{
    
    public:
	intList();
	intList( int ID );
	bool assignNewInt( int ID );
	void printFriendList();
	
    private:
	int intCount;
	int intCapacity;
	bool expandList();

};