#include "ivl.h"

#if !STANDALONE_IL_DISPLAY
#include "fe_common.h"

#include "basics.h" // f_debug
#include "lexical.h" // pos_curr_token, db_source_position, ...
#endif // !STANDALONE_IL_DISPLAY

#include <unistd.h> // getpid
#include <stdio.h> // sprintf, ...
#include <stdlib.h> // system

#if !STANDALONE_IL_DISPLAY
static int indent = 0;

void ivl_where_impl(const char* func) {
  fprintf(f_debug, "IVL: %s: ", func);
  db_source_position(&pos_curr_token);
  fprintf(f_debug, "\n");
}

void ivl_indent() {
  for (int i = 0; i < indent; ++i) fprintf(f_debug, " ");
  indent += 2;
}

void ivl_deindent() {
  indent -= 2;
  for (int i = 0; i < indent; ++i) fprintf(f_debug, " ");
}

ivl_deindenter::~ivl_deindenter() {
  ivl_deindent();
  ivl_where_impl(ptr);
}
#endif // !STANDALONE_IL_DISPLAY

void ivl_bt() {
  char comm[1000]{};
  sprintf(comm, "gdb --batch -ex \"thread apply all bt\" -p %d", getpid());
  system(comm);
}
