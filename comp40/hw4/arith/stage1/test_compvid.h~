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

extern A2Methods_UArray2 compress_compvid_to_test(A2Methods_UArray2 compvid_blocks);
extern A2Methods_UArray2 decompress_test_to_compvid(A2Methods_UArray2 tests);