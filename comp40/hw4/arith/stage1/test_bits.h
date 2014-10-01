#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include "arith40.h"
#include "pnm.h"
#include "a2methods.h"
#include "a2plain.h"
#include "compress40.h"
#include "math.h"
#include "mem.h"
#include "bitpack.h"

#ifndef TEST
#define TEST
typedef struct {
        unsigned a; 
        signed int b;
        signed int c;
        signed int d;
        unsigned P_b;
        unsigned P_r;

} Test; 

#endif


extern A2Methods_UArray2 compress_test_to_bits(A2Methods_UArray2 test_array);
extern A2Methods_UArray2 decompress_bits_to_test(A2Methods_UArray2 test_array);

