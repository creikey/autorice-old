#include <stdio.h>
#include <stdlib.h>
#include "custassert.h"
#include "installnm.h"
#include "ascpaint.h"
#include "network.h"

void install_nm()
{
    S_LOG("Install networkmanager? ");
    if(s_getc() != 'y')
    {
        return;
    }
    printf("\n");
    asc_paint_str("-");
    center_text("Installing networkmanager");
    asc_paint_str("+");
    fflush(stdout);
    call_install_nm_script();
    asc_paint_str("~");
}

void call_install_nm_script()
{
    int install_err = system(INSTALLNM_SCRIPT);
    assert(S_ASSERT(install_err == 0, "Failed to install networkmanager"));
    int network_err = system(CHECK_NETWORK_SCRIPT);
    assert(S_ASSERT(network_err == 0, "Failed to reenable network"));
}