#include "TOT.h"
#include <cstdlib>

TOT::TOT()
{
    transcripts = new Transcript*[INIT_SIZE];
    for( int i = 0; i < INIT_SIZE ; i++ ){
	transcripts[i] = NULL;
    }
    currentCapacity = INIT_SIZE;
    currentCount = 0;
    
    
}
// Overloaded Constructor
// Note: not used bc I could not figure out a way 
//       not to use the &
// Argument: an array of transcripts to be added, the //           number of transcripts being added
TOT::TOT( Transcript* transcriptList, int  listSize )
{
    transcripts = new Transcript*[INIT_SIZE];
    currentCapacity = INIT_SIZE;
	
    if( listSize > currentCapacity )
    {
	expand();
    }
	
    for( int i = 0; i < listSize; i++ ){
	addTranscript( &transcriptList[i] );
    }
    
}

// expansian of a dynamic array of pointers
// note: calls the copy function of transcript to 
//       deep copy 
void TOT::expand()
{
    Transcript** temp = new Transcript*[currentCapacity * RESIZE_FACTOR];
    
    for( int i = 0; i < currentCount; i++ ){
	temp[i] = transcripts[i]->copy();
    }
    
    delete[] transcripts;
    transcripts = temp;
    currentCapacity = currentCapacity * RESIZE_FACTOR;
}

//  Purpose: add a pointer of a copy of the given
//	     transcript to a space in the array
//     Note: checks if it needs to expand after the 
//           pointer of a copy is added
//           - returns true if successful
bool TOT::addTranscript( Transcript* t )
{
    transcripts[currentCount] = t->copy();
    currentCount++;
    
    if( currentCapacity == currentCount ){
	expand();
    }
    
    return true;
}

// Purpose: to lookup the transcript for a student
//	    -returns a pointer to a copy of their
//           transcript
// Argument: the students ID as a string
//     Note: there is no usual case where lookup 
//           is called on an ID not in the array
Transcript* TOT::lookUp(string sID)
{
    
    for( int i = 0; i < currentCount; i++ )
    {
	if( transcripts[i]->getStudentID() == sID ){
	    return transcripts[i];
	}
    }
    
    cerr << " ERROR: COULD NOT FIND STUDENT ID" << endl;
    exit(1);
}

//Print FUNCTION
// cerr statement if you try to print a null 
// transcript
void TOT::print()
{
    for(int i = 0; i < currentCount; i++)
    {
	if(transcripts[i] == NULL){
	    cerr << "NULL ";
	}
	transcripts[i]->print();
    }
}

Transcript* TOT::getTranscriptCopy( string studentID )
{
    return lookUp( studentID )->copy();    
}