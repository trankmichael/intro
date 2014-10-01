#include "Semester.h"
#include <cstdlib>

//Default Constructor
Semester::Semester(){
    list = NULL; 
    term = "";
    year = 0;
}

//Overloaded Constructor
//Arguments: a list of courses added, the Term name
//	     and the termYear
//     Note: it attaches a copy of the list to be added
//	     not the actual list	
Semester::Semester( Courses* listAdded, string termAdded, int yearAdded ){
    list = listAdded->getCopy();
    term = termAdded;
    year = yearAdded; 
}

//  Purpose: to add a course to the linked list in the semester
// Argument: a string courseId and a string grade
//     Note: calls the lists addCourse function to add
void Semester::addCourse( string courseID, string courseGrade )
{
    if( list == NULL ){
	list = new Courses( courseID, courseGrade );
    }
    
    else{
	list->addCourse( courseID, courseGrade );	
    }
    
}
//   Purpose: adds a whole list of courses to the Semester
//  Argument: a pointer the list to be added
//      Note: copies the list in this function
void Semester::addCourseList( Courses* listAdded )
{
    list = listAdded->getCopy();
}

//Print function
// very simple uses the Coursese member print function
void Semester::print(){
    cout << "  Term: " << term << endl;
    cout << "  Year: " << year << endl; 
    list->print();
}

/*  Purpose: copies the Semester and returns a pointer to the 
	   copy
     Note: uses the list copy */	   
Semester* Semester::copy(){
    Semester* temp = new Semester;
    
    temp->list = list->getCopy();
    temp->term = term;
    temp->year = year;
    
    return temp;
    
}
void Semester::set_term( string newTerm ){
    term = newTerm;
}

void Semester::set_year( int newYear ){
    year = newYear;
}

// Courses* Semester::get_list(){
//     return list;
// }
// 
// string Semester::get_term(){
//     return term;
// }
// 
// int Semester::get_year(){
//     return year;
// }