/***********************************************************************/
/*                      IntList Implementation                         */
/***********************************************************************/

#include <iostream>

using namespace std;

#include "IntList.h"


/*
 * Representation of an IntList:  
 * A pointer to a struct with data and next fields.
 *
 * An empty list is represented as the NULL pointer.
 *
 */
struct IntListNode {
	int          data;
	IntListNode *next;
};


/*
 * Operations on IntLists:
 *
 */

IntList empty(void)
{
	return NULL;
}

bool isEmpty(IntList list)
{
	return list == NULL;
}

IntList prepend(int new_data, IntList list)
{
	IntListNode *p_node = new IntListNode;

	p_node->data = new_data;
	p_node->next = list;

	return p_node;
}

int head(IntList list)
{
	return list->data;
}

IntList tail(IntList list)
{
	return list->next;
}

/* 
 * Intended use:  my_list = deleteHead(my_list);
 * Could pass in pointer to IntList and side-effect caller's
 * variable.
 */
IntList deleteHead(IntList list)
{
	IntList rest = tail(list);
	list->next   = NULL;
	delete list;
	return rest;
}
