#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include "arith40.h"
#include "mem.h"
#include "pnm.h"
#include "a2methods.h"
#include "a2plain.h"
#include "compress40.h"
#include "math.h"

#ifndef COMPVID
#define COMPVID
typedef struct {
        float y;
        float pb;
        float pr;
} compvid_pix;

typedef struct {
        compvid_pix p1;
        compvid_pix p2;
        compvid_pix p3;
        compvid_pix p4;
} compvid_block;
#endif

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

extern A2Methods_UArray2 compress_float_to_compvid(A2Methods_UArray2 float_blocks);

extern A2Methods_UArray2 decompress_float_to_compvid(A2Methods_UArray2 compvid_blocks);