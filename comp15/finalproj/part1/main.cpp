#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <string>
#include "dictionary.h"

using namespace std;


int main()
{
	string word;
	Dictionary* dict = new Dictionary;
	int i = 0;
	string words[500000];
	bool check = true;

	while( !cin.eof() )
	{
		cin >> word;
		if( !cin.eof() ){
			words[i] = word;
			dict->insert(word);
			i++;
		}
	}

	words[i] = "sldkjdsflksjd";
	dict->insert(words[i]);
	i++;

	for( int x = 0; x < i; x++ )
	{
		check = dict->isWord("sldkjdsflksjd");
		if( check == false)
		{
			cerr << " FUCKED UP 1: " << words[x] << endl;
		}
	}

	for( int x = 0; x < i; x++ )
	{
		check = dict->isPrefix("");
		if( check == false)
		{
			cerr << " FUCKED UP 2: " << words[x] << endl;
		}
	}


	cerr << dict->isWord("") << endl;

	cout << "Check: " << check << endl;	
	cout << "Real Count: " << i << endl;

}