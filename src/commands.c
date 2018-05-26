#include <stdio.h>
#include <assert.h>

#include "commands.h"
#include "custassert.h"

void init_commands()
{
    printf("Initializing commands...");
    FILE *whis_fp = NULL;
    whis_fp = fopen(WHEREIS_PATH, "r");
    S_ASSERT(whis_fp, "Could not find whereis binary");
    fclose(whis_fp);
}
