/*
 * COMPRESSION 
 *
 *    test_to_bits.c:
 *        Implementation of test_bits.h  
 *        Purpose: compresses to a UArray_2 of uint64_t codewords 
 *                 from a UArray_2 of 'Test' (a, b, c, d, P_b, P_r)
 *      Edited on: March 2, 2014
 *      
 *      Tufts University COMP 40 
 *
 */

#include "test_bits.h"
#include <inttypes.h>

static void apply_pack( int i, int j, A2Methods_UArray2 compressed, 
                        A2Methods_Object * test, void * cl  );
static void pack_a(uint64_t * word, Test test_block);
static void pack_bcd(uint64_t * word, Test test_block);
static void pack_pbpr(uint64_t * word, Test test_block);


A2Methods_UArray2 compress_test_to_bits(A2Methods_UArray2 test_array)
{
        A2Methods_T methods = uarray2_methods_plain;
        assert(methods);

        A2Methods_UArray2 code_words;
        code_words = methods->new( methods->width( test_array ) ,     
                                        methods->height( test_array ),
                                            sizeof( uint64_t ) );
        methods->map_row_major(code_words, &apply_pack, 
                                                        &test_array );
        
        methods->free(&test_array);                                                        
        return code_words;
}

static void apply_pack( int i, int j, A2Methods_UArray2 code_words, 
                        A2Methods_Object * code_word, void * cl  )
{
        A2Methods_T methods = uarray2_methods_plain;
        A2Methods_UArray2 * tmp = cl;
        uint64_t * word = code_word; 
        Test * test_block = methods->at( *tmp, i, j );

        pack_a(word, *test_block);
        pack_bcd(word, *test_block);
        pack_pbpr(word, *test_block);
        (void) code_words;
}

static void pack_a(uint64_t * word, Test test_block)
{
        *word = Bitpack_newu(*word, 6, 26, test_block.a);
}

static void pack_bcd(uint64_t * word, Test test_block)
{
        *word = Bitpack_news(*word, 6, 20, test_block.b);
        *word = Bitpack_news(*word, 6, 14, test_block.c);
        *word = Bitpack_news(*word, 6, 8, test_block.d);

}

static void pack_pbpr(uint64_t * word, Test test_block)
{
        *word = Bitpack_newu(*word, 4, 4, test_block.P_b);
        *word = Bitpack_newu(*word, 4, 0, test_block.P_r);
}


