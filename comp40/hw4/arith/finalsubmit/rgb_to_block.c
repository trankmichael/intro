/*
 * COMPRESSION 
 *
 *    rgb_to_block.c
 *        Implementation of rgb_block.h  
 *        Purpose: compresses from a Pnm_ppm image read from stdin
 *                 to a UArray2 of 'rgb_block' -> 4 pixels of rgb floats 
 *      Edited on: March 2, 2014
 *      
 *      Tufts University COMP 40 
 *
 */


#include "rgb_block.h"

static void apply_rgb_to_block( int i, int j, A2Methods_UArray2 block_array, 
                        A2Methods_Object * block, void * cl );
static rgb_block get_neighbors( int i, int j, Pnm_ppm image );
static rgb_float rgb_to_float(Pnm_rgb temp, int denominator);

A2Methods_UArray2 compress_rgb( FILE * fp ) 
{ 
        A2Methods_T methods = uarray2_methods_plain;
        assert(methods);
        Pnm_ppm image = Pnm_ppmread( fp, methods );

        A2Methods_UArray2 compressed;
        int com_width;
        int com_height;

        com_width = image->methods->width( image->pixels ) / 2;
        com_height = image->methods->height( image->pixels ) / 2;

        
        compressed = image->methods->new(com_width, com_height, 
                                                sizeof(rgb_block));
        image->methods->map_row_major( compressed, &apply_rgb_to_block, 
                                                          &image );

        Pnm_ppmfree( &image );
        fclose( fp );        
        return compressed;
 
}

static void apply_rgb_to_block( int i, int j, A2Methods_UArray2 block_array, 
                        A2Methods_Object * block, void * cl )
{
        Pnm_ppm * image = cl;
        rgb_block * tmp = block;

        *tmp = get_neighbors(i*2, j*2, *image);
        
        (void) block_array;
        (void) i;
        (void) j;
}

static rgb_block get_neighbors( int i, int j, Pnm_ppm image )
{
        rgb_block neighbors;
        Pnm_rgb temp; 
        
        temp = image->methods->at(image->pixels , i, j );
        neighbors.p1 = rgb_to_float( temp, image->denominator );
        temp = image->methods->at(image->pixels , i + 1, j );
        neighbors.p2 = rgb_to_float( temp, image->denominator );
        temp = image->methods->at(image->pixels , i, j + 1 );
        neighbors.p3 = rgb_to_float( temp, image->denominator );
        temp = image->methods->at(image->pixels , i + 1, j + 1 );
        neighbors.p4 = rgb_to_float( temp, image->denominator );

        return neighbors;
}

static rgb_float rgb_to_float(Pnm_rgb temp, int denominator)
{
        rgb_float block;

        block.red = (float)temp->red / (float)denominator;
        block.green = (float)temp->green / (float)denominator;
        block.blue = (float)temp->blue / (float)denominator;

        return block;
}
