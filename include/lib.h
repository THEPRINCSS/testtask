#ifndef LIB
#define LIB
#include "packages.h"

extern void get_branch(const char *,const char*);
extern struct package *read_json(const char*);
extern int write_json(struct package*, struct package *, struct package*);

extern struct package *comparison(struct package *, struct package*);
extern struct package *high(struct package *, struct package*);

#endif
