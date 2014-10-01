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

#ifndef RGB 
#define RGB 
typedef struct {
        float red;
        float green;
        float blue; 
} rgb_float;

typedef struct {
        rgb_float p1;
        rgb_float p2;
        rgb_float p3;
        rgb_float p4;
} rgb_block;
#endif

extern A2Methods_UArray2 compress_rgb( FILE * fp );
extern Pnm_ppm decompress_block_to_rgb( A2Methods_UArray2 block_array );