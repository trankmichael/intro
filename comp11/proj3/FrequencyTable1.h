#include "WordFreqList.h"


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
	WordFreqList table;
	void insAlphabetic( string word );
	
};
