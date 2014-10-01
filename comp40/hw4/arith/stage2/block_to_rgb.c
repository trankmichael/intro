/*
 * DECOMPRESSION 
 *
 *    block_to_rgb.c
 *        Implementation of rgb_block.h  
 *        Purpose: decompresses to a Pnm_ppm image from a UArray2 
 *                 of 'rgb_block' -> 4 pixels of rgb floats 
 *      Edited on: March 2, 2014
 *      
 *      Tufts University COMP 40 
 *
 */


#include "rgb_block.h"

const int DENOMINATOR = 255; 

static void apply_rgb_to_block( int i, int j, A2Methods_UArray2 block_array, 
                        A2Methods_Object * block, void * cl );
static void set_rgb_pixels(Pnm_ppm image, int i, int j, rgb_block block);
static void float_to_rgb(rgb_float pix, Pnm_rgb block);

static inline float force_float( float val, float max, float min )
{
        if( val > max )
                return max;
        if( val < min )
                return min;
        else
                return val;
}

Pnm_ppm decompress_block_to_rgb( A2Methods_UArray2 block_array ) 
{ 
        A2Methods_T methods = uarray2_methods_plain;
        assert(methods);
        Pnm_ppm image;
        NEW(image);

        image->methods = methods;
        image->denominator = DENOMINATOR;
        
        
        image->width = image->methods->width( block_array ) * 2;
        image->height = image->methods->height( block_array ) * 2;

        image->pixels = image->methods->new(image->width, image->height, sizeof(struct Pnm_rgb));
        image->methods->map_row_major( block_array, &apply_rgb_to_block, &image );
        methods->free(&block_array);
        
        return image;
}

static void apply_rgb_to_block( int i, int j, A2Methods_UArray2 block_array, 
                        A2Methods_Object * block, void * cl )
{
        Pnm_ppm * image = cl;

        set_rgb_pixels( *image, i * 2, j * 2, *(rgb_block *)block );

        
        (void) block_array;
        (void) i;
        (void) j;
}

static void set_rgb_pixels(Pnm_ppm image, int i, int j, rgb_block block)
{
        Pnm_rgb temp; 
        temp = image->methods->at(image->pixels , i, j );
        float_to_rgb(block.p1, temp);
        temp = image->methods->at(image->pixels , i + 1, j );
        float_to_rgb(block.p2, temp);
        temp = image->methods->at(image->pixels , i, j + 1 );
        float_to_rgb(block.p3, temp);
        temp = image->methods->at(image->pixels , i + 1, j + 1 );
        float_to_rgb(block.p4, temp);

}

static void float_to_rgb(rgb_float pix, Pnm_rgb out)
{  
        float red, green, blue;


        red = force_float( pix.red * (float)DENOMINATOR, (float) DENOMINATOR, 0 );
        green = force_float( pix.green * (float)DENOMINATOR, (float) DENOMINATOR, 0 );
        blue = force_float( pix.blue * (float)DENOMINATOR, (float) DENOMINATOR, 0 );

        out->red = roundf( red );
        out->blue = roundf( blue );
        out->green = roundf( green );


}