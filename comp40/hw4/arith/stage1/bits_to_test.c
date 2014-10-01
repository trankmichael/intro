#include "test_bits.h"


//// 1 DECOMPRESSING 

static void apply_unpack( int i, int j, A2Methods_UArray2 compressed, 
                        A2Methods_Object * test, void * cl  );
static void unpack_a(uint64_t word, Test * test_block);
static void unpack_bcd(uint64_t word, Test * test_block);
static void unpack_pbpr(uint64_t word, Test * test_block);

A2Methods_UArray2 decompress_bits_to_test(A2Methods_UArray2 code_words)
{
        A2Methods_T methods = uarray2_methods_plain;
        assert(methods);

        A2Methods_UArray2 tests;
        tests = methods->new( methods->width( code_words ) ,     
                                methods->height( code_words ),
                                    sizeof( Test ) );
        methods->map_row_major(tests, &apply_unpack, 
                                         &code_words );
        methods->free( &code_words );
        return tests;
}

static void apply_unpack( int i, int j, A2Methods_UArray2 tests, 
                        A2Methods_Object * test, void * cl  )
{
        A2Methods_T methods = uarray2_methods_plain;
        A2Methods_UArray2 * words = cl;
       	Test * tmp = test; 
        uint64_t * code_word = methods->at( *words, i, j );

        unpack_a(*code_word, tmp);
        unpack_bcd(*code_word, tmp);
        unpack_pbpr(*code_word, tmp);

        // if ( (i < 100) && (j < 100) )
        // {
        //         // fprintf(stderr, "TEST out \n");  
        //         printf( "   pb in %u \n", tmp->P_b);
        //         printf( "   pr in %u \n", tmp->P_r);   
        //         printf( "   a in %u \n", tmp->a);
        //         printf( "   b in %u \n", tmp->b);
        //         printf( "   c in %u \n", tmp->c);
        //         printf( "   d in %u \n", tmp->d);  
                

        // }

        (void) tests;
}

static void unpack_a(uint64_t word, Test * test_block)
{
        test_block->a = Bitpack_getu(word, 9, 23 ) ;
}

static void unpack_bcd(uint64_t word, Test * test_block)
{
        test_block->b = Bitpack_gets(word, 5, 18 ) ;   
        test_block->c = Bitpack_gets(word, 5, 13 ) ;
        test_block->d = Bitpack_gets(word, 5, 8 ) ;
}

static void unpack_pbpr(uint64_t word, Test * test_block)
{
        test_block->P_b = Bitpack_getu(word, 4, 4 ) ;
        test_block->P_r = Bitpack_getu(word, 4, 0 ) ;
}


