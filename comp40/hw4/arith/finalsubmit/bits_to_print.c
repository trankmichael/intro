#include "print_bits.h"
#include <inttypes.h>

/*
 * COMPRESSION 
 *
 *    bits_to_print.c:
 *        Implementation of print_bits.h  
 *        Purpose: compresses an image to the COMP40 compressed
 *                 image format from a UArray2 of 'uint64_t' codeword
 *      Edited on: March 2, 2014
 *      
 *      Tufts University COMP 40 
 *
 */

static void apply_pack( int i, int j, A2Methods_UArray2 code_words, 
                        A2Methods_Object * code_word, void * cl  );

void compress_bits_to_print(A2Methods_UArray2 code_words)
{
    A2Methods_T methods = uarray2_methods_plain;
    assert(methods);


    printf("COMP40 Compressed image format 2\n%u %u", methods->width
                        (code_words) , methods->height(code_words) );
    printf("\n");

    methods->map_row_major(code_words, &apply_pack, NULL);
    methods->free(&code_words);
}

static void apply_pack( int i, int j, A2Methods_UArray2 code_words, 
                        A2Methods_Object * code_word, void * cl  )
{
        uint64_t * word = code_word;
        int CODEWORD_SIZE = 32;
        unsigned lsb;
        int tmp;
        int char_size = 8;

        for ( unsigned y = CODEWORD_SIZE / char_size; y > 0 ; --y) {
                lsb = (y - 1) * char_size;
                tmp = Bitpack_getu( *word, char_size, lsb );
                putchar( tmp );
        }
        printf("\n");
        (void) i;
        (void) j;
        (void) code_words;
        (void) cl;
}
