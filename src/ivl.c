#if !STANDALONE_IL_DISPLAY
#include "fe_common.h"

#include "basics.h" // f_debug
#include "lexical.h" // pos_curr_token, db_source_position, ...
#endif // !STANDALONE_IL_DISPLAY

#include <unistd.h> // getpid
#include <stdio.h> // sprintf, ...
#include <stdlib.h> // system

#if !STANDALONE_IL_DISPLAY
void ivl_where_impl(const char* func) {
  fprintf(f_debug, "IVL: %s: ", func);
  db_source_position(&pos_curr_token);
  fprintf(f_debug, "\n");
}
#endif // !STANDALONE_IL_DISPLAY

void ivl_bt() {
  char comm[1000]{};
  sprintf(comm, "gdb --batch -ex \"thread apply all bt\" -p %d", getpid());
  system(comm);
}
