#include "WordFreqList.h"

const int alph = 26;

class FrequencyTable
{
    public:
	FrequencyTable();
	bool in(string word);
	void insert(string word);
	int frequency(string word);
	int size();
	void get(int n, string *p_word, int *p_frequency);
	void destroy();
    private:
	WordFreqList table[alph];
	void insAlphabetic( string word );
	int findArray( string word );	
};
