#include "hookbook.h"

HookBook::HookBook()
{
    hbook = new Pirate[INIT_CAPACITY];
    currentCapacity = INIT_CAPACITY;
    pirateCount = 0;
}


    /* Adds a new pirate to HookBook, probably the member should
       be created by the hookbook system, for now it is sent in
       from main, friends is a pointer to a dynamic array we
       copy it to the hookbook data structure, if it is null the pirate
       has no friend*/
    
bool HookBook::addPirate(int member, string nm)
{
    //check to see if we need to expand to add
    if(pirateCount >= currentCapacity)
    {
            // check to see if expand worked
            if(!expandPirates())
            {
                return false;
            }
    }
    //made it here so we can add a pirate
    hbook[pirateCount].memberID = member;
    hbook[pirateCount].name = nm;
    hbook[pirateCount].friendList = NULL;
    hbook[pirateCount].friendCount = 0;
    hbook[pirateCount].friendCapacity = 0;
    pirateCount++;
    return true;
    
    
}

    /* Prints the values in the list in ascending order. */
    /* This method is "const", which is a promise to the compiler
     that it won't change the value of any private variables. */
void HookBook::print() const
{
    cout << "There are " << pirateCount << " pirates in the system." << endl;
    for (int i = 0; i < pirateCount; i++) {
        cout << "Pirate: " << hbook[i].name << " with memberID: "
             << hbook[i].memberID << " has friends ";
        
        for(int j = 0; j < hbook[i].friendCount; j++)
        {
            cout << hbook[i].friendList[j] << " ";
        }
        
        cout << endl;
        
    }
}

    
 
//the function you will write you may have an empty list to start
bool HookBook::addFriend(int mem, int friendID)
{
    
    int whichPirate, arraySpot;
    
    // finds the pirate
    for( int i = 0; i < pirateCount; i++ ){
	if( hbook[i].memberID == mem ){
	    whichPirate = i;
	}
    }
    
    // finds the spot to add the new friend
    arraySpot = hbook[whichPirate].friendCount;

    // if the friend count is equal to or greater than friend capacity
    if( hbook[whichPirate].friendCount >= hbook[whichPirate].friendCapacity ){
	
	if( hbook[whichPirate].friendCapacity == 0 )
	{   
	    int* temp = new int[2];
	    temp[0] = friendID;
	    delete[] hbook[whichPirate].friendList;
	    hbook[whichPirate].friendList = temp;
	    hbook[whichPirate].friendCapacity = 2;
	    return true;
	}
	else{
	    expandFriends( whichPirate );
	    hbook[whichPirate].friendList[arraySpot] = friendID;
	    return true;
	}
    }
    
    hbook[whichPirate].friendList[arraySpot] = friendID;
    return true;
    


	

}
    
/* destructor if you have time*/
HookBook::~HookBook()
{
    
}

bool HookBook::expandFriends( int whichPirate )
{
    int newSize;
    

	
    newSize = hbook[whichPirate].friendCapacity * 2 ;
    int* temp = new int[newSize];
	
	
	
    for( int i = 0; i < hbook[whichPirate].friendCount - 1 ; i++ ){
	temp[i] = hbook[whichPirate].friendList[i];
	delete[] hbook[whichPirate].friendList;
	hbook[whichPirate].friendList = temp;
	hbook[whichPirate].friendCapacity = newSize;
    }

    
    
       
    
}

bool HookBook::expandPirates()
{
    Pirate* temp = new Pirate[currentCapacity*2];
    if(temp == NULL){
        return false;
    }
    for (int i = 0; i < pirateCount; i++) {
        temp[i]=hbook[i];
    }
    delete[] hbook;
    hbook = temp;
    currentCapacity = currentCapacity*2;
    return true;
}

