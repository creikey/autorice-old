#include <stdio.h>

#include "greatest.h"
#include "tests.test.h"
#include "commands.h"
#include "custassert.h"

#ifdef DOTEST
bool print_logs = false;
#else
bool print_logs = true;
#endif

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
#ifdef DOTEST
  GREATEST_MAIN_BEGIN();
  // put tests here
  RUN_ALL_SUITS();
  GREATEST_MAIN_END();
#else

  init_commands();
  printf("Hello, world!\n");
  return 0;
#endif // DOTEST
}
