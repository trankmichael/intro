#include <iostream>
#include <cstdlib>
#include <string>
//
//  cts.cpp
// 	  Purpose: handles different requests for a 
//		   seating hall with different priced
//		   seats - includes discounds based on
//		   seating and saves names
// 	edited by: Michael Tran
// Last edited on: March 11, 2013
// 	      For: Comp11 - Tufts
//		   Project 1
using namespace std;

struct Seat {
    string name; 
    string price;
    int    col;
    char   row;
    double rev;
} ;

//===============================================================
//                    GLOBAL CONSTANTS
//===============================================================
const int totalRows   =    14;   // -  bounds of the whole seating
const int totalCols   =    20;   //    in the concert hall

const int lastLoCol   =     3;   // -  the bounds of the lo priced  
const int firstLoCol  =    16;   //    seats  

const int firstHiCol  =     4;	// -  refers to the bounds of the hi
const int lastHiCol   =    15;	//    priced seats using the array 
const int lastHiRow   =     7;	//    coordinates 7 = row 'H' 

const int hiPrice     =   200;   // -  premium ticket price
const int loPrice     =   150;   // -  regular ticket price

const string blankId  = "---";   // -  empty seat iD

const int exitLoop    =   100;   // - value to exit loops

const double discount =    .9;   // - seperate seating discount
//===============================================================
//                   FUNCTION DECLARATIONS
//===============================================================
void menu( Seat seats[][totalCols] , string );
void printSeats( Seat seats[][totalCols] );
void initialBlankName( Seat seats[][totalCols] );
void initialSeatId( Seat seats[][totalCols] );
void initialSeatPrices( Seat seats[][totalCols] );
bool checkAlreadyReserved( Seat seats[][totalCols] , string );
void requestErrors( Seat seats[][totalCols] );
void findHiSeats( Seat seats[][totalCols] , string , int );
void findLoSeats1( Seat seats[][totalCols] , string , int );
void findLoSeats2( Seat seats[][totalCols] , string , int );
void findLoSeats3( Seat seats[][totalCols] , string , int );
void findAnySeats( Seat seats[][totalCols] , string , int );
void findSpace( Seat seats[][totalCols] , string, int, string );
void assignSeat( Seat seats[][totalCols], string, int, int, int ); 
void printParty( Seat seats[][totalCols], string, string, int, bool );
void seperateSeats( Seat seats[][totalCols], string, int, string );
void seperateAnySeats( Seat seats[][totalCols], string, int);
void initialSeatRev( Seat seats[][totalCols] );
double anyRevenue( Seat seats[][totalCols], string );
void cancelReservation( Seat seats[][totalCols] , string );
double totalRevenue( Seat seats[][totalCols] );
double partyRevenue( Seat seats[][totalCols], int, string , string);
//=============================================================
//     		      	    MAIN
//=============================================================
int main()
{
    Seat sArray[totalRows][totalCols];
    string request;

    initialBlankName( sArray );
    initialSeatPrices( sArray );
    initialSeatId( sArray);
    initialSeatRev ( sArray );
    
  for (int i = 0; i != -1 ; i++){
    cin >> request;
    if ( request == "QU" ){
	return 0;
    }
    else{ 
	menu ( sArray, request) ;
    }   
  }
    return 0;

}

// =============================================================
//
//			    FUNCTION
//                 	   DEFINITIONS
//
// =============================================================



// ------------------------------------------------
// Purpose: initializes each individual seat name 
//	    ex: b4
// Arugments: the 2d arrray of seats
// Returns: n/a
// Effects: gives each space in the array a row number
//	    { a , b, c, d ... , n } and an int for its
//          colun number { 1, 2, 3 ... 20}
// ------------------------------------------------
void initialSeatId( Seat sArray[][totalCols] )
{
    int col = 1;
    char row = 'a';
    
    for( int posR = 0; posR < totalRows; posR++ ){

	for ( int posC = 0; posC < totalCols ; posC++ ){
	     sArray[posR][posC].col = col;
	     sArray[posR][posC].row = row;
	     col++;
	}
	col = 1; 
	row++;
    } 
  
}

// ------------------------------------------------
// Purpose: initializes a name for each blank seat
// Arguments: the 2d array of seats
// Returns: n/a
// Effects: gives each .name space in the array the 
//	    blank initializer "---"
// ------------------------------------------------
void initialBlankName( Seat sArray[][totalCols] )
{   
    for( int posR = 0; posR < totalRows; posR++ ){

	for ( int posC = 0; posC < totalCols ; posC++ ){
	    sArray[posR][posC].name = blankId;
	}
       	
    } 
    
}

// ------------------------------------------------ 
// Purpose: initializes the prices for each seat
// Arguments: the 2d array of seats
// Returns: n/a
// Effects: gives each .price space in the array
//	    "hi" or "lo" 
// ------------------------------------------------
void initialSeatPrices( Seat sArray[][totalCols] )
{
    
  
  for( int posR = 0; posR < totalRows; posR++ ){

    for ( int posC = 0; posC < totalCols ; posC++ ){
      
      if ( (posC >= firstHiCol) && (posC <= lastHiCol) && (posR <= lastHiRow) )
      {    
	sArray[posR][posC].price = "hi";
      }
	else{
	sArray[posR][posC].price = "lo";
	}
    }
       	
  } 
    
}

// ------------------------------------------------
// Purpose: initializes all the seat .rev to 0 
// Arguments: the 2d array of structs 
// Returns: n/a
// Effects: all the .rev spaces in the struct will 
//          have zero
// ------------------------------------------------
void initialSeatRev( Seat sArray[][totalCols] )
{
    for( int posR = 0; posR < totalRows; posR++ ){

	for ( int posC = 0; posC < totalCols; posC++ ){
	    sArray[posR][posC].rev = 0;
	}
    }
}

// ------------------------------------------------
// Purpose: handles all the different user inputes
// Argument: the 2d seat array of structs sArray
//    	     string request { "CA" , "PR" , "CA" }
// Returns: n/a
// Effects: calls three different other functions 
//	    depending on the input
// ------------------------------------------------
void menu( Seat sArray[][totalCols] , string request )
{
    string name;
    
    if ( request == "RQ" ){
	requestErrors(sArray);
    }
    else if ( request == "PR" ){
	printSeats(sArray);
    }
    else if ( request == "CA" ){
	cin >> name; 
	cancelReservation(sArray , name);
        cout << "    OK " << name << " cancelled" << endl;
    }

}
// ------------------------------------------------
// Purpose: handles the "CA" input and takes in a
//	    name
// Arguments: the 2d seat array of structs sArray
// Returns: n/a
// Effects: replaces all instances of the name
//  	    inputted with the blank id "---"
//          and couts a confirmation statement
// ------------------------------------------------
void cancelReservation( Seat sArray[][totalCols] , string name )
{
    for ( int posR = 0; posR < totalRows; posR++ ){

	for ( int posC = 0; posC < totalCols; posC++ ){

	    if ( sArray[posR][posC].name == name ){
		sArray[posR][posC].name = blankId;
		sArray[posR][posC].rev = 0;
	    }
	}
    }

}

// ------------------------------------------------
// Purpose: prints out the current .name values in
//          in the struct for all spaces in the 
//	    array --- prints out the total revenue
// Arguments: the 2d seat array of structs
// Returns: n/a
// Effects: does not change any values in the array
// ------------------------------------------------
void printSeats( Seat sArray[][totalCols] )
{  
   for ( int posR = 0; posR < totalRows; posR++ ){
   
      cout << "    "; 
      
	for( int posC = 0; posC < totalCols; posC++ ){
	    cout << sArray[posR][posC].name << " ";
	 
        }
      cout << endl; 
   }

   cout << "Revenue: ";
   cout <<  totalRevenue( sArray ) << ".00"<< endl;
    
}
// ------------------------------------------------
// Purpose: calculates the total revenue of the 
//	    whole concert hall 
// Arguments: the 2d seat array of structs
// Returns: returns the total revenue
// Effects: does not change any values in the array
// ------------------------------------------------
double totalRevenue( Seat sArray[][totalCols] )
{
    double revenue = 0;

    for ( int posR = 0; posR < totalRows; posR++ ){

	for ( int posC = 0; posC < totalCols; posC++ ){

	    revenue = revenue + sArray[posR][posC].rev;

	}
    }
    return revenue;
}
// ------------------------------------------------
// Purpose: checks too if there are any errors if
//          the input is "RQ" if there are it 
//          outputs an error message 
// Arguments: the 2d seat array of structs
// Returns: n/a
// Effects: does not change anything
// Notes: if there are no errors then calls the 
//	  findSpace function
// ------------------------------------------------
void requestErrors( Seat sArray[][totalCols] )
{
  string name;
  string price; 
  int partySize; 
  
  cin >> name >> partySize >> price;
  if ( (partySize > 12) || (partySize < 1 ) ){
      cout << "    NO " << name << " bad-number" << endl;
  }
  else if ( checkAlreadyReserved( sArray, name ) ){
      cout << "    NO " << name << " already-reserved" << endl;
  }
  else {
    
  findSpace( sArray, name, partySize , price );
    
  }
  
}

// ------------------------------------------------
// Purpose: checks if the name already has a
//  	    reservation
// Arguments: the string 'name' being looked for
//	      the 2d seat array of structs
// Returns: bool if there is already the name in the
//	    array
// Effects: does not change any value in the array
// ------------------------------------------------
bool checkAlreadyReserved( Seat sArray[][totalCols] , string name )
{  
    bool check = false;  

    
    for ( int posR = 0; posR < totalRows; posR++ ){
    
       for( int posC = 0; posC < totalCols; posC++ ){				
	   
	   if ( sArray[posR][posC].name == name ){
	       posR = exitLoop;
	       posC = exitLoop;
	       check = true;
	   }
       }    

    }
    return check;

}

// ------------------------------------------------
// Purpose: after 'RQ' has been inputted, calls one
// 	    of three different functions depending
// 	    on the price range
// Arguments: the 2d array of structs / the string
//	      name of the party asking for a 
//	      reservation / int number of people in
//	      party / string price range
// Returns: n/a
// Effects: does not change any values in the array
// ------------------------------------------------
void findSpace(Seat sArray[][totalCols],string name,int partySize,string price)
{
 
  if (  price == "hi" ){
    findHiSeats( sArray, name, partySize ); 
  }
  if (  price == "lo" ){
    findLoSeats1( sArray, name, partySize ); 
  }
  if (  price == "any" ){
    findAnySeats( sArray, name, partySize ); 
  }
  
}
// ------------------------------------------------
// Purpose: searches through the first set of 
//          lo priced seats for adjacent seating
//	    rows 0-7 and columns 0-3
// Arguments: 2d array - the name of the party
//	      - the number of people in the party
// Returns: n/a
// Effects: when a set of adjacent seats are found
//	    it assigns the name to each of those 
//	    seats
// Notes: functions by going through each space in 
//        the array from left to right, then down
//	  the rows - at each space it checks if 
//        there are the correct number of open seats
//	  next to it
//	  -- if no adjacent seats are found calls
//	     another function for seperate seats
//	  -- if adjacent seats are found calls a func
//           to assign seats then another to print the 
//	     confirmation
// ------------------------------------------------
void findLoSeats1( Seat sArray[][totalCols], string name, int partySize )
{
  int count;
  int openAdjacentSeats;
  bool adjacent = false;
  string price = "lo";

  for ( int posR = 0; posR <= lastHiRow ; posR++ ){
    
      for ( int posC = 0; posC <= lastLoCol - (partySize - 1); posC++ ){
      
	  count = 0;		 //number of seats right of posC the loop is at 
	  openAdjacentSeats = 0; //counts the amount of open seats next to posC
	  
	  for ( int posCheck = posC; count < partySize; posCheck++){
	
	      if ( sArray[posR][posCheck].name == blankId ){
	   
		  openAdjacentSeats++;  
	
	      }
	      if ( openAdjacentSeats == partySize ){
		  adjacent = true;
		  assignSeat( sArray, name, partySize, posC , posR);
		  printParty( sArray, name, price, partySize, adjacent);
		  posR = exitLoop;
		  count = exitLoop; 	
		  posC = exitLoop; 
	      }
	
	      count++; //exits and moves to the next posC when it has
	  }	       //counted up partySize number of times and there 
    }		       // are not partySize amount of openseats
  }
  
  if ( !adjacent ){
      findLoSeats2( sArray, name, partySize ); 
  }

}
// ------------------------------------------------
// Purpose: searches through the second set of 
//          lo priced seats for adjacent seating
//	    rows 0-7 and columns 16-19
// Arguments: 2d array - the name of the party
//	      - the number of people in the party
// Returns: n/a
// Effects: when a set of adjacent seats are found
//	    it assigns the name to each of those 
//	    seats
// Notes: functions by going through each space in 
//        the array from left to right, then down
//	  the rows - at each space it checks if 
//        there are the correct number of open seats
//	  next to it
//	  -- if no adjacent seats are found calls
//	     another function for seperate seats
//	  -- if adjacent seats are found calls a func
//           to assign seats then another to print the 
//	     confirmation
// ------------------------------------------------
void findLoSeats2( Seat sArray[][totalCols], string name, int partySize )
{
  int count;
  int openAdjacentSeats;
  bool adjacent = false;
  string price = "lo";
  for ( int posR = 0; posR <= lastHiRow ; posR++ ){
    
      for ( int posC = 16; posC <= totalCols - (partySize); posC++ ){
      
	  count = 0;
	  openAdjacentSeats = 0;
	  
	  for ( int posCheck = posC; count < partySize; posCheck++){
	
	      if ( sArray[posR][posCheck].name == blankId ){
	   
		    openAdjacentSeats++;   
	
	      }
	      if ( openAdjacentSeats == partySize ){
		  adjacent = true;
		  assignSeat( sArray, name, partySize, posC , posR);
		  printParty( sArray, name, price, partySize, adjacent );
		  posR = exitLoop;
		  count = exitLoop;
		  posC = exitLoop; 
	      }
	
	      count++; 
	  }
    }
  }
  
  if ( !adjacent ){
      findLoSeats3( sArray, name, partySize ); 
  }

}

// ------------------------------------------------
// Purpose: searches through the third set of 
//          lo priced seats for adjacent seating
//	    rows 7-14 and columns 0-19
// Arguments: 2d array - the name of the party
//	      - the number of people in the party
// Returns: n/a
// Effects: when a set of adjacent seats are found
//	    it assigns the name to each of those 
//	    seats
// Notes: functions by going through each space in 
//        the array from left to right, then down
//	  the rows - at each space it checks if 
//        there are the correct number of open seats
//	  next to it
//	  -- if no adjacent seats are found calls
//	     another function for seperate seats
//	  -- if adjacent seats are found calls a func
//           to assign seats then another to print the 
//	     confirmation
// ------------------------------------------------
void findLoSeats3( Seat sArray[][totalCols], string name, int partySize )
{
  int count;
  int openAdjacentSeats;
  bool adjacent = false;
  string price = "lo";
  for ( int posR = 7; posR < totalRows; posR++ ){
    
      for ( int posC = 0; posC <= totalCols - (partySize); posC++ ){
      
	  count = 0;
	  openAdjacentSeats = 0;
	  
	  for ( int posCheck = posC; count < partySize; posCheck++){
	
	      if ( sArray[posR][posCheck].name == blankId ){
	   
		    openAdjacentSeats++;   
	
	      }
	      if ( openAdjacentSeats == partySize ){
		   adjacent = true;
		   assignSeat( sArray, name, partySize, posC , posR);
		   printParty( sArray, name, price, partySize, adjacent);           
		   posR = exitLoop;
		   count = exitLoop;
		   posC = exitLoop; 
	      }
	
	      count++; 
	  }
    }
  }
  

  if ( !adjacent ){
	seperateSeats( sArray, name, partySize, price ); 
  }

}
// ------------------------------------------------
// Purpose: searches through the hi priced seats for
//          adjacent hi Seats row 0-7 col 4-15
// Arguments: 2d array - the name of the party
//	      - the number of people in the party
// Returns: n/a
// Effects: when a set of adjacent seats are found
//	    it assigns the name to each of those 
//	    seats
// Notes: functions by going through each space in 
//        the array from left to right, then down
//	  the rows - at each space it checks if 
//        there are the correct number of open seats
//	  next to it
//	  -- if no adjacent seats are found calls
//	     another function for seperate seats
//	  -- if adjacent seats are found calls a func
//           to assign seats then another to print the 
//	     confirmation
// ------------------------------------------------
void findHiSeats( Seat sArray[][totalCols], string name, int partySize )
{
  int count;
  int openAdjacentSeats;
  bool adjacent = false;
  string price = "hi";

  for ( int posR = 0; posR <= lastHiRow ; posR++ ){    
      for ( int posC = firstHiCol; posC <= lastHiCol - (partySize-1); posC++ ){
	  count = 0;
	  openAdjacentSeats = 0; 
	  for ( int posCheck = posC; count < partySize; posCheck++){
	      if ( sArray[posR][posCheck].name == blankId ){
		    openAdjacentSeats++;   
	      }
	      if ( openAdjacentSeats == partySize ){
		   adjacent = true;
		   assignSeat( sArray, name, partySize, posC , posR);
		   printParty( sArray, name, price, partySize, adjacent );
		   posR = lastHiRow + 1;
		   count = exitLoop;
		   posC = lastHiCol;
	      }
	      count++; 
	  }
    }
  }  
  if ( !adjacent ){
      seperateSeats( sArray, name, partySize, price ); 
  }
}

// ------------------------------------------------
// Purpose: searches through all the seats to find
//          adjacent seats and assign them a name
// Arguments: 2d array - the name of the party
//	      - the number of people in the party
// Returns: n/a
// Effects: when a set of adjacent seats are found
//	    it assigns the name to each of those 
//	    seats
// Notes: functions by going through each space in 
//        the array from left to right, then down
//	  the rows - at each space it checks if 
//        there are the correct number of open seats
//	  next to it
//	  -- if no adjacent seats are found calls
//	     another function for seperate seats
//	  -- if adjacent seats are found calls a func
//           to assign seats then another to print the 
//	     confirmation
// ------------------------------------------------
void findAnySeats( Seat sArray[][totalCols], string name, int partySize )
{
    int count;
    int openAdjacentSeats;
    bool adjacent = false;
    string price = "any";
    for( int posR = 0; posR < totalRows; posR++ ){
      	for( int posC = 0; posC <= totalCols - partySize; posC++ ){
	    count = 0;
	    openAdjacentSeats = 0;
	    for ( int posCheck = posC; count < partySize; posCheck++){
		if ( sArray[posR][posCheck].name == blankId ){
		    openAdjacentSeats++;
		}
		if ( openAdjacentSeats == partySize ){
		    adjacent = true;
		    assignSeat( sArray, name, partySize, posC, posR );
		    printParty( sArray, name, price, partySize, adjacent );
		    posR = totalRows;
		    count = exitLoop;
		    posC = totalCols;
		}
		count++;
	    }
	}
    }
    
    if ( !adjacent ){
	seperateAnySeats( sArray, name, partySize);
    }
  
}

// ------------------------------------------------
// Purpose: assigns names to seats
// Arguments: 2d array - the name of the party
//	      - the first open seat found by
//	      a function that called it (posC & posR)
// Returns: n/a
// Effects: assigns a name to the seats
// ------------------------------------------------
void assignSeat(Seat sArray[][totalCols],string name,int partySize,int posC,int posR)
{
	for( int i = 0; i < partySize; i++ ){
      		sArray[posR][posC].name = name ;
      		posC++;
  	}
}

// ------------------------------------------------
// Purpose: if adjacent seats are not found then 
//	    looks for seperate seats
// Arguments: 2d array - party name - partysize -
//	      price range
// Returns: n/a
// Effects: assigns new names in the array if possible
// Notes:   -Calls print party if possible - if not prints 
//          not available
// ------------------------------------------------
void seperateSeats(Seat sArray[][totalCols], string name, int partySize, string price)
{ 
    int count = 0;
    bool adjacent = false;

    for( int posR = 0; posR < totalRows ; posR++ ){

        for ( int posC = 0; posC < totalCols; posC++ ){
	  
	     if( ( sArray[posR][posC].name == blankId ) && 
	         ( sArray[posR][posC].price == price ) ) 
	     {
		sArray[posR][posC].name = name;
		count++;
	     }
	     if ( count == partySize ){
		printParty( sArray, name, price, partySize, adjacent );
		posC = exitLoop;
		posR = exitLoop;
	     }
	     else if ( (posR == totalRows - 1) && ( posC == totalCols - 1 ) ){
		cout << "    NO " << name << " not-available" << endl;
                cancelReservation( sArray, name );
	     }
	}
    }
    
}

// ------------------------------------------------
// Purpose: if adjacent seats are not found then 
//	    looks for seperate seats of any price
// Arguments: 2d array - party name - partysize -
// Returns: n/a
// Effects: assigns new names in the array if possible
// Notes:   -Calls print party if possible - if not prints 
//          not available
// ------------------------------------------------
void seperateAnySeats(Seat sArray[][totalCols], string name, int partySize)
{
    int count = 0;
    bool adjacent = false;
    string price = "any";
    for ( int posR = 0; posR < totalRows; posR++ ){

	for ( int posC = 0; posC < totalCols; posC++ ){

	    if( sArray[posR][posC].name == blankId ){
		sArray[posR][posC].name = name;
		count++;
	    }
	    if( count == partySize ){
                printParty( sArray, name, price, partySize, adjacent );
		posC = totalCols;
		posR = totalRows;
	    }
	    else if ( (posR == totalRows - 1) && ( posC == totalCols - 1 ) ){
	        cancelReservation( sArray, name );
                cout << "NO " << name << " not-available" << endl;
  	    }
	}
    }
	     
		
    
}

// ------------------------------------------------
// Purpose: prints out a confirmation message for 
//	    a party reservation - also assigns 
//          a revenue value to the first seat in
//	    the party
// Arguments: the 2d seat array, a party name, a 
//	      party price range (string), and a
//	      bool to represent if adjacent seating
//	      was possible
// Returns: n/a
// Effects: couts values - calls a function to set 
// 	    the .rev space in the struct for each 
//	    name
// ------------------------------------------------
void printParty(Seat sArray[][totalCols], string name, string price, 
		int partySize, bool adjacent)
{
    double revenue;

    revenue = partyRevenue( sArray, partySize, name, price );
    if ( !adjacent ){
	revenue = revenue * discount;
    }

    cout << "    OK " << name << " " << revenue << " " << partySize << " ";
    for( int posR = 0; posR < totalRows; posR++ ){
	
	for ( int posC = 0; posC < totalCols ; posC++ ){
	    	if ( name == sArray[posR][posC].name ){
	        cout << sArray[posR][posC].row << sArray[posR][posC].col;
	        cout << " ";
	        }
	}  	
    }   

    for(int posR = 0; posR < totalRows; posR++){
	
	for (int posC = 0; posC < totalCols ; posC++){
	    	if ( name == sArray[posR][posC].name ){
		sArray[posR][posC].rev = revenue;
		posC = posR = exitLoop;
	    	}
    	}
    }
    cout << endl;
}
// ------------------------------------------------
// Purpose: calculates the additional revenue from
//	    a group seated in the seats
// Arguments: 2d array - name being looked for
//	      - the string party price - int
//	      how many people are in the group 
// Returns: double - revenue
// Effects: calls a seperate function to handle any
// ------------------------------------------------

double partyRevenue( Seat sArray[][totalCols], int partySize, string name, 
		    string price )
{ 
    double revenue;
    
    if ( price == "lo" ){
	revenue = partySize * 150;
    }
    else if ( price == "hi" ){
        revenue = partySize * 200;
    }
    else if ( price == "any" ){
	revenue = anyRevenue( sArray, name);
    }

    return revenue; 

}

// ------------------------------------------------
// Purpose: calculates the additional revenue from
//	    a group seated in any priced seats
// Arguments: 2d array - name being looked for
// Returns: double - revenue
// Effects: does not change anything in the array
// ------------------------------------------------
double anyRevenue(Seat sArray[][totalCols], string name)
{
    double revenue = 0;

    for ( int posR = 0; posR < totalRows; posR++ ){

	for ( int posC = 0; posC < totalCols; posC++ ){

	    if( sArray[posR][posC].name == name ){
		if( sArray[posR][posC].price == "hi")
	        {
		    revenue = revenue + hiPrice;
	        }
	        if( sArray[posR][posC].price == "lo")
		{
		    revenue = revenue + loPrice;
		}
	    }
	}
    }

    return revenue;

}



