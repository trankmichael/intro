/******************************************************************************
 * segment_tests.c
 * Universal Machine - Homework 6
 * Submission 1
 * Segmented Memory Unit Tests
 * By: Jon Arbaugh and Michael Tran
 *
 * This file contains the unit tests for the segmented memory
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "segments.h"
#include "seq.h"

SegMem_T test_new();
void test_free(SegMem_T);
void map_many(SegMem_T);
void unmap_many(SegMem_T);
void specific_load_store(SegMem_T);
void brute_force_load_store(SegMem_T);

int main(int argc, char *argv[])
{
        (void)argc;
        (void)argv;
        SegMem_T t = test_new();
        test_free(t);
        t = test_new();
        map_many(t);
        unmap_many(t);
        test_free(t);
        t = test_new();
        specific_load_store(t);
        brute_force_load_store(t);
        return 0;
}

SegMem_T test_new()
{
        SegMem_T mem = Seg_new();
        assert(mem != NULL);
        return mem;
}

void test_free(SegMem_T mem)
{
        Seg_free(&mem);
        /* must be tested with valgrind */
}


void map_many(SegMem_T mem)
{
        uint32_t i;
        uint32_t num_segs = 500;
        uint32_t length = 25;
        uint32_t id = 0;

        for (i = 0; i < num_segs; i++) {
                id = Seg_map(mem, length);
                assert (id == i); /* at this point, i and b should equal */
        }
}

void unmap_many(SegMem_T mem)
{
        uint32_t i = 0;
        uint32_t num_segs = 500;
        uint32_t id = 0;

        for (i = 0; i < num_segs; i++) {
                Seg_unmap(mem, i);
        }

        id = Seg_map(mem, 15);
        /* operates under the idea that ids are reused */
        /* so if unmap works, map should return an already used id */
        assert(id <= num_segs);
        Seg_unmap(mem, id);
}

void specific_load_store(SegMem_T mem)
{
        uint32_t seg_id = 0;
        uint32_t seg_id2 = 0;

        uint32_t val1 = 57;
        uint32_t val2 = 987654;
        uint32_t val3 = 670;

        seg_id = Seg_map(mem, 15);
        Seg_store(mem, val1, seg_id, 0);
        Seg_store(mem, val2, seg_id, 1);
        Seg_store(mem, val3, seg_id, 2);

        assert(val1 == Seg_load(mem, seg_id, 0));
        assert(val2 == Seg_load(mem, seg_id, 1));
        assert(val3 == Seg_load(mem, seg_id, 2));

        val1 = 7434325;
        val2 = 92;
        val3 = 0;

        seg_id2 = Seg_map(mem, 15);
        Seg_store(mem, val1, seg_id2, 0);
        Seg_store(mem, val2, seg_id2, 1);
        Seg_store(mem, val3, seg_id2, 2);

        assert(val1 == Seg_load(mem, seg_id2, 0));
        assert(val2 == Seg_load(mem, seg_id2, 1));
        assert(val3 == Seg_load(mem, seg_id2, 2));

        Seg_unmap(mem, seg_id);
        Seg_unmap(mem, seg_id2);
}

void brute_force_load_store(SegMem_T mem)
{
        srand(time(NULL));
        uint32_t num_segs = rand() % 1000;
        uint32_t seg_length = 0;
        uint32_t i = 0;
        uint32_t val = 0;
        uint32_t offset = 0;
        uint32_t seg_id = 0;

        for (i = 0; i < num_segs; i++) {
                seg_length = rand() % 1000;
                seg_id = Seg_map(mem, seg_length);
                offset = rand() % seg_length;
                val = rand() % 1000000;
                Seg_store(mem, val, seg_id, offset);
                assert(val == Seg_load(mem, seg_id, offset));
                Seg_unmap(mem, seg_id);
        }
}
