#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

#include "WordFreqList.h"


// Purpose: constructs an empty WordFreqList
// Arguments: n/a
// Return: an empty Word
WordFreqList empty(){
    return NULL;
}

// Purpose: determines if the linked list is empty
// Arguments: a pointer to a list
// Returns: true - if it is empty
//	    false - if it is not empty
bool isEmpty(WordFreqList list){
    return list == NULL;
}

// Purpose: adds a new node at the beginning of the list 
//	    - gives the tail of the new node the old list
// Arguments: string to insert for the new nodes word
//            int to insert for the new nodes frequency
//            pointer to the linked list where the nodes added	      
// Returns: the new list
WordFreqList prepend( string new_word, int frequency, WordFreqList list){
    
    WordFreqListNode *p_node = new WordFreqListNode;
    
    p_node->stored.word = new_word;
    p_node->stored.freq = frequency;
    p_node->next = list;
    
    return p_node;
    
    
}

// Purpose: extracts the data struct in the given node
// Arguments: pointer to the node 
// Returns: struct of a word and an int
data head( WordFreqList list ){
    return list->stored;
}

// Purpose: finds out the pointer attached to a node
// Arguments: pointer to a node
// Returns: returns the pointer/tail of the node
WordFreqList tail( WordFreqList list ){
    return list->next;
}

// Purpose: removes the first node of a list by reassigning
//          its pointer to null
// Arguments: a pointer to the first node of the list
// Returns: returns the pointer to new list without the first
//          node
WordFreqList deleteHead( WordFreqList list ){
    WordFreqList rest = tail(list);
    list->next  = NULL;
    delete list;
    return rest;
}

// Purpose: inserts a new node in the middle of the linked list
// Arguments: string - new word to be inserted / int - new frequency for
//            the new node / pointer to the node that it should be after
// Returns: returns nothing just directly edits the linked list 
void insertAfter( string new_word, int frequency, WordFreqList after){
    WordFreqListNode *p_node = new WordFreqListNode;
    WordFreqListNode *temp;
	
    p_node->stored.word = new_word;
    p_node->stored.freq = frequency;
    temp = after->next;
    after->next = p_node;
    p_node->next = temp;
	
}

// Purpose: changes the value for the frequency of the node
// Arguments: int - new frequency / pointer to the edited node
// Returns: nothing just edits the struct in the node
void setFrequency( int frequency, WordFreqList list ){
    list->stored.freq = frequency;    
}
