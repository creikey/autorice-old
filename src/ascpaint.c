#include <sys/ioctl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "ascpaint.h"
#include "custassert.h"

term_size _cur_term_size = {0, 0};

term_size get_term_size()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    term_size to_return;
    to_return.c = w.ws_col;
    to_return.r = w.ws_row;
    return to_return;
}

void init_ascpaint()
{
    S_LOG("Initializing ascpaint...");
    _cur_term_size = get_term_size();
    S_ASSERT(_cur_term_size.c > 0 && _cur_term_size.r > 0, "Cur term size isn't greater than 0");
}

void asc_paint_str(const char *to_print)
{
    assert(to_print);
    _cur_term_size = get_term_size();
    size_t tp_len = strlen(to_print);
    int i = _cur_term_size.c;
    for (; i > tp_len; i -= tp_len)
    {
        printf("%s", to_print);
    }
    for (int ii = 0; i > 0; ii++)
    {
        printf("%c", to_print[ii]);
        i--;
    }
}

void center_text(const char *to_center)
{
    assert(to_center);
    size_t tp_len = strlen(to_center);
    _cur_term_size = get_term_size();
    int spaces = ((tp_len + _cur_term_size.c) / 2) - tp_len;
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
    printf("%s\n", to_center);
}

void clear_screen()
{
    printf("\e[1;1H\e[2J");
}