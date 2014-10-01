#include "Transcript.h"

//Default Constructor
Transcript::Transcript()
{
    semList = new Semester*[INIT_SEM_SIZE];
    for( int i = 0; i < INIT_SEM_SIZE ; i++ ){
	semList[i] = NULL;
    }
    semCapacity = INIT_SEM_SIZE;
    semCount = 0;
    studentID = "";
    
}

//  OVERLOADED CONSTRUCTOR
// Argument: string StudentId pointer to a semester to be added
//     Note: sets all the private data according to one semester
//           element
Transcript::Transcript( string newStudentID, Semester* semestersAdded )
{
    studentID = newStudentID;
    semList = new Semester*[INIT_SEM_SIZE];
    for( int i = 0; i < INIT_SEM_SIZE ; i++ ){
	semList[i] = NULL;
    }
    semList[0] = semestersAdded->copy();
    semCapacity = INIT_SEM_SIZE;
    semCount = 1;
    
    
}
//  Purpose: add a semester to transcript
// Argument: a pointer to a semester to be added
//     Note: goes to the empty array element and assigns it the
//           pointer to a copy
//           - ater adding it checks if the array should be
//	       expanded 
void Transcript::addSemester( Semester* semestersAdded )
{
    semList[semCount] = semestersAdded->copy();
    semCount++;
    
    if ( semCount == semCapacity )
    {
	if( !expand() )
	{
	    exit(1);
	}
    }
    
}
// expansion of a dynamic array
bool Transcript::expand()
{
    Semester** temp = new Semester*[semCapacity * EXPAND_FACTOR];
    
    for( int i = 0; i < semCount; i++ ){
	temp[i] = semList[i]->copy();
    }
    
    delete[] semList;
    semList = temp; 
    semCapacity = semCapacity * EXPAND_FACTOR;
    return true;
}

// Purpose: to return a pointer to a copy of a transcript
//    Note: does this by using the copy function of semesters
//          which uses the copy function of list
Transcript* Transcript::copy()
{
    Transcript* temp = new Transcript;
    temp->semCount = semCount;
    temp->semCapacity = semCapacity;
    temp->studentID = studentID;
    
    for( int i = 0; i < semCount; i++ ){
	temp->semList[i] = semList[i]->copy();
    }
    
    return temp;
}

// Purpose: prints the transcript pretty
//    Note: uses the other print member functions of the other
//          objects
void Transcript::print()
{
    cout << "StudentID: " << studentID << endl;
    cout << "  Semesters: " << semCount << endl;
    for( int i = 0; i < semCount; i++ )
    {
	semList[i]->print();
    }

}


string Transcript::getStudentID()
{
    return studentID;
}

void Transcript::setStudentID( string newID )
{
    studentID = newID;
}

// int Transcript::getSemCount()
// {
//     return semCount;    
// }
// 
// void Transcript::setSemCount( int newCount )
// {
//     semCount = newCount;
// }

// int Transcript::getSemCapacity()
// {
//     return semCapacity;
// }
// 
// void Transcript::setSemCapacity( int newCapacity )
// {
//     semCapacity = newCapacity;
// }
// 