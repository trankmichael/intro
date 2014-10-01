/*  
 *  a2plain.c 
 *      by: Michael Tran and Quinn Hood
 *      Last Edited On: February 17, 2014 
 *
 *  For: 
 *      Tufts University 
 *      COMP 40 HW 3 
 *  Purpose: 
 *      Implements A2Methods and hides implementation of UArray2
 */

#include <stdlib.h>
#include <a2plain.h>
#include "uarray2.h"

typedef A2Methods_UArray2 A2;

static A2 new(int width, int height, int size)
{
        return UArray2_new(width, height, size);
}

static A2 new_with_blocksize(int width, int height, int size,
                                            int blocksize)
{
        (void) blocksize;
        return UArray2_new(width, height, size);
}

static void a2free(A2 * UArray2)
{
        UArray2_free( (UArray2_T *) UArray2);
}

static int width(A2 UArray2)
{
        return UArray2_width(UArray2);
}

static int blocksize(A2 UArray2)
{
        (void) UArray2;
        return 1;
}

static int height(A2 UArray2)
{
        return UArray2_height(UArray2);
}

static int size(A2 UArray2)
{
        return UArray2_size(UArray2);
}

static A2Methods_Object *at(A2 UArray2, int i, int j)
{
        return UArray2_at(UArray2, i, j);
}

typedef void applyfun(int i, int j, UArray2_T UArray2, void *elem, void *cl);


struct reg_closure {
        A2Methods_applyfun *apply;
        A2 array2;
        void *cl;
};

static void apply_reg(int row, int col, UArray2_T UArray2, void *elem, void 
                                                                        *vcl)
{
        struct reg_closure *cl = vcl;
        (void) UArray2;
        cl->apply( row, col, cl->array2, elem, cl->cl );
}

static void map_row_major(A2 array2, A2Methods_applyfun apply, void *cl)
{
        struct reg_closure mycl = { apply, array2, cl };
        UArray2_map_row_major( array2, apply_reg, &mycl );
}

static void map_col_major(A2 array2, A2Methods_applyfun apply, void *cl)
{
        struct reg_closure mycl = { apply, array2, cl };
        UArray2_map_col_major( array2, apply_reg, &mycl );
}

struct small_closure {
        A2Methods_smallapplyfun *apply;
        void *cl;
};

static void apply_small(int i, int j, UArray2_T array2, void *elem, void 
                                                                        *vcl)
{
        struct small_closure *cl = vcl;
        (void)i;
        (void)j;
        (void)array2;
        cl->apply(elem, cl->cl);

}

static void small_map_row_major(A2 a2, A2Methods_smallapplyfun apply, void 
                                                                        *cl)
{
        struct small_closure mycl = { apply, cl };
        UArray2_map_row_major(a2, apply_small, &mycl);
}

static void small_map_col_major(A2 a2, A2Methods_smallapplyfun apply, void 
                                                                        *cl)
{
        struct small_closure mycl = { apply, cl };
        UArray2_map_col_major(a2, apply_small, &mycl);
}
static struct A2Methods_T uarray2_methods_plain_struct = {
        new,
        new_with_blocksize,
        a2free,
        width,
        height,
        size,
        blocksize,
        at,
        map_row_major,
        map_col_major,
        NULL,                   // map_block_major
        map_row_major,          // map_default
        small_map_row_major,
        small_map_col_major,
        NULL,                   // small_map_block_major
        small_map_row_major,    // small_map_default
};
                        
A2Methods_T uarray2_methods_plain = &uarray2_methods_plain_struct;
