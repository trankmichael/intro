//
// temps.cpp -- a program to analyze temperatures for a month over years
//

#include <iostream>
using namespace std;

const int MAXYEARS = 200;
const int MAXDAYS  = 31;
const int NODATA   = -9999;          // from the ornl.gov datafile
const int NUMCOLS  = MAXDAYS + 1;    // spot 0 for the year; 1 for 1st, ..
const int SENTINEL = -1;
const int TODAY    = 16;
const int MY_YEAR  = 2013;           // set to year you were born

bool read_in_data(int [][NUMCOLS]);
void analyze     (int data[][NUMCOLS]);

int main() 
{
        int temps[MAXYEARS][NUMCOLS];

        if (read_in_data(temps) == false) {
                cout << "too much data" << endl;
                return 1;
        }
        analyze(temps);

        return 0;
}

//
// read_in_data
//   purp: read in month data for several years, store in array
//   args: array with space for MAXYEARS rows and NUMCOLS cols
//   rets: true if read in data ok, false if out of space
//   note: copies data into array, includes sentinel at end
//   note: each row begins with year month type where type is a string
//         then MAXDAYS worth of ints
//

bool read_in_data(int data[][NUMCOLS]) 
{
        int year, month;
        string type;
        int row = 0;
        int value;

        do {
                cin >> year;
                if (row >= MAXYEARS)           // check for overflow
                        return false;
                data[row][0] = year;           // put year in array

                if (year != SENTINEL) {
                        cin >> month >> type;  // read and ignore for now
                        for (int day = 1; day <= MAXDAYS; day++) {
                                cin >> data[row][day];
                        }
                        row++;
                }
        } while (year != SENTINEL);
        return true;
}

int    find_max_temp_all        (int t[][NUMCOLS]);
void   print_days_this_hot      (int t[][NUMCOLS], int temp);
int    find_max_temp_for_day    (int t[][NUMCOLS], int day);
double find_avg_temp_all        (int t[][NUMCOLS]);
double find_avg_temp_for_year   (int t[][NUMCOLS], int year);
double find_avg_temp_for_day    (int t[][NUMCOLS], int day);
int    find_year_of_hottest_oct (int t[][NUMCOLS]);
int    find_day_with_highest_avg(int t[][NUMCOLS]);

// analyze -- run the various data analysis functions

void analyze(int data[][NUMCOLS])
{
        int    highest_temp;
        double avg_high;
        int    hottest_year, hottest_day;

        highest_temp = find_max_temp_all(data);            // [1]
        cout << "         The highest Oct temp is: " << highest_temp << endl;

        cout << "    This temperature happened on: ";
        print_days_this_hot(data, highest_temp);           // [2]
        cout << endl;

        highest_temp = find_max_temp_for_day(data, 31);    // [3]
        cout << "   Highest temp on Halloween was: " << highest_temp << endl;

        highest_temp = find_max_temp_for_day(data, TODAY); // [4]
        cout << "Highest temp on Oct " << TODAY << " was: "
             << highest_temp << endl;

        avg_high = find_avg_temp_all(data);                // [5]
        cout << "        Average Oct high temp is: " << avg_high << endl;

        avg_high = find_avg_temp_for_year(data, MY_YEAR);  // [6]
        cout << "       Avg Oct high temp in " << MY_YEAR << ": "
             << avg_high << endl;

        avg_high = find_avg_temp_for_day(data, TODAY);     // [7]
        cout << "        Avg high temp for Oct " << TODAY << ": "
             << avg_high << endl;

        hottest_year = find_year_of_hottest_oct(data);     // [8]
        cout << "         Hottest Oct was in year: " << hottest_year << endl;

        hottest_day = find_day_with_highest_avg(data);     // [9]
        cout << "         Hottest date in Oct is : " << hottest_day << endl;
}

int find_max_temp_all(int t[][NUMCOLS])
{
  int row = 0;
  int i;
  int maxTemp = NODATA;
  int comparedTemp;
  
  do {
    
    for ( int n = 1; n <= MAXDAYS; n++ ){
	
      comparedTemp = t[row][n];
      
      if ( comparedTemp > maxTemp ) {
	
	    maxTemp = comparedTemp;	
	
      }
      
    }
    
    
    row ++;
    i = t[row][0];  
    
  }while (  i != SENTINEL );
  
  return maxTemp;
  
}

// search the table for days that have temperature temp
// print out the year, month and date for each matching element

void print_days_this_hot(int t[][NUMCOLS], int temp)
{
  int row = 0;
  int i;
  int tempOnDay;
  
  do {
    
    for ( int n = 1; n <= MAXDAYS; n++ ){
      
      tempOnDay = t[row][n];
      
      if ( tempOnDay == temp ){
      
	cout << t[row][0] << " October " << n;
	
      }
    }
    
    row++;
    i = t[row][0];
    
  }while ( i != SENTINEL );
  
}

int find_max_temp_for_day(int t[][NUMCOLS], int day)
{
  int row = 0; 
  int i;
  int maxTemp = NODATA;
  int tempOnDay;
  
  do { 
    
    for ( int n = 1; n <= MAXDAYS; n++ ){
      
      if ( n == day ){
	
	tempOnDay = t[row][n];
	
	if ( tempOnDay > maxTemp ){
	 
	  maxTemp = tempOnDay;
	}
	
     }
    }
	   
    row++;
    i = t[row][0];
    
  }while ( i != SENTINEL );
 
  return maxTemp;
  
}

double find_avg_temp_all(int t[][NUMCOLS])
{
  int row = 0; 
  int i;
  int maxTemp = NODATA;
  int tempOnDay;
  int avgTemp;
  int count = 0;
  
  do { 
    
  
	   
    row++;
    i = t[row][0];
    
  }while ( i != SENTINEL );
 
  avgTemp = totalTemp / count 
  return avgTemp;
  
}

double find_avg_temp_for_year(int t[][NUMCOLS], int year)
{
}

double find_avg_temp_for_day(int t[][NUMCOLS], int day)
{
}

int find_year_of_hottest_oct(int t[][NUMCOLS])
{
}

int find_day_with_highest_avg(int t[][NUMCOLS])
{
}
