#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ulestr.h"

size_t ustrlen(const ustr str)
{
	return *((const size_t*) str - 1);
}

ustr ustrnew(const char* text)
{
	/* [len][text][\0] */
	size_t  len = strlen(text);
	void*   block = malloc(sizeof(size_t) + len + 1);
	size_t* lenptr = (size_t*)block;
	ustr    textptr = (ustr)((size_t*)block + 1);

	if (block == NULL)
		return NULL;

	*lenptr = len;
	memcpy(textptr, text, len + 1);

	return textptr;
}

void ustrfree(ustr str)
{
	if (str)
		free(str);
}

