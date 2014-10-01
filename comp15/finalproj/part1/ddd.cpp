#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <string>
#include "dictionary.h"

// default constructor for the dictionary object
Dictionary::Dictionary()
{
    root = new Node; 	  // initializes the root
    root->marker = false; // sets the root to be not a word initially
    root->word = "";	  // sets a blank string for word
    root->letter = "";	  // blank character for the letter member
    for( int i = 0; i < ALPH; i++ ){
		root->child[i] = NULL;		// initializes each spacen the child array
    }
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

	for( int i = 0; i < length; i++)	// increments through
	{									// each character in the string
		if( isalpha(s[i]) )				// checks if its a letter
		{
			char letter = tolower(s[i]);	// lowercases the letter
			int index = charToInt(letter);	// converts to the int for index
			if(current->child[index] == NULL )
			{								// if current reaches NULL before
				return false;				// the number of letters in the word
			}								// has been reached returns false
			current = current->child[index];// goes next letter of the word
		}
	}
	return true; // returns true if successful finds the connected string
    
}

Node* Dictionary::lastLetter( string s )
{

}
// print( Node* s, int t, char[] u )
// used mainly for testing
// - rescursive print function
// - prints all the words in the dictionary in alphabetical order
void Dictionary::print( Node* Root, int level, char[] segment )
{
	if( root == NULL )
	{
		return;
	}
	for ( int i = 0; i < ALPH; i++)
	{
branch[level] = root->
	}
}
   
// isWord(string s)
// checks to see if the word is in the dictionary
//	-similar to isPrefix
bool Dictionary::isWord( string s )
{
	Node* current = root;
	int length = s.size();

	for( int i = 0; i < length; i++)
	{
		if( isalpha(s[i]) )
		{
			char letter = tolower(s[i]);
			int index = charToInt(letter);
			if(current->child[index] == NULL )
			{
				return false;
			}
			current = current->child[index];
		}
	}
	return current->marker;

}
 
bool Dictionary::insert( string s)
{
    Node* current = root;
    int length = s.size();

    for( int i = 0; i < length; i++ )
    {
    	if( isalpha( s[i] ) )
    	{
    		char letter = tolower(s[i]);
			int index = charToInt(letter);
    		if( current->child[index] == NULL )
    		{
    			current->child[index] = newNode();
    			current->child[index]->letter = letter;
    		}

    		current = current->child[index];
    	}

    }
    count++;
    current->marker = true;
    current->word = s;
    return true;
}

Node* Dictionary::newNode()
{
	Node* s = new Node;
	s->marker = false;
	for( int i = 0; i < ALPH; i++ )
	{
		s->child[i] = NULL;
	}

	return s;

}

int Dictionary::charToInt(char c)
{
	return (c - 'a');
}

