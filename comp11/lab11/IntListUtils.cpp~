/***********************************************************************/
/*                          IntList Utilities                          */
/***********************************************************************/

#include <iostream>

using std::cout;

#include "IntList.h"


/*
 * Can use a while or for loop. 
 */
void print(IntList list)
{
    cout << "[";
    while(!isEmpty(list)){
	cout << head(list);
	deleteHead(list);
	if(!isEmpty){
	    cout << ", ";
	}
    }
    cout << "]";
}

// 	4 ~> 3 ~> ()
void printArtistically(IntList list)
{
    while(!isEmpty(list)){
	cout << head(list);
	deleteHead(list);
	cout << " ~> ";
    }
    cout << "()";
}

int sumList(IntList list)
{
    int sum = 0;
    
    while(!isEmpty(list)){
	sum = sum + head(list);
	deleteHead(list);
    }
    return sum;
}

int length(IntList list)
{
    int count = 0;
    
    while(!isEmpty(list)){
	count++;
	deleteHead(list);
    }
    return count;
}

IntList copy(IntList list)
{
    IntList copy;
    IntList copy2;
    
    while(!isEmpty(list)){
	copy = prepend( head(list) , copy )
	deleteHead(list);
    }
    while(!isEmpty(copy)){
	copy2 = prepend( head(copy) , copy2 )
	deleteHead(copy);
    }
    return copy2;
}

IntList mapIncrement(IntList list)
{
    while(!isEmpty(list)){
	copy = prepend( head(list) + 1 , copy )
	deleteHead(list);
    }
    while(!isEmpty(copy)){
	copy2 = prepend( head(copy) + 1, copy2 )
	deleteHead(copy);
    }
    return copy2;
    
}

IntList mapIncrementBy(IntList list, int increment)
{
    while(!isEmpty(list)){
	copy = prepend( head(list) + increment , copy )
	deleteHead(list);
    }
    while(!isEmpty(copy)){
	copy2 = prepend( head(copy) + increment , copy2 )
	deleteHead(copy);
    }
    return copy2;
}

IntList sum(IntList list1, IntList list2)
{
	// STUB
	return empty();
}

IntList filterPositive(IntList list)
{
	// STUB
	return empty();
}

IntList range(int lo, int hi)
{
	// STUB
	return empty();
}

void deleteList(IntList *p_list)
{
	// STUB
}
