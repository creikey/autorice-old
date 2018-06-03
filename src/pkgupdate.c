#include <stdlib.h>
#include <stdio.h>

#include "custassert.h"
#include "pkgupdate.h"
#include "ascpaint.h"

void update_packages()
{
    S_LOG("Update packages? ");
    if (s_getc() != 'y')
    {
        return;
    }
    printf("\n");
    asc_paint_str("-");
    center_text("Updating packages");
    asc_paint_str("+");
    fflush(stdout);
    call_updatepkg_script();
    asc_paint_str("~");
}

void call_updatepkg_script()
{
    int update_err = system(PKGUPDATE_SCRIPT);
    assert(S_ASSERT(update_err == 0, "Failed to update all packages"));
}