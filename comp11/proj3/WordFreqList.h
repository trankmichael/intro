#ifndef __WORDFREQLIST_H__
#define __WORDFREQLIST_H__

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <stdexcept>
#include <string>







struct data {
    int freq;
    string word;
};

struct WordFreqListNode {
    data stored;
    WordFreqListNode *next;
};

typedef WordFreqListNode *WordFreqList;

WordFreqList 	 empty	   	(void);
bool    	 isEmpty	(WordFreqList list);
WordFreqList 	 prepend	(string new_word, int frequency, WordFreqList list);
data		 head	   	(WordFreqList list);
WordFreqList	 tail       	(WordFreqList list);
WordFreqList 	 deleteHead 	(WordFreqList list);
void	 	 insertAfter	(string new_word, int frequency, WordFreqList after);
void		 setFrequency	(int frequency, WordFreqList set);

#endif