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
#include "uarray2.h"
#include <except.h>


        /*****************************************************************
        *                     FUNCTION PROTOTYPES 
        *****************************************************************/
void readIn();

        /*****************************************************************/




/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~ ** MAIN ** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
int main( int argc, char* argv[])
{
        readIn();
        if( argc == 2 )
        (void) argc;
        (void) argv;

}

Uarray2 readIn();
{

        Uarray2 test = Uarray2_new()
}
