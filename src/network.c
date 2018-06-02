#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "network.h"
#include "ascpaint.h"
#include "custassert.h"

void check_network()
{
    S_LOG("Checking network...");
    int network_err = system(CHECK_NETWORK_SCRIPT);
    if (!S_ASSERT(network_err == 0, "Network offline"))
    {
        S_LOG("Set up network? ");
        assert(s_getc() == 'y');
        printf("\n");
        asc_paint_str("-");
        center_text("Setting Up Network");
        asc_paint_str("+");
        set_up_network();
        asc_paint_str("_");
    }
}

void set_up_network()
{
    int setup_err = system(SET_UP_NETWORK_SCRIPT);
    assert(setup_err == 0);
    S_LOG("Checking network setup...");
    int network_err = system(CHECK_NETWORK_SCRIPT);
    assert(S_ASSERT(network_err == 0, "Setup failed"));
}