#include <stdio.h>
#include <table.h>
#include <stdlib.h>
#include <ctype.h>
#include <set.h>
#include <atom.h>
#include <seq.h>
#include <str.h>
#include <list.h>

typedef struct
{
        char* fp;
        char* name;
} fpPair;

void readAll( Table_T );
fpPair readLine();
int addToTable( Set_T nameSet, Table_T fpTable , fpPair pair);
int nameStart( char *buffer, int fpEnd);
void addToTableHelp( Table_T , fpPair );
void printAll( Table_T );
static void applyprinttable( const void * , void ** , void *);
static void applyprintlist( void ** , void *);
static void applyFree( void ** ptr, void* cl);


const int initTableSize = 10;
const int initSetSize = 20;
const int initSeqSize = 10; 
const int maxFpSize = 512;
const int bufferSize = 50000;


int main( int argc, char *argv[])
{

        (void) argc;
        (void) argv;

        Table_T fpTable = Table_new( initTableSize, NULL, NULL );

        readAll( fpTable );
        printAll( fpTable);
        Table_free(&fpTable);
        return 0;
}


void printAll( Table_T fpTable )
{
        Table_map(fpTable, applyprinttable, NULL);
}

static void applyprinttable( const void * key, void ** names, void *cl)
{
    (void) key;
    if( List_length(*names) > 1 ){ //fgroups must have at least 2 names.
        List_map(*names, applyprintlist, NULL); //names is a pointer to a list.
        printf("\n");
    }
    List_map( *names , applyFree, NULL );
    List_free(*names);
    (void) cl;
}

static void applyFree( void ** ptr, void* cl)
{
    free(*ptr);
    (void) cl;
}
static void applyprintlist( void ** name, void *cl){
    printf(*name);
    (void) cl;
}

void readAll( Table_T fpTable )
{
        Set_T nameSet = Set_new( initSetSize, NULL, NULL ); 


        fpPair pair;

        while( !feof(stdin) )
        {      

                pair = readLine();
                addToTable( nameSet, fpTable, pair );

        }

        Set_free(&nameSet);

}

int addToTable( Set_T nameSet, Table_T fpTable, fpPair pair)
{
        const char * nameAtom = Atom_string(pair.name);

        if( !Set_member( nameSet, nameAtom) )
        {
                Set_put( nameSet, nameAtom);
                addToTableHelp( fpTable, pair );
                return 1;
        }
        else{
                free (pair.name);
                free (pair.fp);
                return 0;
        }
}

void addToTableHelp( Table_T fpTable, fpPair pair )
{
        List_T names = NULL;
        const char * fpAtom = Atom_string(pair.fp);

        // if the key does exist in the table 
        // get the list already stored 
        if( Table_get( fpTable, fpAtom ) != NULL )
        {       
                names = Table_get( fpTable, fpAtom );
        }

        // pushes the the list 
        names = List_push( names, pair.name);
        Table_put( fpTable, fpAtom, names );

        free(pair.fp);

        // List_map( names , applyFree, NULL );

}

fpPair readLine()
{
        fpPair pair;

        pair.fp = malloc( sizeof(pair.fp) );
        pair.name = malloc( sizeof(pair.name) ); 
        char *buffer = malloc( bufferSize * sizeof( char ) );      
        int fpEnd;



        fgets( buffer, bufferSize, stdin );

        if(feof(stdin))         // prevent the reading in of a blank line
        {
                free (pair.name);
                free (pair.fp);
                free (buffer);
                return pair;
        }

        fpEnd = Str_find( buffer, 1, 0 , " ");
        pair.fp = Str_dup( buffer, 1, fpEnd, 1 );
        pair.name = Str_dup( buffer, nameStart( buffer, fpEnd ), 0 , 1);

        free (buffer);
        return pair;



}

// Purpose: ignores whitespace after fp and returns index of the 
//          first char in the name
int nameStart( char *buffer, int fpEnd )
{

        int index = fpEnd - 1;     // handling Hansons string index
                                   // convention vs standard c indeces
        char check = buffer[index];
        int count = 0;

        while( isspace(check) )
        {       
                index++;
                count++;
                check = buffer[index];
        }

        return count + fpEnd;
}