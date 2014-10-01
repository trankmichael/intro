#include "test_compvid.h"

//// 2 DECOMPRESSING 


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
       // methods->free( &tests );
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
        return (float)a / 511.0;
}

static float int_to_floatbcd( int bcd )
{
        return (float)bcd / 50.0;
}



/* decompress v.1 */

// static void apply_decompress( int i, int j, A2Methods_UArray2 decompressed, 
//                         A2Methods_Object * test, void * cl  );
// static compvid_block test_to_block( Test compressed );
// static compvid_block set_pb_pr( compvid_block block, Test comp );
// static compvid_block set_y( compvid_block block, Test comp );
// static float convert_a(unsigned val);
// static float convert_bcd(signed val);


// A2Methods_UArray2 decompress_test_to_compvid(A2Methods_UArray2 tests)
// {
//         A2Methods_T methods = uarray2_methods_plain;
//         assert(methods);

//         A2Methods_UArray2 decompressed;
//         decompressed = methods->new( methods->width( tests ) ,     
//                                         methods->height( tests),
//                                             sizeof( compvid_block ) );
//         methods->map_row_major(tests, &apply_decompress, 
//                                                         &decompressed );
//         return decompressed;
// }

// static void apply_decompress( int i, int j, A2Methods_UArray2 decompressed, 
//                         A2Methods_Object * test, void * cl  )
// {
//         A2Methods_T methods = uarray2_methods_plain;
//         A2Methods_UArray2 * tmp = cl;
//         Test * test_block = test; 
//         compvid_block * block = methods->at( *tmp, i, j );

//         *block = test_to_block( *test_block );

//         // if( (i < 3 ) && ( j < 3 ) ) {
//         //     fprintf(stderr, "pb out: %f \n", block->p1.pb );
//         //     fprintf(stderr, " pr out: %f \n", block->p1.pr );
//         //     fprintf(stderr, "  y out: %f \n", block->p1.y );
//         // }

//         (void) decompressed;


//         // if( (i == 0 ) && ( j == 0 ) ) {
//         //     fprintf(stderr, "a in: %d \n", test_block->a  );
//         //     fprintf(stderr, "b in: %d \n", test_block->b  );
//         //     fprintf(stderr, "c in: %d \n", test_block->c );
//         //     fprintf(stderr, "d in: %d \n", test_block->d );
//         // }
// }


// static compvid_block test_to_block( Test compressed )
// {
//         compvid_block block; 
//         block = set_y( block, compressed );
//         block = set_pb_pr( block, compressed );

//         return block;
// }

// static compvid_block set_pb_pr( compvid_block block, Test comp )
// {
//         float pb = Arith40_chroma_of_index( comp.P_b );
//         float pr = Arith40_chroma_of_index( comp.P_r );
//         // fprintf( stderr, " pb: %f ",  pb);
//         // fprintf( stderr, " pr: %f ", pr );

//         block.p1.pb = pb;
//         block.p1.pr = pr;
//         block.p2.pb = pb;
//         block.p2.pr = pr;
//         block.p3.pb = pb;
//         block.p3.pr = pr;
//         block.p4.pb = pb;
//         block.p4.pr = pr;
//         return block;
// }

// static compvid_block set_y( compvid_block block, Test comp )
// {
//         float a, b, c, d;
//         a = convert_a(comp.a);
//         b = convert_bcd(comp.b);
//         c = convert_bcd(comp.c);
//         d = convert_bcd(comp.d);

//         block.p1.y = a - b - c + d;
//         block.p2.y = a - b + c - d;
//         block.p3.y = a + b - c - d;
//         block.p4.y = a + b + c + d;
//         return block;
// }

// static float convert_a(unsigned val)
// {
//         float out;

//         out = (float)val / 511.0;

//         return out;
// }

// static float convert_bcd(signed val)
// {
//         float out;

//         out = (float)val / 50.0;

//         return out;
// }