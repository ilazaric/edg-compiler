#ifndef IVL_H
#define IVL_H 1

extern void ivl_where_impl(const char* func);
extern void ivl_bt();

#define ivl_where() ivl_where_impl(__func__)

#endif /* ifndef IVL_H */
