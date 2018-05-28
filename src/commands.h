#ifndef H_COMMANDS
#define H_COMMANDS

#define WHICH_PATH "/usr/bin/which"

#include "strbuff.h"

void init_commands();

str_buff *get_command_path(const char *command_name);

str_buff *get_absolute_path(const char *in_path);

#endif