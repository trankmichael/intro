#ifndef Semester_H
#define Semester_H

#include <iostream>
#include "Courses.h"

using namespace std;

class Semester
{
    
    public:
	Semester();
	Semester( Courses* listAdded, string termAdded, int yearAdded );
	void addCourse(  string courseID, string courseGrade );
	void addCourseList( Courses* listAdded );
	void print();
	Semester* copy();
	void set_term( string term );
	void set_year( int year );
// // 	Courses* get_list();
// // 	string get_term(); 
// // 	int get_year();
	
    private:
	Courses* list;
	string term; 
	int year;
	
};

#endif
	
