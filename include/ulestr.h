#ifndef ULESTR_H
#define ULESTR_H

#include <stddef.h>

typedef char* ustr;

/* get length of a string */
size_t ustrlen(const ustr);

/* allocate a new string */
ustr ustrnew(const char*);

/* free a string */
void ustrfree(ustr);

#endif /* ULESTR_H */

