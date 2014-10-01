/******************************************************************************
 * segments.h
 * Universal Machine - Homework 6
 * By: Jon Arbaugh and Michael Tran
 *
 * This file is the interface to the segmented memory
 *****************************************************************************/

#ifndef SEGMENTS
#define SEGMENTS

#include <stdint.h>

#define T SegMem_T
typedef struct T *T;

/*
 * Creates a new SegMem_T and returns the pointer to it
 */
T Seg_new();

/*
 * Return the value at seg_id and offset
 */
uint32_t Seg_load(T mem, uint32_t seg_id, uint32_t offset);

/*
 * Take the value and store
 * it in seg_id and offset
 */
void Seg_store(T mem, uint32_t value, uint32_t seg_id, uint32_t offset);

/*
 * Create a new segment with the length specified
 * with either an unmapped index or a new index
 * Each word is initialized to 0
 * The ID of the new segment is returned
 */
uint32_t Seg_map(T mem, uint32_t length);

/*
 * Unmaps the segment identified by seg_id
 * The ID may be reused when a new segment is mapped
 */
void Seg_unmap(T mem, uint32_t id);

/*
 * Frees the SegMem_T
 */
void Seg_free(T *mem);

#undef T
#endif
