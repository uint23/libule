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

/* uleutf is based on utf8.h from  */

#ifndef ULEUTF_H
#define ULEUTF_H

#include "uletypes.h"

typedef char    utf8_int8_t;
typedef ule_i32 utf8_int32_t;

/* Implemented */

/* TODO */
int uleutf_casecmp(const char* src1, const char* src2);
char* uleutf_cat(char* dst, const char* src);
char* uleutf_chr(const char* src, ule_i32 chr);
int uleutf_cmp(const char* src1, const char* src2);
char* uleutf_cpy(char* dst, const char* src);
size_t uleutf_cspn(const char* src, const char* reject);
char* uleutf_dup(const char* src);
size_t uleutf_len(const char* str);
size_t uleutf_nlen(const char* str, size_t n);
int uleutf_ncasecmp(const char* src1, const char* src2, size_t n);
char* uleutf_ncat(char* dst, const char* src, size_t n);
int uleutf_ncmp(const char* src1, const char* src2, size_t n);
char* uleutf_ncpy(char* dst, const char* src, size_t n);
char* uleutf_ndup(const char* src, size_t n);
char* uleutf_pbrk(const char* str, const char* accept);
char* uleutf_rchr(const char* src, ule_i32 chr);
size_t uleutf_size(const char* str);
size_t uleutf_size_lazy(const char* str);
size_t uleutf_nsize_lazy(const char* str, size_t n);
size_t uleutf_spn(const char* src, const char* accept);
char* uleutf_str(const char* haystack, const char* needle);
char* uleutf_casestr(const char* haystack, const char* needle);
char* uleutf_valid(const char* str);
char* uleutf_nvalid(const char* str, size_t n);
int uleutf_makevalid(char* str, ule_i32 replacement);
char* uleutf_codepoint(const char* str, ule_i32* out_codepoint);
size_t uleutf_codepointcalcsize(const char* str);
size_t uleutf_codepointsize(ule_i32 chr);
int uleutf_codepointvisualwidth(ule_i32 chr);
char* uleutf_catcodepoint(char* str, ule_i32 chr, size_t n);
int uleutf_islower(ule_i32 chr);
int uleutf_isupper(ule_i32 chr);
void uleutf_lwr(char* str);
void uleutf_upr(char* str);
ule_i32 uleutf_lwrcodepoint(ule_i32 cp);
ule_i32 uleutf_uprcodepoint(ule_i32 cp);
char* uleutf_rcodepoint(const char* str, ule_i32* out_codepoint);
char* uleutf_dup_ex(const char* src, char* (*alloc_func_ptr)(char*, size_t), char* user_data);
char* uleutf_ndup_ex(const char* src, size_t n, char* (*alloc_func_ptr)(char*, size_t), char* user_data);

#endif /* ULEUTF_H */
