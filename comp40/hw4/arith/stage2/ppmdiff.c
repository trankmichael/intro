#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "assert.h"
#include "uarray2.h"
#include "uarray2b.h"
#include "a2methods.h"
#include "a2plain.h"
#include "a2blocked.h"
#include "pnm.h"
#include <math.h>

static double cmp_files(FILE *fp1, FILE *fp2, A2Methods_T methods);
static void cmp_apply(int i, int j, A2Methods_UArray2 array2, A2Methods_Object *ptr, void *cl);

typedef struct closure {
	double   red_tally;
	double 	 green_tally;
	double 	 blue_tally;
	Pnm_ppm  cmp_rdr;
	double denominator;
} closure;

int main(int argc, char *argv[])
{
	if (argc != 3) {
		exit(1);
	}

	FILE *fp1 = fopen(argv[1], "r");
	FILE *fp2 = fopen(argv[2], "r");
	A2Methods_T methods = uarray2_methods_plain;

	assert(fp1);
	assert(fp2);

	cmp_files(fp1, fp2, methods);

	return 0;

}

static double cmp_files(FILE *fp1, FILE *fp2, A2Methods_T methods)
{

	Pnm_ppm rdr1 = Pnm_ppmread(fp1, methods);
	Pnm_ppm rdr2 = Pnm_ppmread(fp2, methods);

	int widthdiff = abs(rdr1->width - rdr2->width);
	int heightdiff = abs(rdr1->height - rdr2->height);

	assert(widthdiff <= 1 && heightdiff <= 1);

	closure cl = { 0.0, 0.0, 0.0, rdr2, rdr1->denominator };

	methods->map_row_major(rdr1->pixels, cmp_apply, &cl);


	double rgb_tally = cl.red_tally + cl.green_tally + cl.blue_tally;

	double e = sqrt(rgb_tally / (3 * methods->width(rdr1->pixels) * methods->height(rdr1->pixels)));

	printf("%f\n", e);

	return 2.0;
}

static void cmp_apply(int i, int j, A2Methods_UArray2 array2, A2Methods_Object *ptr, void *cl)
{
	Pnm_rgb pixel1 = (Pnm_rgb)ptr;
	Pnm_rgb pixel2 = NULL;
	closure *clp   = (closure *)cl;
	double rtally, gtally, btally;

	Pnm_ppm cmp_rdr           = clp->cmp_rdr;
	const A2Methods_T methods = (const A2Methods_T)cmp_rdr->methods;

	pixel2 = (Pnm_rgb)methods->at(cmp_rdr->pixels, i, j);

	rtally = abs(((float)pixel1->red - (float)pixel2->red)) / (float)clp->denominator;
	rtally = rtally * rtally;

	gtally = abs(((float)pixel1->green - (float)pixel2->green)) / (float)clp->denominator;
	gtally = gtally * gtally;

	btally = abs(((float)pixel1->blue - (float)pixel2->blue)) / (float)clp->denominator;
	btally = btally * btally;

	clp->red_tally = rtally;
	clp->green_tally = gtally;
	clp->blue_tally = btally;

	(void)array2;

}