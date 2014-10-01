/*  
 *  fgroups.c 
 *      by: Michael Tran and Jaime Sanchez
 *      Last Edited On: January 25, 2014 
 *
 *  For: 
 *      Tufts University 
 *      COMP 40 HW 1 
 *      Part B: Finger Print Groups
 *  Purpose: 
 *      Handle fingerprint and name pairs read in from standard input, then
 *      print the names belonging to each fingerprint group
 *
 */


#include <stdio.h>
#include <table.h>
#include <stdlib.h>
#include <ctype.h>
#include <set.h>
#include <atom.h>
#include <str.h>
#include <list.h>

typedef struct
{
       char* fp;
       char* name;
} fpPair;


   /*****************************************************************
    *                     FUNCTION PROTOTYPES 
    *****************************************************************/

void read_all( Table_T );
fpPair read_line();
fpPair scrape_input( char* buffer );
int find_name( char *buffer, int fpEnd);
int Table_add( Set_T nameSet, Table_T fpTable , fpPair pair);
void Table_add_helper( Table_T fpTable, fpPair pair );
void print( Table_T fpTable );
char* add_new_line( char* name );
static void apply_Table_print( const void * key , void ** names, void * cl);
static void apply_List_print( void ** names , void * cl);
static void apply_List_free( void ** ptr, void* cl);

    /*****************************************************************/




   /*****************************************************************
    *                      GLOBAL CONSTANTS 
    *****************************************************************/

const int initTableSize = 10;
const int initSetSize = 20;
const int initSeqSize = 10; 
const int maxFpSize = 512;
const int bufferSize = 50000;
const int badLine = -500;


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~ ** MAIN ** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
int main( int argc, char *argv[])
{

       (void) argc;
       (void) argv;

       Table_T fpTable = Table_new( initTableSize, NULL, NULL );

       read_all( fpTable );
       print( fpTable);
       Table_free(&fpTable);
       return 0;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


    /*****************************************************************
    *                                                               *
    *                                                               *
    *                INPUT HANDLING IMPLEMENTATION                  *
    *                                                               *
    *                                                               *
    *****************************************************************/


/* Purpose: reads in from user input and calls functions to store the 
 *          valid input in a finger print table
 *   Calls: Table_add, read_line
 *    Note: allocates Set to be used in checking for repeat names
 */
void read_all( Table_T fpTable )
{
       Set_T nameSet = Set_new( initSetSize, NULL, NULL ); 

       fpPair pair;

        while( !feof(stdin) )
        {      
                pair = read_line();

                /* pair.name == NULL when there is badly formatted line */
                if( ( pair.name != NULL ) ) {
                        Table_add( nameSet, fpTable, pair );
                } else {
                        free (pair.fp);
                }
        }
        Set_free(&nameSet);
}

/* Purpose: handles one line of user input, and calls functions which
 *          format the input into type "fpPair" to be returned
 *   Calls: scrape_input
 *    Note: allocates buffer of "bufferSize" --- NOT DYNAMIC ( needs work )
 * Returns: fingerprint pair of valid format
 */
fpPair read_line()
{
        fpPair pair;
        char *buffer = malloc( bufferSize * sizeof( char ) );

        fgets( buffer, bufferSize, stdin );
        pair = scrape_input( buffer );
        free (buffer);

        return pair;
}

/* Purpose: given a buffer of a single line of input - splits into two 
 *          strings - fingerprint and name -  
 *   Calls: find_name, add_new_line
 *    Note: uses Hanson's 'Str' interface
 * Returns: fingerprint pair of valid format
 */
fpPair scrape_input( char* buffer )
{
        int fpEnd;
        fpPair pair;
        pair.fp = NULL ;
        pair.name = NULL; 

        /* finds the first whitespace character then duplicates the buffer to 
         * fp   */  
        fpEnd = Str_find( buffer, 1, 0 , " ");
        pair.fp = Str_dup( buffer, 1, fpEnd, 1 );

        /* line is badly formatted -> returns pair while pair.fp == NULL */
        if( ( fpEnd == 0 ) || find_name( buffer, fpEnd ) == badLine ){
                return pair;
        }

        pair.name = Str_dup( buffer, find_name( buffer, fpEnd ), 0 , 1);
        pair.name = add_new_line( pair.name );

        return pair;
}

/* Purpose: ignores whitespace after fp and returns index of the 
 *          first char in the name, 
 *    Note: if there is no nonwhitespace char in the 
 *          name returns a sentinel value 'badLine'
 * Returns: int - index of first character in the name 
 *              - or a sentinel value 'badLine'
 */
int find_name( char *buffer, int fpEnd )
{
        int index = fpEnd - 1;    // handling Hansons string index
                                  // convention vs standard c indeces
        char check = buffer[index];
        int count = 0;
        
        while( isspace(check) ){
                if( check == '\n' ){
                        return badLine;
                }
                index++;
                count++;
                check = buffer[index];
        }

        return count + fpEnd;
        
}

/* Purpose: adds new line character to the end of a name for formatting
 *    Note: should only add a new line to the last name read in - if any at all
 * Returns: char * with the new line character added 
 */
char* add_new_line( char* name )
{
        /* starts from the right of the string to improve efficiency */
        if ( (Str_rfind(name,1,0,"\n") == 0) ) {   
                char* temp = name;
                name = Str_cat(name,1,0, "\n",1,0);
                free (temp);
        }
        return name;
}

    /*****************************************************************
    *                                                               *
    *                                                               *
    *                OUTPUT HANDLING IMPLEMENTATION                 *
    *                                                               *
    *                                                               *
    *****************************************************************/


/* Purpose: calls a mapping function to the names in fp groups in the table
 *    Note: if there is no nonwhitespace char in the 
 *          name returns a sentinel value 'badLine'
 *    Call: Table_map, apply_Table_print
 */
void print( Table_T fpTable )
{   
        /* CLOSURE PREVENTS PRINTING OF NEW LINE BEFORE FIRST FGROUP */
        int *cl = malloc(sizeof(*cl));
        *cl = 1;    
        Table_map(fpTable, apply_Table_print, cl);
        free (cl);
}

/* Purpose: apply function for Table_map which prints the fp groups 
 *    Note: uses List_map to free and print the members of the lists 
 *    Call: apply_List_print, applyList_free
 */
static void apply_Table_print( const void * key, void ** names, void *cl)
{
        (void) key;


        if( List_length(*names) > 1 ){ 
                if( *(int *) cl != 1 ){
                        printf("\n");
                }
                List_map(*names, apply_List_print, NULL);
                (*(int *) cl)--;
        }

        List_map( *names , apply_List_free, NULL );
        List_free((List_T *)names);
}

/* Purpose: prints the member of the list */
static void apply_List_print( void ** name, void *cl)
{
        printf(*name);
        (void) cl;
}


    /*****************************************************************
    *                                                               *
    *                                                               *
    *                  DATA STORAGE IMPLEMENTATION                  *
    *                                                               *
    *                                                               *
    *****************************************************************/


/* Purpose: adds the pair to that table if the atomized name is not in the set
 *    Note: frees the members in pair if it is not added - otherwise frees in
 *          Table_add_helper once added
 *    Call: Table_add_helper
 */
int Table_add( Set_T nameSet, Table_T fpTable, fpPair pair)
{
       const char * nameAtom = Atom_string(pair.name);


        if( !Set_member( nameSet, nameAtom) )
        {
               Set_put( nameSet, nameAtom);
               Table_add_helper( fpTable, pair );
               return 1;
        }
        else{
                free( pair.fp);
                free( pair.name);
                return 0;
        }
}

/* Purpose: adds the valid fingerprint pair to the table
 *    Note: called after checking if if the name belongs
 */
void Table_add_helper( Table_T fpTable, fpPair pair )
{
        List_T names = NULL;
        const char * fpAtom = Atom_string(pair.fp);
        free( pair.fp );

        /* if the key is already present - its member list 
           must be copied and added to */
        if( Table_get( fpTable, fpAtom ) != NULL ){       
               names = Table_get( fpTable, fpAtom );
        }
       
        names = List_push( names, pair.name);
        Table_put( fpTable, fpAtom, names );
}

/* Purpose: called by map to free each element of the list */
static void apply_List_free( void ** ptr, void* cl)
{
        free(*ptr);
        (void) cl;
}