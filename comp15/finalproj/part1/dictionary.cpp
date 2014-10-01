#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <string>
#include "dictionary.h"

// default constructor for the dictionary object
Dictionary::Dictionary()
{
    root = newNode();	  // calls the function to initialize each node
    count = 0;			  // sets a word count to zero
}

//checks if the string is in the tree
//	-the word marker is not required
//	-is the same as isWord, but without 
//	 marker check   
bool Dictionary::isPrefix( string s )
{
   Node* current = root;	// traverser pointer
   int length = s.size();	// checks the string size

	if( (root->marker == false) && (s == "") )
	{
		return false;
	}

	for( int i = 0; i < length; i++)	// increments through
	{									// each character in the string
		if( isalpha(s[i]) )				// checks if its a letter
		{
			char letter = tolower(s[i]);	// lowercases the letter
			int index = charToInt(letter);	// converts to the int for index
			if(current->child[index] == NULL )
			{								// if current reaches NULL before
				return false;				// the number of letters
			}								// has been reached returns false
			current = current->child[index];// goes next letter of the word
		}
	}
	return true; // returns true if successful finds the connected string
    
}

// isWord(string s)
// checks to see if the word is in the dictionary
//	-similar to isPrefix
bool Dictionary::isWord( string s )
{
	Node* current = root;		// sets a temp pointer to the root
	int length = s.size();		// gets the string length

	for( int i = 0; i < length; i++) // loops through each character 
	{
		if( isalpha(s[i]) )			 // checks if its alphabetical
		{
			char letter = tolower(s[i]);  	// changes the char to lower case
			int index = charToInt(letter);  // sets the index of the child
			if(current->child[index] == NULL )
			{						// if it ever reaches NULL without a
				return false;		// complete string it will return false
			}						//  -- the string is not present --
			current = current->child[index];	// moves the iterator
		}
	}
	return current->marker;			// at the end returns the word marker

}
 
// insert function
// adds word to the trie data structure
bool Dictionary::insert( string s)
{
    Node* current = root;	// gets a new temp pointer
    int length = s.size();	// string length counter

	current->marker = true; // handles the empty string is a word once anything
							// is added to the trie
    for( int i = 0; i < length; i++ )	//  loops through the string 
    {
    	if( isalpha( s[i] ) )	// if it is an alphabet character
    	{
    		char letter = tolower(s[i]);	// converts to lower
			int index = charToInt(letter);	// converts to int for index
    		if( current->child[index] == NULL )	// reaches a leaf on the trie
    		{
    			current->child[index] = newNode(); // adds a node to the trie
    			current->child[index]->letter = letter; // sets the letter to
    		}											// the word letter

    		current = current->child[index];	   // moves the iterator
    	}

    }
    count++;						// housekeeping count member
    current->marker = true;			// sets the leaf to true - its a word 
    current->word = s;				// stores the whole word on the node
    return true;					// returns true once successful
}

// new node initializer
// called in insert 
Node* Dictionary::newNode()
{
	Node* s = new Node;			// makes a new node
	s->marker = false;			// sets the marker to false
	s->word = "";				// initializes the blank string
	for( int i = 0; i < ALPH; i++ )	// loops through the alphabet
	{
		s->child[i] = NULL;		//sets each to null
	}

	return s;					// returns the new pointer
}

// converts the lower case character into an int
// used to find the index of each array
int Dictionary::charToInt(char c)
{
	return (c - 'a');
}

