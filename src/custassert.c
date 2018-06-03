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

char s_getc()
{
    if (!print_logs)
    {
        return 'y';
    }
    char got_char = '\n';
    while (got_char == '\n' || got_char == ' ')
    {
        got_char = fgetc(stdin);
    }
    return got_char;
}