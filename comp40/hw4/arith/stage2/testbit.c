
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bitpack.h"
#include <inttypes.h>

int main(int argc, char *argv[])
{
    uint64_t test = 0;
        
    // 	printf("%u", Bitpack_fitsu(5,3));
    //	printf("%i", Bitpack_fitss(5,3));

    // test = ~test; 
    // fprintf(stderr, "inverse test %" PRIu64 "\n", test);

    // test = test << 32;
    // fprintf(stderr, "l shift test %" PRIu64 "\n", test);


    // test = test >> 32; 
    // fprintf(stderr, "r shift test %" PRIu64 "\n", test);

 //        test = Bitpack_newu(test, 4, 0, 3);
 //        fprintf(stderr, "test P_b: %" PRIu64 "\n", test );

 //        test = Bitpack_newu(test, 4, 4, 8);
 //        fprintf(stderr, "test P_r: %" PRIu64 "\n", test );

        test = Bitpack_news(test, 5, 8, -13);
        fprintf(stderr, "test d: %" PRIu64 "\n", test );
        test = Bitpack_gets(test, 5, 8);
        fprintf(stderr, "word: %" PRIu64 "\n", test );
 //        test = Bitpack_news(test, 5, 13, 5);
 //        fprintf(stderr, "test c: %" PRIu64 "\n", test );

	// test = Bitpack_news(test, 5, 18, -1);
	// test = Bitpack_newu(test, 9, 23, 247);

	//  //printf("%" PRIu64, test);

	// //printf("%uint64_t", test);
 //    // fprintf(stderr, "test out: %" PRIu64 "\n", Bitpack_getu(test, 4, 0));
 //    // fprintf(stderr, "test out: %" PRIu64 "\n", Bitpack_getu(test, 4, 4));
 //        fprintf(stderr, "test pb: %" PRIu64 "\n", Bitpack_getu(test, 4, 0) );
 //        fprintf(stderr, "test pr: %" PRIu64 "\n", Bitpack_getu(test, 4, 4) );
 //        fprintf(stderr, "test d: %" PRId64 "\n", Bitpack_gets(test, 5, 8) );
 //        fprintf(stderr, "test c: %" PRId64 "\n", Bitpack_gets(test, 5, 13) );
 //        // fprintf(stderr, "test c: %x "\n", Bitpack_gets(test, 5, 13) );


 //    fprintf(stderr, "FINAL TEST %i \n", (int)test);
 //    printf( " %u \n", (unsigned)test);
    // uint64_t i;
    // int64_t n;

    // for (i = 0; i < 33; ++i)
    // {
    //     fprintf(stderr, "num: %" PRIu64 "->%i \n", i, Bitpack_fitsu( i, 5 ) );
    // }

    // for (n = -9; n < 9; ++n)
    // {
    //     fprintf(stderr, "num: %" PRId64 "->%i \n", n, Bitpack_fitss( n, 4 ) );
    // }


    return 0;
        //Bitpack_fitss(5,3);
	(void)argc;
	(void)argv;
 
}
