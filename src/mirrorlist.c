#include <stdio.h>
#include <stdlib.h>
#include "custassert.h"
#include "mirrorlist.h"
#include "ascpaint.h"

void update_mirrorlist()
{
    S_LOG("Set up mirrorlist? ");
    if (s_getc() != 'y')
    {
        return;
    }
    printf("\n");
    asc_paint_str("-");
    center_text("Updating mirrorlist");
    asc_paint_str("+");
    fflush(stdout);
    call_mirrorlist_script();
    asc_paint_str("~");
}

void call_mirrorlist_script()
{
    int update_err = system(UPDATE_MIRRORLIST_SCRIPT);
    assert(S_ASSERT(update_err == 0, "Failed to update mirrorlist"));
}