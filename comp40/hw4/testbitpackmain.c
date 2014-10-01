#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "bitpack.h"
#include <except.h>
#include <assert.h>


static bool check_laws( uint64_t word, unsigned w, unsigned lsb, uint64_t val, 
                                                unsigned w2, unsigned lsb2 )
static bool check_fl( )
int main(int argc, char *argv[])
{

        FILE *randfp;
        randfp = fopen("/dev/urandom", "rb");

        assert(randfp);

        uint64_t word, w2, lsb2;
        size_t rc; 

        for( unsigned w = 0; w <= 64; w++ ) {
                for ( unsigned lsb = 0; lsb + w <= 64; lsb++ ) {
                        for (unsigned trial = 0; trial < 1000; trial++ ) {
                                assert(randfp);
                                rc = fread(&word, sizeof(word), 1, randfp);
                                assert(rc == 1);

                                rc = fread( &w2, sizeof(w2), 1, randfp );
                                assert(rc == 1);
                                w2 = w2 % 64; 

                                rc = fread( &lsb2, sizeof(lsb2), 1, randfp );
                                assert(rc == 1);
                                lsb2 = lsb2 % 64; 

                                rc = fread( &val, sizeof(val), 1, randfp );
                                val = val >> 
                                assert(rc == 1);


                                if ( lsb2 + w2 <= 64 ) {
                                        TRY
                                                assert( check_laws( word, w, 
                                                        lsb, val, w2, lsb2 ) );
                                        ELSE
                                                fprintf(stderr, "Exception 
                                                        raised during testing");
                                        END_TRY;
                                }

                        }
                }


        }

        fclose(randfp);

}


check_laws(uint64_t word, unsigned w, unsigned lsb, uint64_t val, unsigned w2, 
                                                                unsigned lsb2)                                                                                                                                                                                                                                                                                                                                                                                                                                          )
{

        getu( newu( word,w,lsb,val) ) == Bitpack_getu

}