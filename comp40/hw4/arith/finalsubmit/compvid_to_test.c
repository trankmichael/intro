#include "test_compvid.h"

/*
 * COMPRESSION 
 *
 *    compvid_to_test.c:
 *        Implementation of test_compvid.h  
 *        Purpose: compresses a UArray_2 of 'compvid_blocks' (y, pb, pr ) 
 *                 to a UArray_2 of 'Test' (a, b, c, d, P_b, P_r)
 *      Edited on: March 2, 2014
 *      
 *      Tufts University COMP 40 
 *
 */


static void apply_compress( int i, int j, A2Methods_UArray2 compvid_blocks, 
                        A2Methods_Object * cv_block, void * cl  );

static unsigned get_index_pb(compvid_block block);
static unsigned get_index_pr(compvid_block block);

static unsigned get_a( compvid_block block );
static signed int get_b( compvid_block block );
static signed int get_c( compvid_block block );
static signed int get_d( compvid_block block );

static unsigned normalize_a( float val );
static signed int normalize_bcd( float val );

static inline float force_float( float val, float max, float min )
{
        if( val > max )
                return max;
        if( val < min )
                return min;
        else
                return val;
}

A2Methods_UArray2 compress_compvid_to_test(A2Methods_UArray2 compvid_blocks)
{
        A2Methods_T methods = uarray2_methods_plain;
        assert(methods);

        A2Methods_UArray2 compressed;
        compressed = methods->new( methods->width( compvid_blocks ) ,     
                                        methods->height( compvid_blocks),
                                            sizeof( Test ) );
        methods->map_row_major(compvid_blocks, &apply_compress, 
                                                        &compressed );
        methods->free(&compvid_blocks);
        return compressed;
}

static void apply_compress( int i, int j, A2Methods_UArray2 compvid_blocks, 
                        A2Methods_Object * cv_block, void * cl  )
{
        A2Methods_T methods = uarray2_methods_plain;
        assert(methods);

        A2Methods_UArray2 * tests;
        Test * test;
        compvid_block * block;
        unsigned pb, pr;

        tests = cl;
        test = methods->at( *tests, i, j );
        block = cv_block;
        pb = get_index_pb( *block );
        pr = get_index_pr( *block );

        test->a = get_a( *block );
        assert( (test->a <= 511) );
        test->b = get_b( *block );
        assert( (test->b <= 15) && (test->b >= -15) );
        test->c = get_c( *block );
        assert( (test->c <= 15) && (test->c >= -15) );
        test->d = get_d( *block );
        assert( (test->d <= 15) && (test->d >= -15) );
        test->P_b = pb;
        test->P_r = pr; 

        (void) compvid_blocks;

}

static unsigned get_index_pb(compvid_block block)
{
        float avg = 0;


        avg = (block.p1.pb + block.p2.pb + block.p3.pb + block.p4.pb) / 4.0;

        return Arith40_index_of_chroma(avg);
}

static unsigned get_index_pr(compvid_block block)
{
        float avg = 0;
        avg = (block.p1.pr + block.p2.pr + block.p3.pr + block.p4.pr) / 4.0;

        return Arith40_index_of_chroma(avg);
}

static unsigned get_a( compvid_block block )
{
        float sum;
        sum = (block.p4.y + block.p3.y + block.p2.y + block.p1.y) / 4.0;
        return normalize_a( sum );
}
static signed int get_b( compvid_block block )
{
        float sum;
        sum = (block.p4.y + block.p3.y - block.p2.y - block.p1.y) / 4.0;
        return normalize_bcd( sum );
}
static signed int get_c( compvid_block block )
{
        float sum;
        sum = (block.p4.y - block.p3.y + block.p2.y - block.p1.y) / 4.0;
        return normalize_bcd( sum );
}
static signed int get_d( compvid_block block )
{
        float sum;
        sum = (block.p4.y - block.p3.y - block.p2.y + block.p1.y) / 4.0;
        return normalize_bcd( sum );
}
static unsigned normalize_a( float val )
{
        val = force_float( val, 1, 0 );
        return roundf(val * 511.0);
}
static signed int normalize_bcd( float val )
{
        val = force_float( val, 0.3, -0.3);
        return (signed int) roundf(val * 50.0);

}
