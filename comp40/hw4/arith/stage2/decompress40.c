#include "compress40.h"
#include "rgb_block.h"
#include "float_compvid.h"
#include "test_compvid.h"
#include "test_bits.h"
#include "print_bits.h"

extern void decompress40(FILE *input)
{
	Pnm_ppm image;
	A2Methods_UArray2 temp;
	temp = decompress_print_to_bits(input);
	temp = decompress_bits_to_test(temp);
	temp = decompress_test_to_compvid(temp);
	temp = decompress_float_to_compvid(temp);
	image = decompress_block_to_rgb( temp );
	Pnm_ppmwrite( stdout, image );
	Pnm_ppmfree( &image );
}
