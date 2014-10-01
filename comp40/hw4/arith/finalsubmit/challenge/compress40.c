#include "compress40.h"
#include "rgb_block.h"
#include "float_compvid.h"
#include "test_compvid.h"
#include "test_bits.h"
#include "print_bits.h"

extern void compress40(FILE *input)
{
        A2Methods_UArray2 temp;
        temp = compress_rgb(input);
        temp = compress_float_to_compvid(temp);
        temp = compress_compvid_to_test(temp);
        temp = compress_test_to_bits(temp);
        compress_bits_to_print(temp);
}
