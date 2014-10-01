#ifndef courses_H
#define courses_H

#include <iostream>
#include <cstdlib>
using namespace std;

struct Course{
    string courseNumber;
    string grade;
    Course* next;
};


class Courses
{
    public:
	Courses();
	Courses( string newCourseNum, string newGrade );	
	void addCourse( string newCourseNum, string newGrade);
	int getCourseCount();
	Courses* getCopy();
	void print();
    private:
	Course* head;
	int courseCount;
    
};

#endif