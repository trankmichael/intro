#include <stdio.h>
#include <stdint.h>
#include "set.h"

int cmp(const void *x, const void *y)
{
        uint32_t a = *(uint32_t*)x;
        uint32_t b = *(uint32_t*)y;
        return (a == b ? 0 : (a > b ? 1 : -1));
}

unsigned hash(const void *x)
{
        return *(uint32_t*)x;
}


int main(int argc, char *argv[])
{
        (void)argc;
        (void)argv;
        Set_T t = Set_new(1, cmp, hash);
        uint32_t i = 0;
        uint32_t val = 0;
        for (i = 0; i < 10000; i++) {
                Set_put(t, &val);
                fprintf(stdout, "%d\n", Set_length(t));
        }
        Set_free(&t);
        return 0;
}
