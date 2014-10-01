/*  uarray2b.c 
 *      by: Michael Tran and Quinn Hood
 *      Last Edited On: February 17, 2014 
 *
 *  For: 
 *      Tufts University 
 *      COMP 40 HW 3 
 *      Part A: Improving Locality Through Blocking
 *  Purpose: 
 *      Provides an implemenation for a blocked 2D array
 *
 */
#include "uarray2b.h"
#include "uarray2.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "mem.h"
#include "assert.h"
#define T UArray2b_T

struct T {
        UArray2_T blocks;
        int height;
        int width;
        int size;
        int blocksize;
        int bwidth;
        int bheight; 
};

/* Purpose: Given a block, which is a UArray2, goes through each element in the
 *          block while making sure that it does not go into the wasted space
 *   Calls: The apply function on the element
 *    Note: Calculates the x and y coordinates of the space to make sure it
 *          is not out of bounds
 */
static void map_block( UArray2_T block , T array2b, int b_col, int b_row, 
                        void apply(int i, int j, T array2b, void *elem, 
                                   void *cl), void *cl)
{
        int i, j;
        int y_2b ;
        int x_2b;
                                

        for ( i = 0; i < array2b->blocksize; i++ ) {
                for ( j = 0; j < array2b->blocksize; j++ ) {
                        x_2b = ((b_col * array2b->blocksize) + i );
                        y_2b = ((b_row * array2b->blocksize) + j );
                        if( ( x_2b < array2b->width ) && 
                            ( y_2b < array2b->height ) ) {
                                apply( x_2b, y_2b, array2b, 
                                       UArray2_at(block, i, j), cl );   
                        }
                        
                }       
        }
                

}

/* Purpose: Our UArray2b is implemented as a UArray2 of UArray2's.  
 *   Calls: UArray2_new in order to create our blocks
 *    Note: n/a
 */
T UArray2b_new (int width, int height, int size, int blocksize)
{
        T array2b;
        NEW(array2b);
        int i, j;

        assert(width);
        assert(height);
        assert(size);
        assert(blocksize);

/*
Calculates the number of blocks
*/      
        if ( width % blocksize != 0 ) {
                array2b->bwidth = (width / blocksize) + 1;      
        } else {
                array2b->bwidth = width / blocksize;
        }
        if ( height % blocksize != 0 ) {
                array2b->bheight = (height / blocksize) + 1;    
        } else {
                array2b->bheight = height / blocksize;
        }
                        
/*
Creates the blocks which are represetned as UArray2's
*/
        array2b->blocks = UArray2_new( array2b->bwidth, array2b->bheight, 
                                       sizeof(UArray2_T));
        array2b->size = size;
        array2b->width = width;
        array2b->height = height; 
        array2b->blocksize = blocksize;
/*
Loops through each block to create a new UArray2
*/
        for ( i = 0; i < array2b->bwidth; i++) {
                for ( j = 0; j < array2b->bheight; j++) {
                        UArray2_T *temp = UArray2_at( array2b->blocks, i, j );
                        *temp = UArray2_new(blocksize, blocksize, size);
                }
        }
        return array2b;
}

/* Purpose: Calculates the blocksize based on size and then creates a new
 *          UArray2b with that calculated blocksize
 *   Calls: UArray2b_new
 *    Note: n/a
 */
T UArray2b_new_64K_block(int width, int height, int size)
{
        assert(width);
        assert(height);
        assert(size);
        
        int blocksize = sqrt(64 * 1024 / size);

        if( blocksize < 1 )
        {
                blocksize++;
        }
        return UArray2b_new(width, height, size, blocksize);
}

/* Purpose: Given an element in the array, it frees it
 *   Calls: UArray2_free
 *    Note: n/a
 */
void free_apply( int i, int j, UArray2_T array2, void * elem, void * cl )
{
        assert( elem );
        
        UArray2_T * tmp = elem; 
        
        UArray2_free( tmp );
        (void) cl;
        (void) i;
        (void) j;
        (void) array2;
}

/* Purpose: Loops through the UArray2 and frees all of the UArray2's held within
 *          and then frees the outer UArray2
 *   Calls: Map by col major and free
 *    Note: n/a
 */
void UArray2b_free (T *array2b)
{       
        assert(array2b);
        assert(*array2b);

        
        UArray2_map_col_major( (*array2b)->blocks, free_apply, NULL );
        UArray2_free( &((*array2b)->blocks) );
        free (*array2b);

}

int UArray2b_width (T array2b)
{
        assert( array2b );
        return array2b->width;
}
int UArray2b_height(T array2b)
{
        assert( array2b );
        return array2b->height;
}

int UArray2b_size (T array2b)
{
        assert( array2b );
        return array2b->size;
}

int UArray2b_blocksize(T array2b)
{
        assert( array2b );
        return array2b->blocksize;
}

/* Purpose: Returns a pointer to the element at the given index
 *   Calls: n/a
 *    Note: n/a
 */
void *UArray2b_at(UArray2b_T array2b, int i, int j)
{
        
        assert( array2b );
        
        int blockcol = i / array2b->blocksize;
        int blockrow = j / array2b->blocksize;
        
        UArray2_T *block; 
        block = UArray2_at( array2b->blocks, blockcol, blockrow );
        return UArray2_at( *block, i % array2b->blocksize, 
                           j % array2b->blocksize );
}

/* Purpose: Goes through the blocks in order to call the apply function on every
 *          element in one block before moving onto another
 *   Calls: Map_block in order to go through every element
 *    Note: n/a
 */
extern void UArray2b_map(T array2b,
                         void apply(int i, int j, T array2b, void *elem, 
                                    void *cl), void *cl)
{
        assert( array2b );
        UArray2_T* temp;
        int i, j;

        for ( i = 0; i < array2b->bwidth; i++) {
                for( j = 0; j < array2b->bheight; j++) {
                        temp = UArray2_at(array2b->blocks, i, j);
                        map_block(*temp , array2b , i , j, apply, cl);
                }
        }
}

