#include <iostream>

using namespace std;

/*
 * nam_selsort.cpp - selection sort with count of swaps and compares
 *
 * purpose:	see how count of swaps and comps depends on
 *		a) order of input data
 *		b) size of data set
 *
 * written by: Michael Tran
 * on    date: March 27, 2013
 */

const int SIZE = 50000;

struct Person {
        int    year;
        string name;
};

int read_in_data(Person array[], int space);
void name_sort  (Person array[], int len);
void print_array(Person array[], int len);
int locate_lowest(Person array[], int len, int start);
void swap_elements(Person array[], int pos1, int pos2);

int main() 
{
        Person person[SIZE];
        int    len = 0;

        len = read_in_data(person, SIZE);
        name_sort(person, len);
        print_array(person, len);

        return 0;
}

/*
 * read_in_data -- read in array of year, name from cin
 * args: array to read, maxlen
 * rets: number of items read
 * note: truncates input if space is filled, no error report
 * NEW!: stops at EOF, no sentinel needed
 */
int read_in_data(Person array[], int space)
{
        int  pos      = 0;
        bool finished = false;

        while ((pos < space) && (!finished)) {
                cin >> array[pos].year;
                if (cin.eof()) {
                        finished = true;
                } else {
                        cin >> array[pos].name;
                        pos++;
                }
        }
        return pos;
}

/*
 * name_sort -- sort an array structs on name
 *   args: array of structs, number of elements in array
 *   rets: nothing
 *   acts: a) Sorts the array using the selection sort algorithm
 *         b) At end, prints number of comparisons and number of swaps
 */
void name_sort(Person array[], int len) 
{
     int pos2;
  
     for ( int i = 0; i < len; i++ ){
	pos2 = locate_lowest( array, len, i );  
        swap_elements( array, i, pos2);
     }

}

// -------------------- WRITE TWO HELPER FUNCTIONS -----------------

// locate_lowest -- find index of lowest value in range
//   args: array of structs, start of range, end of range
//   rets: index of lowest item in range
//   note: if two with lowest, returns first one
int locate_lowest(Person array[], int len, int start)
{
    int index = 0; 
    string first;
    
    first = array[start].name;
    
    for ( int i = start; i < len ; i++ ){
	if( array[i].name < first ){
	   first = array[i].name;
	   index = i;
	}  
    }
  
    return index;
  
}


// swap_elements -- swap two elements in the array
//   args: array of structs, index of pos1, index of pos2
//   rets: nothing

void swap_elements(Person array[], int pos1, int pos2)
{
  int first_year;
  string first_name;
  int second_year;
  string second_name;
  
  first_name = array[pos2].name;
  first_year = array[pos2].year;
  second_name = array[pos1].name;
  second_year = array[pos1].year;
  
  array[pos1].name = first_name;
  array[pos1].year = first_year;
  array[pos2].name = second_name;
  array[pos2].year = second_year;
  
}


// -------------------- END OF HELPER FUNCTIONS --------------------

/*
 * print_array -- print the array to cout
 *  args: array of strings, number of elements to print
 *  rets: nothing
 *  acts: loops through array sending each item to cout
 */
void print_array(Person array[], int len) 
{
        int i;

        for (i = 0; i < len; i++) {
                cout << array[i].year << " " << array[i].name << endl;
        }
}
