#include <stdio.h>
#include <stdlib.h>
#include "custassert.h"
#include "installxorg.h"
#include "ascpaint.h"

void install_xorg()
{
    S_LOG("Install xorg? ");
    if (s_getc() != 'y')
    {
        return;
    }
    S_LOG("Installing xorg...");
    printf("\n");
    asc_paint_str("-");
    center_text("Installing XORG");
    asc_paint_str("+");
    fflush(stdout);
    call_install_xorg_script();
    asc_paint_str("~");
}

void call_install_xorg_script()
{
    int install_err = system(INSTALL_XORG_SCRIPT);
    assert(S_ASSERT(install_err == 0, "Failed to install xorg"));
}