/*  
 *  brighness.c 
 *      by: Michael Tran and Jaime Sanchez
 *      Last Edited On: January 25, 2014 
 *
 *  For: 
 *      Tufts University 
 *      COMP 40 HW 1 
 *      Part A: Brightness of a grayscale inmage
 *  Purpose: 
 *      prints the average brightness of a pgm image 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pnmrdr.h"
#include <except.h>
 
   /*****************************************************************
    *                     FUNCTION PROTOTYPES 
    *****************************************************************/
FILE * get_file( int argc, char * argv[] );
FILE * open_or_abort(char *fname, char *mode);
double get_brightness( FILE * fp );
bool isGraymap(Pnmrdr_T file);
Pnmrdr_T exceptionTest(FILE *fp);
    /*****************************************************************/


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~ ** MAIN ** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
int main( int argc, char * argv[])
{
        if (argc > 2 ) { 
                fprintf(stderr,"too many arguments/files\n");
                exit(1);
        } else if (argc == 2) {
                FILE * fp = NULL; 
                fp = open_or_abort(argv[1], "r");
                get_brightness(fp);
                fclose(fp);
        } else { 
                get_brightness(stdin);
        }
    return 0; 
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */



    /*****************************************************************
    *                                                               *
    *                                                               *
    *                PGM AVG HANDLING IMPLEMENTATION                *
    *                                                               *
    *                                                               *
    *****************************************************************/

double get_brightness( FILE * fp )
{       
        Pnmrdr_T pgm_file = NULL; 
        pgm_file = exceptionTest(fp);
 
        if (!isGraymap(pgm_file)){
                fprintf(stderr,"Files is not Graymap format \n");
                exit(1);
        }

        Pnmrdr_mapdata map = Pnmrdr_data(pgm_file);
        double average = 0;
        unsigned width = map.width; 
        unsigned height = map.height;
    
        for( unsigned i = 0; i <  (width * height) ; i++ ){
                average += Pnmrdr_get(pgm_file);
        }
    
        average = average/ map.denominator;
        average = average / (width*height);
        printf("%.03f\n",average);
        free(pgm_file);
   
        return average;   
}

    /*****************************************************************
    *                                                               *
    *                                                               *
    *                INPUT HANDLING IMPLEMENTATION                  *
    *                                                               *
    *                                                               *
    *****************************************************************/

FILE * open_or_abort(char *fname, char *mode)
{
        FILE *fp = fopen(fname,mode);
        if (fp == NULL) {
                fprintf(stderr,"Could not open file %s with mode %s\n",
                        fname, mode);
                exit(1);
        }
        return fp;
}


bool isGraymap(Pnmrdr_T file)
{
        if ( Pnmrdr_data(file).type == Pnmrdr_gray){ 
                return true;
        } else {
                return false;
        }
}

Pnmrdr_T exceptionTest(FILE *fp)
{
        Pnmrdr_T pgm_file = NULL;

        TRY
                pgm_file = Pnmrdr_new(fp);
        EXCEPT(Pnmrdr_Badformat)
                fprintf(stderr, "Bad format\n");
                exit(EXIT_FAILURE);
        END_TRY;

        return pgm_file;
}