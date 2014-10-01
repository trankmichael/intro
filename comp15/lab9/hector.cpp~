#include <iostream>
#include <stdio.h>
#include "hector.h"

using namespace std;
//
// hector.cpp -- compare three different collision solutions
//
// your job: code the insert functions
//  our job: run the three insert functions and report results
//

// constructor
Hector::Hector()
{
	for(int i = 0; i < TSIZE; i++)
	{
		cheneyTable[i] = NULL;
		linnyTable[i] = -1;
		doublesTable[i] = -1;
	}
}


// linear probing
//
//  returns number of collisions before finding a spot
//
int Hector::linny(int value)
{
	int attempt = 0;
	int index;
	bool found = false;
	while(!found)
	{

	    index = ( 3 * value + 7 + attempt ) % TSIZE;
	    
	    if( linnyTable[index] == -1 )
	    {
		linnyTable[index] = value;
		found = true;
	    }
	    
	    attempt++;
	}
	
	attempt--;
	return attempt;
}

// double hashing using a second function
//  
//  returns number of collisions before finding a spot
//
int Hector::doubles(int value)
{
    int attempt = 0;
    int index;
    bool found = false;
    while(!found)
    {
	index = ( 3*value + 7 + attempt * ( 13-(value % 13 ))) % 17;
	
	if( doublesTable[index] == -1 )
	{
	    doublesTable[index] = value;
	    found = true;
	}
	
	attempt++;
    }
    
    attempt--;
    return attempt;
	
}

// chained hashing -- each spot in table is a linked list 
//
//  returns number of items in that spot before insertion
//
int Hector::cheney(int value)
{
    int attempt = 0;
    int index;
    Node* temp;
    
    index = ( 3 * value + 7) % TSIZE;
    temp = cheneyTable[index];
    while( temp != NULL )
    {
	attempt++;
	temp = temp->next;
    }
	
    cheneyTable[index] = new Node;
    cheneyTable[index]->key = value;
    cheneyTable[index]->next = NULL;
    
    return attempt;
}

// print the hash tables
void Hector::print()
{
	for(int i=0; i < TSIZE; i++)
	{
		cout << linnyTable[i] << " ";
		
	}
	
	cout << endl;
	
	for(int i=0; i < TSIZE; i++)
	{
		cout << doublesTable[i] << " ";
		
	}
	cout << endl;
	
	Node* iter = NULL;
	for(int i=0; i < TSIZE; i++)
	{
		iter = cheneyTable[i];
		cout << " [";
		while(iter != NULL)
		{
			cout << iter->key << " ";
			iter = iter->next;
		}
		cout << "]";
	}
	cout << endl;
}
