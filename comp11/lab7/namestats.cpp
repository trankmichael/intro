// namestats.cpp -- age stats by names
//   usage: namestats name < datafile-of-year-name
// 
//  result: find avg, then range of ages and frequency by age
//  history: revised 2012-10-23 added 'who' to show_freq

#include <iostream>
#include <cstdlib>

using namespace std;


struct Person {
    string name;
    int age;
};

const int MAXPEOPLE = 50000;
const int SENTINEL  = -1;
const int NOW       = 2013;

void    read_in_data(Person person[], int sentinel, int array_size);
string  get_name    ();
void	print_ages  (Person person[], int sentinel, string who);
void    do_stats    (Person person[], int sentinel, string who);
int	find_max    (Person person[], int sentinel, string name);
int	find_min    (Person person[], int sentinel, string name);
double	find_avg    (Person person[], int sentinel, string name);
void	show_freq   (Person person[], int sentinal, string name,
                     int min, int max);

int main()
{
	Person	people[MAXPEOPLE];
	string	name;

	read_in_data(people, SENTINEL, MAXPEOPLE);
	name = get_name();
	print_ages(people, SENTINEL, name);
	do_stats(people, SENTINEL, name);

	return 0;
}

// --- read_in_data ------------------------------------------------------
//  args: array of Person structs, sentinel, max space in array
//  rets: nothing
//  does: reads from cin a year and name, puts sentinel in array
//  errs: calls exit if out of space
//
void read_in_data(Person person[], int sentinel, int space)
{
	int	yr = -1;
	string	nm;
	int	pos = 0;

	do {
		cin >> yr >> nm ;
		
		if (pos >= space) {
		
			cerr << "Out of space\n";
			exit(1);
		}
		person[pos].name = nm;
		person[pos].age = NOW -  yr;
		pos++;	
	} while (nm != "DONE");
}

// --- get_name ----------------------------------------------------------
//  purp: read in one name from cin
//  args: none
//  rets: the name
string get_name()
{
  	string name;
    
	cin >> name;	        
        return name;
}

// --- print_ages -------------------------------------------------------
//  purp: print all ages for the specified name
//  args: an array of structs, the sentinel, the name to find
//  rets: nothing
//  does: prints report to cout
//
void print_ages(Person person[], int sentinel, string who)
{

    int yr;

    for ( int pos = 0 ; yr != sentinel ; pos++ ){

	if ( person[pos].name == who ){

	    cout << person[pos].age << endl;
	}
	yr = NOW - person[pos].age;
    }


}

// --- do_stats ----------------------------------------------------------
//  purp: compute and print avg, range AND freq for each age in range
//  args: an array of structs, the sentinel, the name to find
//  rets: nothing
//  does: prints report to cout
//
void do_stats(Person person[], int sentinel, string who)
{
	int	min, max;	// min and max age for 'who'
	double	avg;

	avg = find_avg(person, sentinel, who);
	min = find_min(person, sentinel, who);
	max = find_max(person, sentinel, who);
	cout << "average: " << avg << endl;
	cout << "range: "   << min << "-" << max << endl;
	show_freq(person, sentinel, who, min, max);
}

double find_avg(Person person[], int sent, string who)
{
        double sum = 0; 
	int yr;
	int count = 0;
	double average;
	
	for ( int pos = 0; yr != sent ; pos++ ){
	
	 if ( person[pos].name == who ){
	   
	   sum = sum + person[pos].age;
	   count++; 
	 }
	 
	 yr = NOW - person[pos].age;
	 
	}
	 
	 
	 average = sum / count; 
	 return average;
        
}

int find_min(Person person[], int sent, string who)
{
        int minAge = 1000;
	int yr;
	
	for ( int pos = 0; yr != sent ; pos++ ){
	
	 if ( (person[pos].name == who ) && ( person[pos].age <= minAge ) ){
	   
	   minAge = person[pos].age;
	   
	 }
	 
	 yr = NOW - person[pos].age;
	 
	}
	
	
        return minAge;
}

int find_max(Person person[], int sent, string who)
{
        int maxAge = 0;
	int yr;
	
	for ( int pos = 0; yr != sent ; pos++ ){
	
	 if ( (person[pos].name == who ) && ( person[pos].age >= maxAge ) ){
	   
	   maxAge = person[pos].age;
	   
	 }
	 
	 yr = NOW - person[pos].age;
	 
	}
	
	
        return maxAge;
}

void show_freq(Person person[], int sent, string who, int min, int max)
{
        // STUB
}
