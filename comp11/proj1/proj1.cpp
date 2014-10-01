#include <iostream>
#include <string>
#include <cstdlib>
//
// 	proj1.cpp
//	
//    Purpose: handles a concert hall
//    Edited by: Michael Tran
//    Edited on: 
//
using namespace std;

struct Seats {
    string name;
    string price;
    char row;
    int column;
} ;
 
const char maxRow        = 'N'; 
const int  maxColumns    =  20;					// there are 20 columns
const int  numberOfRows  =  14;					// there are 14 rows {a,b,...m,n}
const int  firstHiColumn =   5;
const int  lastHiColumn  =  16;
const char lastHiRow     = 'H';

void initialEmptyCustId(Seats seats[numberOfRows][maxColumns]);
void assignSeatNames(Seats seats[numberOfRows][maxColumns]);	//assigns both a letter for row {a,b...n} and an int {0,1...20} for column
void assignSeatPrices(Seats seats[numberOfRows][maxColumns]);
void printSeats(Seats seats[numberOfRows][maxColumns]);
void menu(Seats seats[numberOfRows][maxColumns] , string );
void requestSeats(Seats seats[numberOfRows][maxColumns] , string , int, string);
void hiSeats(Seats seats[numberOfRows][maxColumns] , string, int );
void anySeats(Seats seats[numberOfRows][maxColumns] , string, int);
void loSeats(Seats seats[numberOfRows][maxColumns] , string, int);

int main()
{
    Seats seats[numberOfRows][maxColumns];
    string request = "0";

    cerr << "before ieci" << endl;
   //  initialEmptyCustId( seats );
    cerr << "after ieci" << endl;
   // assignSeatNames( seats );   
    cerr << "after seatname" << endl;
   	

    cout << request;
        cerr << "before cin" << endl;		    //
	cin >> request;                        	    // <-------------- seg faults here
        cerr << "after cin" << endl;
    	if ( request == "QU" ){
	    cerr << "retrning" << endl;	
	    return 0;
	}	
    	else {
		cerr << "befroe menu" << endl;
		menu(seats , request);
		cerr << "after " << endl;
    	}
    

    return 0;

}

void assignSeatNames( Seats seats[numberOfRows][maxColumns] )
{
    int posC = 0;						//posC for position column
    char row = 'a';
    int column = 1;

    for ( int posR = 0; posR < numberOfRows ; posR++ ){        //posR for position row
					       		
	do{
	    seats[posR][posC].row = row;			//first goes through the array
	    seats[posR][posC].column = column;			//from left to right assigning
	    column++;						//int values for the columns
	    posC++;						//and char values for the rows
	}while ( posC < maxColumns );
	

	row++;							//goes to the next row
    }

	 
}

void assignSeatPrices( Seats seats[numberOfRows][maxColumns] )
{
    int posC = 0;
    
    for ( int posR = 0; posR < numberOfRows ; posR++ ){
     do{	
	if( seats[posR][posC].column < firstHiColumn ){
	  seats[posR][posC].price = "lo";
	}
	if( seats[posR][posC].column > lastHiColumn ){
	  seats[posR][posC].price = "hi";
	}
           posC++;
     }while ( posC < maxColumns );
    }
    
}

void printSeats( Seats seats[numberOfRows][maxColumns] )
{
    int posR = 0; 
    string name;
    cerr << "before loop" << endl;
    for ( int posC = 0; posC < maxColumns ; posC ++ ){
	do{
	    cerr << "before seats[][].name" << endl;
	    cout << seats[posR][posC].name;
	    posC++;
	}while ( posR < numberOfRows );
	cout << endl;
    }


}

void initialEmptyCustId( Seats seats[numberOfRows][maxColumns] )
{
  int posC = 0;
  string empty = "---";  

  cerr << "before for loop" << endl;
  for ( int posR = 0; posR < numberOfRows ; posR++ ){
      cerr << "after for loop" << endl;
     do{
	 cerr << "after do loop" << endl;
      seats[posR][posC].name = empty;
      cout << empty;
      posC++;
    }while ( posC < maxColumns );
 
  }
}

void menu( Seats seats[numberOfRows][maxColumns] , string request )
{
    std:string name;
    int partySize;
    string price = "0";

    cerr << "beginning of menu";
    if ( request == "CA" ){
	cin >> name;
    }
    cerr << "before PR";
    if ( request == "PR" ){
	printSeats( seats ); 
    }
    cerr << "before RQ";
    if ( request == "RQ" ){
	cin >> name >> partySize >> price;
	requestSeats( seats, name , partySize , price );
    }
 
}

void requestSeats( Seats seats[numberOfRows][maxColumns] , string name, int partySize, string price )
{
    if( price == "any" ){
	anySeats ( seats, name , partySize );
    }
    if( price == "hi" ){
	hiSeats ( seats, name, partySize );
    }
    if( price == "lo" ){

	loSeats ( seats, name, partySize );
    }

}

void hiSeats( Seats seats[numberOfRows][maxColumns] , string name, int partySize )
{
    int posC = 0;

    for ( int posR = 0 ; seats[numberOfRows][maxColumns].row <= lastHiRow ; posR ++ ){

	posC++;

    }

}

void loSeats ( Seats seats[numberOfRows][maxColumns] , string name, int partySize )
{
}

void anySeats ( Seats seats[numberOfRows][maxColumns] , string name, int partySize )
{
}
