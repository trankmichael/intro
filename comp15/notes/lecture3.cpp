// 10q files to thank people
//

//rest just returns a pointer to the tail of 
//the list without the head
sequence* sequence::rest(){
 
// makes a new pointer called s which points to a new 
// sequence called mySQ
    sequence* s = new Sequence(mySQ[0]);
    concatenate(s);
    
    sequence* s2 = new Sequence(mySQ[0]);
    s2->concatenate(s);

    sequence* s3 = new Sequence;	//use this in homework
    s3->mySQ[0] = mySQ[0];		//something like this
    
 
    
}

//homework questions
//    -an empty sequence
//    -rest returns a pointer to a sequence that is empty
//    -you cannot return an empty character. there is no empty character
//     you must cerr << "cannot return a char from an empty sequence "
//     then exit(1);
//     you must return but you cannot return nothing
//     YOU CAN NEVER CALL FIRST ON AN EMPTY SEQUENCE [CONTRACT] PUT THIS
//     IN THE COMMENTS ABOVE THE FUNCTION. THIS IS THE FUNCTIONS CONTRACT

// to use exit(1); you must include <cstdlib> in the header file so you can
// use it in the implementation (.cpp file)

//// EMPTY SEQUENCES ARE JUST CONTAINERS THAT DONT CONTAIN ANYTHING
//// 


bool courselist::enroll( Student s )
{
    
    if ( currentEnrolled >= currentCapacity ) // for these cases you should always look at the
	{				      // opposite case to see if it is better	
	    expand();
	}
	
    cList[currentEnrolled] = s;
    currentEnrolled;
    return true;

}

// the new function is fucking slow dont loop it

void courselist::expand()
{
    
	Student* temp = new student[currentCapacity * 2];
	
	for ( int i = 0; i < currentEnrolled; i++)
	{
	    temp[i] = cList[i];
	}
	
	// live in the function die in the function
	// at end of the function the temp pointer is deleted anyway 
	
	delete[] clist;
	clist = temp;
	currentCapacity = currentCapacity * 2;
	
}

