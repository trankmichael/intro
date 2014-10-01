#include "bitpack.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

Except_T Bitpack_Overflow = { "Overflow packing bits" };
static uint64_t clear_space( uint64_t word, unsigned lsb, unsigned width );
static uint64_t get_signed_mask( uint64_t val, unsigned lsb, unsigned width );


static inline uint64_t shift_right_unsigned( uint64_t word, unsigned offset )
{
        uint64_t out;
        if ( offset == 64) {
                out = 0;
        }
        else {
                out = word >> offset;
        }

        return out;
        
}

static inline uint64_t shift_left( uint64_t word, unsigned offset )
{
        uint64_t out;
        if ( offset == 64) {
                out = 0;
        }
        else {
                out = word << offset;
        }

        return out;
}

static inline uint64_t get_last_bit( int64_t word, unsigned width ) 
{
        uint64_t mask = ~0;
        mask = shift_left( mask, 63 );
        mask = shift_right_unsigned( mask, 64 - width );
        mask = ( mask & word );
        mask = shift_right_unsigned( mask, width -1 );
        return mask;
}

static inline int64_t shift_right_signed( int64_t word, unsigned offset, unsigned width )
{
        uint64_t mask;
        word = shift_right_unsigned( word, offset );

        uint64_t last_bit = get_last_bit( word, width ); 

        if( offset == 64 ){
                return 0;
        }
        else if ( last_bit == 1 ) {
                mask = ~0;
                mask = shift_left( mask, ( width ) );
                word = ( word | mask );;
        }    
        
   
        return word;
}



bool Bitpack_fitsu(uint64_t n, unsigned width)
{
        uint64_t upperbound = 1; 
        upperbound = shift_left( upperbound, width );
        if ( n < upperbound) {
                return true;
        }
                return false;
}

bool Bitpack_fitss( int64_t n, unsigned width)
{
        int64_t lowerbound = ~0;

        lowerbound = shift_right_signed( lowerbound, width - 1, 0 );
        lowerbound = shift_left( lowerbound, width - 1 );
    
        if ( (n <= ~lowerbound) && (n >= lowerbound) ) {
                return true;
        }
        return false;
}

uint64_t Bitpack_getu(uint64_t word, unsigned width, unsigned lsb)
{
	uint64_t mask = ~0;
	uint64_t newword;

        mask = shift_right_unsigned( mask, (64 - width) );
        mask = shift_left(mask, lsb);

        newword = word & mask;
        newword = shift_right_unsigned( newword, lsb );
	return newword;
}


int64_t Bitpack_gets(uint64_t word, unsigned width, unsigned lsb)
{
        uint64_t mask = ~0;
        int64_t newword;

        /* gets you the word */
        mask = shift_right_unsigned( mask, (64 - width) );
        mask = shift_left(mask, lsb);
        newword = word & mask;

        /* propogates ones or zeros */
        newword = shift_right_signed( newword, lsb, width );
        return newword;
}

uint64_t Bitpack_newu(uint64_t word, unsigned width, unsigned lsb,
                                                        uint64_t value)
{
        if( (width > 64) ) {
                RAISE(Bitpack_Overflow);
        }
        if( (width + lsb) > 64 ) {
                RAISE(Bitpack_Overflow);
        }
	uint64_t mask = 0;
        uint64_t newword = 0;
    
        word = clear_space( word, lsb, width );
        mask = ( mask | value ) << lsb;
        // fprintf(stderr, "word %i \n", (int)word );

	newword = (word | mask);
        // fprintf(stderr, "newword %i \n", (int)newword );
	// newword = (newword | (value << lsb));
        // if( Bitpack_getu(newword, width, lsb) != value )
        // {
        //         exit(1);
        // }
	return newword;
}

uint64_t Bitpack_news(uint64_t word, unsigned width, unsigned lsb,  
                                                        int64_t value)
{   
        if( (width > 64) ) {
                RAISE(Bitpack_Overflow);
        }
        if( (width + lsb) > 64 ) {
                RAISE(Bitpack_Overflow);
        }       

        uint64_t mask;

        word = clear_space( word, lsb, width );
        mask = get_signed_mask( value, lsb, width );

        word = ( mask | word );

        if( Bitpack_gets(word, width, lsb) != value )
        {
                exit(1);
        }
        return word;
}

static uint64_t clear_space( uint64_t word, unsigned lsb, unsigned width )
{
        uint64_t mask = ~0;
        mask = mask << ( 64 - width );
        mask = mask >> ( 64 - (width + lsb) );
        mask = ~mask;

        // fprintf(stderr, "mask %" PRIu64 "\n", mask);
        word = ( word & mask );
        // fprintf(stderr, "word %" PRIu64 "\n", word);
        return word;
}

static uint64_t get_signed_mask( uint64_t val, unsigned lsb, unsigned width )
{
        uint64_t mask = ~0;
        mask = mask << ( 64 - width );
        mask = mask >> ( 64 - (width + lsb) );

        //fprintf(stderr, "mask %" PRIu64 "\n", mask);

        val = val << lsb;
        //fprintf(stderr, "val %" PRIu64 "\n", val);
        val = ( val & mask );

        //fprintf(stderr, "val %" PRIu64 "\n", val);

        return val;
}
