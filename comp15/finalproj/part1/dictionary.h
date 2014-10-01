#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <string>

using namespace std;
const int ALPH = 26;

struct Node{
    bool marker;	// true - if its the end of word
    string word;  	// stores the end of the word
    Node* child[ALPH];	// children alphabet
    char letter;	// stores the individual letter
};


class Dictionary{
    public:
    	// default constructor
		Dictionary();	

		// checks if the string is in the trie
		bool isPrefix( string s );

		// checks if the string is in the trie and 
		// it is a word
		bool isWord( string s );

		// inserts the string into the trie
		bool insert(string s );

    private:
    	// start of the trie
		Node* root;

		// converst character to int
		int charToInt( char c);

		// makes a new node 
		Node* newNode();

		// housekeeping word count
		int count;
};
