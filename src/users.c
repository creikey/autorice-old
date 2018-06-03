#include <stdio.h>
#include <stdlib.h>
#include "custassert.h"
#include "users.h"
#include "ascpaint.h"

void setup_users()
{
    S_LOG("Setting up users...");
    printf("\n");
    asc_paint_str("-");
    center_text("Setting Up Users");
    asc_paint_str("+");
    fflush(stdout);
    call_setup_users_script();
    asc_paint_str("~");
}

void call_setup_users_script()
{
    int setup_err = system(SETUP_USERS_SCRIPT);
    assert(S_ASSERT(setup_err == 0, "Failed to setup users"));
}