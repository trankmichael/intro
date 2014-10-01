#include "WordFreqList.h"
#include <iostream>
#include <string>
using namespace std;

struct blue{
	yellow p;//to access x->p.word or .freq
	node next;
};

//returns empty list
node empty	 (void){
	return NULL;
}

//returns true for empty list
bool isEmpty	 (node list){
	return list == NULL;
}

//takes new word/freq pair and WordFreqList and returns pointer to new 
//non-empty node with pair stored in first element
node prepend	 (string new_word, int new_freq, node list){
	node p_node = new blue;

	p_node->p.word = new_word;
	p_node->p.freq = new_freq;
	p_node->next = list;

	return p_node;
}

//takes list and returns word/freq pair in list
yellow first	 (node list){
	return list->p;
}

//takes list and returns rest
node rest 	 (node list){
	return list->next;
}

//takes list deletes first node and returns rest
node deleteFirst (node list){
	node theRest = rest(list);
	list->next   = NULL;
	delete list;
	return theRest;
}

//takes list and word/freq pair and creates new non-empty list node first 
//element is pair and rest is rest of given list (updated to have new
//original start)
void insertAfter (node list, string new_word, int new_freq){
	node new_node = new blue;
	new_node->p.word = new_word;
	new_node->p.freq = new_freq;
	new_node->next = rest(list);
	list->next = new_node;
}

//takes list and integer and updates frequency stored in given list node
//returns nothing
void set_freq	 (node list, int new_freq){
	if(list != NULL){
		list->p.freq = new_freq;
	}
}

