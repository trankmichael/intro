#ifndef TRANSCRIPTS_H
#define TRANSCRIPTS_H

#include <iostream>
#include "Semester.h"

using namespace std;

const int INIT_SEM_SIZE = 14;
const int EXPAND_FACTOR = 2;

class Transcript
{
    public:
	Transcript();
	Transcript( string newStudentID, Semester* semesterAdded );
	void addSemester( Semester* semestersAdded );
/*	int getNumSemester();
	void setSemCount( int newCount );
	int getSemCount();	
	int getSemCapacity();
	void setSemCapacity( int newCapacity );*/
	string getStudentID();
	void setStudentID( string newID );
	void print();
	Transcript* copy();
	
    private:
	Semester** semList;
	int semCapacity;
	int semCount;
	bool expand();
	string studentID;
	
};

#endif
