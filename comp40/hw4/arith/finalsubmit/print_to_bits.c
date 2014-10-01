#include "print_bits.h"
#include <inttypes.h>

/*
 * DECOMPRESSION 
 *
 *    prints_to_bits.c :
 *        Implementation of print_bits.h  
 *        Purpose: decompresses an image in the COMP40 compressed
 *                 image format to a UArray2 of 'uint64_t' codeword
 *      Edited on: March 2, 2014
 *      
 *      Tufts University COMP 40 
 *
 */
 
static void assign_words( A2Methods_UArray2 words, FILE * in, 
                                                A2Methods_T methods );

A2Methods_UArray2 decompress_print_to_bits(FILE * in)
{
        unsigned height, width;
        int read = fscanf(in, "COMP40 Compressed image format 2\n%u %u", 
                                                            &width, &height);
        assert(read == 2);
        int c = getc(in);
        assert(c == '\n');

        A2Methods_T methods = uarray2_methods_plain;
        assert(methods);
        A2Methods_UArray2 words;

        words = methods->new( width, height, sizeof( uint64_t ) );
        assign_words( words, in, methods );
        return words;
}

static void assign_words( A2Methods_UArray2 words, FILE * in, 
                                                A2Methods_T methods ) 
{
        uint64_t * word;
        uint64_t tmp2;
        char tmp;

        for (int i = 0; i < methods->height(words) ; ++i)
        {
                for (int j = 0; j < methods->width(words) ; ++j)
                {    
                        word = methods->at( words, j, i);
                        tmp = getc(in);
                        tmp2 = Bitpack_getu( (uint64_t)tmp, 8, 0);
                        *word = Bitpack_newu( *word, 8, 24, tmp2 );
                        tmp = getc(in);
                        tmp2 = Bitpack_getu( (uint64_t)tmp, 8, 0);
                        *word = Bitpack_newu( *word, 8, 16, tmp2 );
                        tmp = getc(in);
                        tmp2 = Bitpack_getu( (uint64_t)tmp, 8, 0);
                        *word = Bitpack_newu( *word, 8, 8, tmp2 );
                        tmp = getc(in);
                        tmp2 = Bitpack_getu( (uint64_t)tmp, 8, 0);
                        *word = Bitpack_newu( *word, 8, 0, tmp2 );
                        tmp = getc(in);
                }
        }
        (void) tmp;
        (void) word;
}
