#include "rgb_block.h"
#include "float_compvid.h"
#include "test_compvid.h"
#include "test_bits.h"

int main(int argc, char *argv[])
{
        Pnm_ppm image; 
        A2Methods_UArray2 temp;
        temp = compress_rgb( stdin);
        // temp = compress_float_to_compvid(temp);
        // temp = compress_compvid_to_test(temp);
        // // temp = compress_test_to_bits(temp);
        // // temp = decompress_bits_to_test(temp);
        // temp = decompress_test_to_compvid(temp);
        // temp = decompress_float_to_compvid(temp);
        image = decompress_block_to_rgb( temp );
        Pnm_ppmwrite( stdout, image );
        (void) argc;
        (void) argv;
        (void) image;
}
