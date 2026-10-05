#include "ivl.h"

#include <unistd.h> // getpid
#include <stdio.h> // sprintf, ...
#include <stdlib.h> // system

void ivl_bt() {
  char comm[1000]{};
  sprintf(comm, "gdb --batch -ex \"thread apply all bt\" -p %d", getpid());
  system(comm);
}

#if !STANDALONE_IL_DISPLAY
#include "fe_common.h"

#include "basics.h" // f_debug
#include "lexical.h" // pos_curr_token, db_source_position, ...
#include "expr.h" // an_init_component

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

int ivl_init_component_length(const struct an_init_component* ptr) {
  check_assertion(ptr);
  check_assertion(ptr->kind == ick_braced);
  ptr = ptr->variant.braced.list;
  int len = 0;
  while (ptr) {
    ++len;
    ptr = ptr->next;
  }
  return len;
}
#endif // !STANDALONE_IL_DISPLAY
