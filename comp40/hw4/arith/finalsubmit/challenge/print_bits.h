#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include "arith40.h"
#include "pnm.h"
#include "a2methods.h"
#include "a2plain.h"
#include "compress40.h"
#include "bitpack.h"


extern void compress_bits_to_print(A2Methods_UArray2 code_words);
extern A2Methods_UArray2 decompress_print_to_bits( FILE * in );
