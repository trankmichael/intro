#include "Courses.h"

// Default Constructor
Courses::Courses()
{
    head = NULL;
    courseCount = 0;
}

// Overloaded Constructor
// Arguments: a course number string / a string letter Grade
//      Note: sets the course count
Courses::Courses( string newCourseNum, string newGrade )
{
    Course* nodeX = new Course;
    nodeX->courseNumber = newCourseNum;
    nodeX->grade = newGrade;  
    nodeX->next = NULL;
    head = nodeX;
    courseCount = 1;
}

//  Purpose: add a course to the front of the linked list
// Argument: a courseID string and a string letter grade
//     Note: increments courseCount
void Courses::addCourse( string newCourseNum, string newGrade)
{
    Course* nodeX = new Course;
    nodeX->courseNumber = newCourseNum;
    nodeX->grade = newGrade;
    nodeX->next = head;
    head = nodeX;
    courseCount++;
}

//  Purpose: copies the linked list - returns a pointer of type
//	     Courses 
// Argument: n/a
//     Note: runs by increminting through the original until NULL
//	     and making new Nodes in the copy
Courses* Courses::getCopy()
{
    Courses* copy = new Courses;
    Course* original = head;
    copy->head = new Course;
    Course* copyTemp = copy->head;
    
    
    for( int i = 0; original != NULL  ; i++ )
    {
	copyTemp->courseNumber = original->courseNumber;
	copyTemp->grade = original->grade;
	copyTemp->next = new Course;
	copyTemp = copyTemp->next;
	original = original->next;
    }
    
    copy->courseCount = courseCount;
    
    return copy;
}

//  Purpose: prints out the courses and grades
// Argument: n/a
//     Note: if it attempts to print an empty List e.g. a 
//	     a semester with no courses it prints "" but does
//	     not exit
void Courses::print()
{
    Course* temp = head;
    
    if( head == NULL ){
	cout << "";
    }
    
    else{
	for( int i = 0; i < courseCount ; i++ ){
	    cout << "      Course: " << temp->courseNumber << " " 
		 << temp->grade << endl;
	    temp = temp->next;
	}	
    }
    cout << endl;
    
}