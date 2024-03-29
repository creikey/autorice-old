#include <stdio.h>

#include "greatest.h"
#include "tests.test.h"
#include "commands.h"
#include "ascpaint.h"
#include "custassert.h"
#include "network.h"
#include "mirrorlist.h"
#include "pkgupdate.h"
#include "installnm.h"
#include "kde.h"
#include "users.h"
#include "installxorg.h"

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
  clear_screen();
  asc_paint_str("=");
  asc_paint_str("-");
  asc_paint_str("_");
  asc_paint_str("  -");
  center_text("Ricing Desktop");
  center_text(" - c  r  e  i  k  e  y - ");
  asc_paint_str("_");
  init_commands();
  init_ascpaint();
  check_network();
  update_mirrorlist();
  update_packages();
  setup_users();
  install_xorg();
  install_nm();
  install_kde();
  asc_paint_str("~|");
  center_text("Finished Boostrapping");
  center_text("For dotfile manager, see github.com/creikey/dotfiles.git");
  asc_paint_str("_");
  return 0;
#endif // DOTEST
}
