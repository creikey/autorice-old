#ifndef H_COMMANDS
#define H_COMMANDS

#define WHICH_PATH "/usr/bin/which"

void init_commands();

char *get_command_path(const char *command_name);

#endif