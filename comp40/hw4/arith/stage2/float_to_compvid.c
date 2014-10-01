/*
 * COMPRESSION 
 *
 *    float_to_compvid.c
 *        Implementation of float_compvid.h  
 *        Purpose: compresses to a UArray_2 of compvid_block 
 *                 from a UArray_2 of 'rgb_block' 
 *      Edited on: March 2, 2014
 *      
 *      Tufts University COMP 40 
 *
 */

#include "float_compvid.h"

static void apply_compress( int i, int j, A2Methods_UArray2 compressed, 
                        A2Methods_Object * cv_block, void * cl );
static compvid_pix get_pix( rgb_float in );
static float get_y( rgb_float in );
static float get_pb( rgb_float in );
static float get_pr( rgb_float in );

A2Methods_UArray2 compress_float_to_compvid(A2Methods_UArray2 float_blocks)
{
        A2Methods_T methods = uarray2_methods_plain;
        assert(methods);

        A2Methods_UArray2 compressed;
        compressed = methods->new( methods->width( float_blocks ) ,                                      methods->height( float_blocks),
                                     sizeof( compvid_block ) );
        methods->map_row_major(compressed, &apply_compress, &float_blocks);

        methods->free(&float_blocks);
        return compressed;
}
static void apply_compress( int i, int j, A2Methods_UArray2 compressed, 
                        A2Methods_Object * cv_block, void * cl )
{
        A2Methods_T methods = uarray2_methods_plain;
        A2Methods_UArray2 * tmp = cl;
        compvid_block * cv = cv_block;

        cv->p1 = get_pix( ((rgb_block*)methods->at( *tmp, i, j ))->p1 );
        cv->p2 = get_pix( ((rgb_block*)methods->at( *tmp, i, j ))->p2 );
        cv->p3 = get_pix( ((rgb_block*)methods->at( *tmp, i, j ))->p3 );
        cv->p4 = get_pix( ((rgb_block*)methods->at( *tmp, i, j ))->p4 );

        (void) compressed;
}
static compvid_pix get_pix( rgb_float in )
{
        compvid_pix out;
        out.y = get_y( in );
        out.pb = get_pb( in );
        out.pr = get_pr( in );

        return out;
}

static float get_y( rgb_float in )
{
        return 0.299 * in.red + 0.587 * in.green 
                      + 0.114 * in.blue;
}
static float get_pb( rgb_float in )
{
        return -0.168736 * in.red - 0.331264 * in.green
                       + 0.5 * in.blue;

}
static float get_pr( rgb_float in )
{
        return 0.5 * in.red - 0.418688 * in.green
                       - 0.081312 * in.blue; 
}
