#include <stdio.h>
#include <stdlib.h>
#include "custassert.h"
#include "kde.h"
#include "ascpaint.h"

void install_kde()
{

    S_LOG("Install kde? ");
    if (s_getc() != 'y')
    {
        return;
    }
    printf("\n");
    asc_paint_str("-");
    center_text("Installing KDE");
    asc_paint_str("+");
    fflush(stdout);
    call_install_kde_script();
    asc_paint_str("~");
}

void call_install_kde_script()
{
    int install_err = system(INSTALL_KDE_SCRIPT);
    assert(S_ASSERT(install_err == 0, "Failed to install KDE"));
}