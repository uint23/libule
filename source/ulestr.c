/* Copyright 2026 uint (and contributors)

Permission to use, copy, modify, and distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. */

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

