#ifndef IVL_H
#define IVL_H 1

extern void ivl_where_impl(const char* func);
extern void ivl_bt();
extern void ivl_indent();
extern void ivl_deindent();

struct ivl_deindenter {
  const char* ptr;
  ivl_deindenter(const char* ptr_) : ptr(ptr_) {}
  ~ivl_deindenter();
};

#define ivl_where_old() ivl_where_impl(__func__)
#define ivl_where() \
  ivl_indent(); \
  ivl_where_impl(__func__); \
  ivl_deindenter _(__func__)

int ivl_init_component_length(const struct an_init_component* ptr);

#endif /* ifndef IVL_H */
