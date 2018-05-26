#include <stdio.h>

#include "custassert.h"

int _s_assert(void *thing, const char *fail_explanation)
{
    if (!thing)
    {
        printf("FAIL!\n> %s\n", fail_explanation);
        return 0;
    }
    printf("OK!\n");
    return 1;
}