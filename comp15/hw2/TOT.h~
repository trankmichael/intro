#ifndef TOT_H
#define TOT_H

#include <iostream>
#include "Transcript.h"

using namespace std;

const int INIT_SIZE = 5;
const int RESIZE_FACTOR = 2;

class TOT
{
    public:
	TOT();
	TOT( Transcript* transcriptList, int listSize);
	//Function returns a point to a copy of student’s transcripts
	Transcript* getTranscriptCopy(string studentID);
	//function add a single Transcript to the system, returns bool if it worked
	bool addTranscript(Transcript* t);
	void print();
	
    private:
	//dynamic array of pointers to Transcripts
	Transcript** transcripts;
	Transcript* lookUp(string sID);
	//expand dynamic array when it is full
	void expand();
	//count of how many currently stored
	int currentCount;
	//capacity of the dynamic array
	int currentCapacity;
	
};

#endif