#ifndef IVL_H
#define IVL_H 1

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define ivl_where() do {                        \
    fprintf(f_debug, "IVL: %s: ", __func__);    \
    db_source_position(&pos_curr_token);        \
    fprintf(f_debug, "\n");                     \
  } while (false)

#define ivl_bt() do {                                                   \
    char comm[1000]{};                                                  \
    sprintf(comm, "gdb --batch -ex \"thread apply all bt\" -p %d", getpid()); \
    system(comm);                                                       \
  } while (false)

#endif /* ifndef IVL_H */
