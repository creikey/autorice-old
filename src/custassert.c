#include <stdio.h>

#include "custassert.h"

int _s_fail(const char *fail_explanation)
{
    if (print_logs)
    {
        printf("FAIL!\n> %s\n", fail_explanation);
    }
    return 0;
}

int _s_success()
{
    if (print_logs)
    {
        printf("OK!\n");
    }
    return 1;
}