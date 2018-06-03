#include <stdio.h>
#include <stdlib.h>
#include "custassert.h"
#include "gnome.h"
#include "ascpaint.h"

void install_gnome()
{
    
    S_LOG("Install gnome? ");
    if(s_getc() != 'y')
    {
        return;
    }
    printf("\n");
    asc_paint_str("-");
    center_text("Installing Gnome");
    asc_paint_str("+");
    fflush(stdout);
    call_install_gnome_script();
    asc_paint_str("~");
}

void call_install_gnome_script()
{
    int install_err = system(INSTALL_GNOME_SCRIPT);
    assert(S_ASSERT(install_err == 0, "Failed to install gnome"));
}