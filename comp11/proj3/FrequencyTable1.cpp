#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "FrequencyTable1.h"
#include "WordFreqList.h"

// Purpose: constructs an empty list
// Arguments: n/a
// Returns: n/a
FrequencyTable::FrequencyTable(){
    table = empty();
}

// Purpose: determines if a word is already
//	    in the linked list
// Arguments: string word being looked for
// Returns: bool - true if the word is found
//               - false if the word is not
bool FrequencyTable::in(string word){

    WordFreqListNode *p_node;
       
    p_node = table;
    
    while( !isEmpty(p_node) ){
	if (head(p_node).word == word){
	    return true;
	}
	else{
	   p_node = tail(p_node);
	}
    }
    return false;

}

// Purpose: inserts a string into a node in the
//          linked list in alphabetical order
// Arguments: string - word to be inserted
// Returns: n/a
// Note: handles three different cases
//           -the list is empty
//	     -the word is in the list
//           -the word is not in the list
void FrequencyTable::insert(string word){
    
    WordFreqListNode *p_node;
    p_node = table;
    int newfreq;

    if( in(word) ){
	while( !isEmpty(p_node) ){
	    if ( head(p_node).word == word ){ 
		newfreq = head(p_node).freq + 1;
		setFrequency( newfreq,p_node);
		return;
	    }
	    else{		 
		p_node = tail(p_node);			
	    }
	}
    }
    else if ( isEmpty(table) ){
	table = prepend( word, 1, table );    
    }
    else if ( !in(word) ){
	insAlphabetic(word);
    }

}

// Purpose: determenines the frequency of a word
// Arguments: string word whos frequency is being found
// Returns: int - frequency of the word
// Note: I did not find this function necessary
//       For the get function I was able to get the freq
//       and word at the same time from each node of the
//       list
int FrequencyTable::frequency(string word){
    
    WordFreqListNode *p_node;
    p_node = table;
    
    if( !in(word) ){
	return 0;
    }
    else{
	while( !isEmpty(p_node) ){ 
	    if( head(p_node).word == word ){
		return head(p_node).freq;
	    }
	    else{
		p_node = tail(p_node);
	    }
	}
    }
    return 0;

}
// Purpose: determines the size of the list of words
// Arguments: n/a
// Returns: int - how many nodes in the word
// Note: this was used to determine how many times the
//       get function should be called
int FrequencyTable::size(){
    int count = 0;
    
    WordFreqListNode *p_node;
    p_node = table;
    
    if( isEmpty(table) ){
	return 0;
    }
    while ( !isEmpty(p_node) ){
	p_node = tail(p_node);
	count++; 
   }

   return count; 
}

// Purpose: takes in two pointers and points them at the
//	    word and the frequency of a node in the list
// Arguments: int - which node to find
//            string pointer - to point at the word in
// 			       the node
//            int pointer - to point at the frequency in
//                          the node
// Returns: n/a
// Note: returns nothing, points at the two values in the
//		 struct
void FrequencyTable::get(int n, string *p_word, int *p_frequency){
 
    WordFreqListNode *p_node;
    p_node = table;
    
    for(int i = 1; i < n ; i++ ){
	p_node = tail(p_node);	
    }
    
    *p_word = head(p_node).word;
    *p_frequency = head(p_node).freq;

}


// Purpose: destroys the whole table
// Arguments: n/a
// Returns: n/a
void FrequencyTable::destroy(){
    while ( !isEmpty(table) ){
	table = deleteHead(table);
    }
}

// Purpose: to insert a word alphabetically in a list
// Arguments: string - word to be inserted
// Returns: n/a
// Note: called by the insert function
//       handles three cases:
//	   -the word belongs at the front of the list
//         -the word belongs at the end of the list
//         -the word belongs in the middle
void FrequencyTable::insAlphabetic(string word){
    WordFreqListNode *p_node, *p_node2;
    p_node = table;
    p_node2 = tail(table);
    
    while( !isEmpty(p_node) ){
       
	if( isEmpty(p_node2) && word > head(p_node).word ){
	    insertAfter( word, 1, p_node );
	    return;
	}
	else if(  word < head(p_node).word ){
	    table = prepend( word, 1, table );
	    return;
	}
	else if(( head(p_node).word < word ) && ( head(p_node2).word > word )){	             		
            insertAfter( word, 1, p_node );
	    return;
	}
	else{
	    p_node = p_node2;
	    p_node2 = tail(p_node2);
	}
    }
    
}
