// COMP 15 HW 2
//  Revised On: October 4, 2013
// Description: uses three objects to handle a set of transcripts
//	        representing student courses and grades
// TUFTS UNIVERSITY

#include "TOT.h"
#include <iostream>


using namespace std;

int main()
{
    // -------------------------------------------------------    
    //
    //	TESTING FOR COURSES OBJECT 
    //
    // -------------------------------------------------------
    Courses* testCourseListSem1 = new Courses;
    testCourseListSem1->addCourse("COMP40" , "F" );
    testCourseListSem1->addCourse("ECON05" , "A-" );
    testCourseListSem1->addCourse("MATH61" , "B+" );
    
    Courses* testCourseListSem2 = new Courses( "COMP15" , "A" );
    testCourseListSem2->addCourse("COMP40" , "F" );
    testCourseListSem2->addCourse("ECON05" , "A-" );
    testCourseListSem2->addCourse("MATH61" , "B+" );
    
    Courses* testCourseListSem3 = new Courses( "ECON62" , "B+" );
    testCourseListSem3->addCourse("COMP11" , "B" );
    testCourseListSem3->addCourse("CHEM01" , "C" );
    testCourseListSem3->addCourse("MATH82" , "C+" );
    
    Courses* testCourseListSem4 = new Courses( "MATH36" , "C-" );
    testCourseListSem4->addCourse("COMP160" , "D-" );
    testCourseListSem4->addCourse("CHEM25" , "B+" );
    testCourseListSem4->addCourse("MATH34" , "B+" );
    
    Courses* testCourseListSem5 = new Courses( "ECON60" , "B" );
    testCourseListSem5->addCourse("COMP25" , "A+" );
    testCourseListSem5->addCourse("CHEM13" , "B-" );
    testCourseListSem5->addCourse("MATH71" , "C+" );

    
    Courses* testCourseListSem6 = new Courses( "ECON11" , "B" );
    testCourseListSem6->addCourse("COMP30" , "A" );
    testCourseListSem6->addCourse("CHEM02" , "C" );
    testCourseListSem6->addCourse("MATH34" , "C+" );

    
    Courses* testCourseListSem7 = new Courses( "ECON60" , "B" );
    testCourseListSem7->addCourse("COMP11" , "A" );
    testCourseListSem7->addCourse("CHEM01" , "C" );
    testCourseListSem7->addCourse("MATH34" , "C+" );
    
    Courses* testCourseListSem8 = new Courses( "ECON60" , "B" );
    testCourseListSem8->addCourse("COMP11" , "A" );
    testCourseListSem8->addCourse("CHEM01" , "C" );
    testCourseListSem8->addCourse("MATH34" , "C+" );
    
    Courses* testCourseListSem9 = new Courses( "ECON60" , "B" );
    testCourseListSem9->addCourse("COMP11" , "A" );
    testCourseListSem9->addCourse("CHEM01" , "C" );
    testCourseListSem9->addCourse("MATH34" , "C+" );
    
    Courses* testCourseListSem10 = new Courses( "ECON60" , "B" ); 
    testCourseListSem10->addCourse("COMP11" , "A" );
    testCourseListSem10->addCourse("CHEM01" , "C" );
    testCourseListSem10->addCourse("MATH34" , "C+" );
    
    Courses* testCourseListSem11 = new Courses( "COMP15" , "A" );
    testCourseListSem11->addCourse("COMP40" , "F" );
    testCourseListSem11->addCourse("ECON05" , "A-" );
    testCourseListSem11->addCourse("MATH61" , "B+" );
    
    Courses* testCourseListSem12= new Courses( "ECON62" , "B+" );
    testCourseListSem12->addCourse("COMP11" , "B" );
    testCourseListSem12->addCourse("CHEM01" , "C" );
    testCourseListSem12->addCourse("MATH82" , "C+" );
    
    Courses* testCourseListSem13 = new Courses( "MATH36" , "C-" );
    testCourseListSem13->addCourse("COMP160" , "D-" );
    testCourseListSem13->addCourse("CHEM25" , "B+" );
    testCourseListSem13->addCourse("MATH34" , "B+" );
    
    Courses* testCourseListSem14 = new Courses( "ECON60" , "B" );
    testCourseListSem14->addCourse("COMP25" , "A+" );
    testCourseListSem14->addCourse("CHEM13" , "B-" );
    testCourseListSem14->addCourse("MATH71" , "C+" );
    
    Courses* testCourseListSem15 = new Courses( "ECON11" , "B" );
    testCourseListSem15->addCourse("COMP30" , "A" );
    testCourseListSem15->addCourse("CHEM02" , "C" );
    testCourseListSem15->addCourse("MATH34" , "C+" );
    
    Courses* testCourseListSem16 = new Courses( "ECON60" , "B" );
    testCourseListSem16->addCourse("COMP11" , "A" );
    testCourseListSem16->addCourse("CHEM01" , "C" );
    testCourseListSem16->addCourse("MATH34" , "C+" );
    
    Courses* testCourseListSem17 = new Courses( "ECON60" , "B" );
    testCourseListSem17->addCourse("COMP11" , "A" );
    testCourseListSem17->addCourse("CHEM01" , "C" );
    testCourseListSem17->addCourse("MATH34" , "C+" );
    
    Courses* testCourseListSem18 = new Courses( "ECON60" , "B" );
    testCourseListSem18->addCourse("COMP11" , "A" );
    testCourseListSem18->addCourse("CHEM01" , "C" );
    testCourseListSem18->addCourse("MATH34" , "C+" );
    
    Courses* testCourseListSem19 = new Courses( "ECON60" , "B" ); 
    testCourseListSem19->addCourse("COMP11" , "A" );
    testCourseListSem19->addCourse("CHEM01" , "C" );
    testCourseListSem19->addCourse("MATH34" , "C+" );

    cout << " END OF ADDING TO COURSES ~~~~ "<< endl;

    // -------------------------------------------------------    
    //	TESTING FOR SEMESTER OBJECT 
    // ( CREATING 18 SEMESTERS by the overloaded constructor )
    //  + one semester by adding a whole list
    //  + one semester by adding each course 
    // -------------------------------------------------------
    Semester* testSem1 = new Semester( testCourseListSem1, "FALL", 2000 );
    testSem1->print();
    Semester* testSem2 = new Semester( testCourseListSem2, "SPRING", 2001 );
    testSem2->print();
    Semester* testSem3 = new Semester( testCourseListSem3, "FALL", 2001 );
    testSem3->print();
    Semester* testSem4 = new Semester( testCourseListSem4, "SPRING", 2002 );
    testSem4->print();
    Semester* testSem5 = new Semester( testCourseListSem5, "FALL", 2002 );
    testSem5->print();
    Semester* testSem6 = new Semester( testCourseListSem6, "SPRING", 2003 );
    testSem6->print();
    Semester* testSem7 = new Semester( testCourseListSem7, "FALL", 2003 );
    testSem7->print();
    Semester* testSem8 = new Semester( testCourseListSem8, "SPRING", 2004 );
    testSem8->print();
    Semester* testSem9 = new Semester( testCourseListSem9, "FALL", 2004 );
    testSem9->print();
    Semester* testSemA = new Semester( testCourseListSem10, "SPRING", 2005 );
    testSemA->print();
    Semester* testSemB = new Semester( testCourseListSem11, "FALL", 2005 );
    testSemB->print();
    Semester* testSemC = new Semester( testCourseListSem12, "SPRING", 2006 );
    testSemC->print();
    Semester* testSemD = new Semester( testCourseListSem13, "FALL", 2006 );
    testSemD->print();
    Semester* testSemE = new Semester( testCourseListSem14, "SPRING", 2007 );
    testSemE->print();
    Semester* testSemF = new Semester( testCourseListSem15, "FALL", 2007 );
    testSemF->print();
    Semester* testSemG = new Semester( testCourseListSem16, "SPRING", 2008 );
    testSemG->print();
    Semester* testSemH = new Semester( testCourseListSem17, "FALL", 2009 );
    testSemH->print();
    Semester* testSemI = new Semester( testCourseListSem18, "SPRING", 2010 );
    testSemI->print();
    
    //Testing Semester by default constructer and adding a
    //whole list ( PLEASE MANUALLY SET YEAR AND TERM ) 
    Semester* testSemList = new Semester();
    testSemList->addCourseList( testCourseListSem19 );
    testSemList->set_term("FALL");
    testSemList->set_year(2010);
    testSemList->print();
    
    
    //Testing Semester by default constructor and adding
    //each individual course ( PLEASE MANUALLY SET YEAR AND TERM ) 
    Semester* testSemIndi = new Semester();
    testSemIndi->addCourse( "MATH17", "A+" );
    testSemIndi->addCourse( "MATH19", "A" );
    testSemIndi->addCourse( "MATH20", "A-" );
    testSemIndi->addCourse( "MATH21", "B+" );
    testSemIndi->set_term("SPRING");
    testSemIndi->set_year(2011);
    testSemIndi->print();
    
    
    cout << " END OF ADDING TO SEMESTERS ~~~~~~ " << endl;
    
    // -------------------------------------------------------    
    //
    //	TESTING FOR TRANSCRIPT OBJECT 
    //
    // -------------------------------------------------------
    Transcript* testTran = new Transcript( "PATTY", testSem1 );
    testTran->addSemester( testSem2 );
    testTran->addSemester( testSem3 );
    testTran->addSemester( testSem4 );
    testTran->addSemester( testSem5 );
    testTran->addSemester( testSem6 );
    testTran->addSemester( testSem7 );
    testTran->addSemester( testSem8 );
    testTran->addSemester( testSem9 );
    testTran->addSemester( testSemA );
    testTran->addSemester( testSemB );
    testTran->addSemester( testSemC );
    testTran->addSemester( testSemD );
    testTran->print();
    
    // MANUALLY ASSIGN STUDENT ID 
    Transcript* testTran1 = new Transcript;
    testTran1->setStudentID("JOSEPHINE");
    testTran1->addSemester( testSem2 );
    testTran1->addSemester( testSem3 );
    testTran1->addSemester( testSem4 );
    testTran1->addSemester( testSem5 );
    testTran1->addSemester( testSem6 );
    testTran1->addSemester( testSem7 );
    testTran1->addSemester( testSem8 );
    testTran1->addSemester( testSem9 );
    testTran1->addSemester( testSemA );
    testTran1->addSemester( testSemB );
    testTran1->addSemester( testSemC );
    testTran1->addSemester( testSemD );
    testTran1->print();
    
    cout << " END OF ADDING TO TRANSCRIPTS ~~~~~~ " << endl;
    // -------------------------------------------------------    
    //
    //	TESTING FOR TOT OBJECT 
    //
    // -------------------------------------------------------
    
    TOT* testTOT = new TOT;
    testTOT->addTranscript( testTran );
    testTOT->addTranscript( testTran );
    testTOT->addTranscript( testTran );
    testTOT->addTranscript( testTran );
    testTOT->addTranscript( testTran );
    testTOT->addTranscript( testTran ); // FORCING TO EXPAND TOT
    testTOT->addTranscript( testTran );
    testTOT->addTranscript( testTran );
    testTOT->addTranscript( testTran );
    testTOT->addTranscript( testTran );
    testTOT->addTranscript( testTran1 );
    testTOT->print();
    
    testTOT->getTranscriptCopy("JOSEPHINE")->print();
}