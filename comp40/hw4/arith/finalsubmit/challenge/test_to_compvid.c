#include "test_compvid.h"

/*
 * DECOMPRESSION 
 *
 *    test_to_compvid.c:
 *        Implementation of test_compvid.h  
 *        Purpose: decompresses to a UArray_2 of 'compvid_blocks' (y, pb, pr ) 
 *                 from a UArray_2 a 'Test' (a, b, c, d, P_b, P_r)
 *      Edited on: March 2, 2014
 *      
 *      Tufts University COMP 40 
 *
 */

static void apply_decompress( int i, int j, A2Methods_UArray2 decompressed, 
                        A2Methods_Object * test, void * cl  );
static compvid_pix set_p1( Test test, float pb, float pr );
static compvid_pix set_p2( Test test, float pb, float pr );
static compvid_pix set_p3( Test test, float pb, float pr );
static compvid_pix set_p4( Test test, float pb, float pr );
static float int_to_floata( int a );
static float int_to_floatbcd( int y );

static inline float force_float( float val, float max, float min )
{
        if( val > max )
                return max;
        if( val < min )
                return min;
        else
                return val;
}

A2Methods_UArray2 decompress_test_to_compvid(A2Methods_UArray2 tests)
{
        A2Methods_T methods = uarray2_methods_plain;
        assert(methods);

        A2Methods_UArray2 decompressed;
        decompressed = methods->new( methods->width( tests ) ,     
                                        methods->height( tests),
                                            sizeof( compvid_block ) );
        methods->map_row_major(decompressed, &apply_decompress, 
                                                        &tests );
        methods->free(&tests);
        return decompressed;
}


/* decompress v2 */ 
static void apply_decompress( int i, int j, A2Methods_UArray2 blocks, 
                                A2Methods_Object * block, void *cl)
{
        A2Methods_T methods = uarray2_methods_plain;
        A2Methods_UArray2 * test_array = cl;
        Test * test = methods->at( *test_array, i, j );
        compvid_block * out = block;
        float pb, pr;

        pb = Arith40_chroma_of_index( test->P_b );
        pr = Arith40_chroma_of_index( test->P_r );

        out->p1 = set_p1( *test, pb, pr );
        out->p2 = set_p2( *test, pb, pr );
        out->p3 = set_p3( *test, pb, pr );
        out->p4 = set_p4( *test, pb, pr );
        (void) blocks;
}

static compvid_pix set_p1( Test test, float pb, float pr )
{
        compvid_pix out;
        out.pb = force_float( pb, .05, -.05 );
        out.pr = force_float( pr, .05, -.05 );
        
        out.y = int_to_floata(test.a) - int_to_floatbcd(test.b)
                - int_to_floatbcd(test.c) + int_to_floatbcd(test.d);
        
        out.y = force_float( out.y, 1, 0);
        return out; 
}
static compvid_pix set_p2( Test test, float pb, float pr )
{
        compvid_pix out;
        out.pb = force_float( pb, .05, -.05 );
        out.pr = force_float( pr, .05, -.05 );
        
        out.y = int_to_floata(test.a) - int_to_floatbcd(test.b)
                + int_to_floatbcd(test.c) - int_to_floatbcd(test.d);
        
        
        out.y = force_float( out.y, 1, 0);
        return out; 
}
static compvid_pix set_p3( Test test, float pb, float pr )
{
        compvid_pix out;
        out.pb = force_float( pb, .05, -.05 );
        out.pr = force_float( pr, .05, -.05 );
        
        out.y = int_to_floata(test.a) + int_to_floatbcd(test.b)
                - int_to_floatbcd(test.c) - int_to_floatbcd(test.d);
        
        out.y = force_float( out.y, 1, 0);
        return out; 
}
static compvid_pix set_p4( Test test, float pb, float pr )
{
        compvid_pix out;
        out.pb = force_float( pb, .05, -.05 );
        out.pr = force_float( pr, .05, -.05 );
        
        out.y = int_to_floata(test.a) + int_to_floatbcd(test.b)
                + int_to_floatbcd(test.c) + int_to_floatbcd(test.d);
        
        out.y = force_float( out.y, 1, 0);
        return out; 
}

static float int_to_floata( int a )
{
        return (float)a / 63.0;
}

static float int_to_floatbcd( int bcd )
{
        return (float)bcd / 31.0;
}
