#include "rgb_block.h"
#include "float_compvid.h"
#include "test_compvid.h"
#include "test_bits.h"
#include "print_bits.h"

int main(int argc, char *argv[])
{
        Pnm_ppm image; 
        A2Methods_UArray2 temp;
        
        // temp = compress_rgb( stdin);
        // temp = compress_float_to_compvid(temp);
        // temp = compress_compvid_to_test(temp);
        // temp = compress_test_to_bits(temp);
        // compress_bits_to_print( temp );


        temp = decompress_print_to_bits( stdin );
        temp = decompress_bits_to_test(temp);
        temp = decompress_test_to_compvid(temp);
        temp = decompress_float_to_compvid(temp);
        image = decompress_block_to_rgb( temp );

        Pnm_ppmwrite( stdout, image );
        Pnm_ppmfree( &image );


        (void) argc;
        (void) argv;
        (void) image;
}
