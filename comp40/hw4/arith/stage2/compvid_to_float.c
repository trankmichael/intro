/*
 * DECOMPRESSION 
 *
 *    compvid_to_float.c
 *        Implementation of float_compvid.h  
 *        Purpose: compresses from a UArray_2 of compvid_block 
 *                 to a UArray_2 of 'rgb_block' 
 *      Edited on: March 2, 2014
 *      
 *      Tufts University COMP 40 
 *
 */

#include "float_compvid.h"

static void apply_decompress( int i, int j, A2Methods_UArray2          
                        decompressed, A2Methods_Object * r_block, void * cl  );
static rgb_float get_rgb(  compvid_pix in );

A2Methods_UArray2 decompress_float_to_compvid(A2Methods_UArray2 compvid_blocks)
{
        A2Methods_T methods = uarray2_methods_plain;
        assert(methods);

        A2Methods_UArray2 decompressed;
        decompressed = methods->new( methods->width( compvid_blocks ) ,                                        
                                        methods->height( compvid_blocks),
                                            sizeof( rgb_block ) );
        methods->map_row_major(decompressed, &apply_decompress, 
                                                        &compvid_blocks );
        methods->free(&compvid_blocks);
        return decompressed;
}
static void apply_decompress( int i, int j, A2Methods_UArray2 decompressed, 
                        A2Methods_Object * r_block, void * cl  )
{
        A2Methods_T methods = uarray2_methods_plain;
        A2Methods_UArray2 * tmp = cl;
        rgb_block * rgb = r_block;

        rgb->p1 = get_rgb(  ((compvid_block *)methods->at( *tmp, i, j ))->p1 );
        rgb->p2 = get_rgb( ((compvid_block *)methods->at( *tmp, i, j ))->p2 );
        rgb->p3 = get_rgb( ((compvid_block *)methods->at( *tmp, i, j ))->p3 );
        rgb->p4 = get_rgb( ((compvid_block *)methods->at( *tmp, i, j ))->p4 );
        (void) decompressed;
}

static rgb_float get_rgb(  compvid_pix in )
{       
        rgb_float pix;

        pix.red = 1.0 * (float)in.y + 0.0 * (float)in.pb + 1.402 * (float)in.pr;
        pix.green = 1.0 * (float)in.y - 0.344136 * (float)in.pb - 0.714136 * 
                                                        (float)in.pr;
        pix.blue = 1.0 * (float)in.y + 1.772 * (float)in.pb + 0.0 * (float)in.pr;

        return pix; 
}