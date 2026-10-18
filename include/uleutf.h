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

/* Return less than 0, 0, greater than 0 if src1 < src2, src1 == src2, src1 >
 * src2 respectively, case insensitive. */
utf8_constexpr14 utf8_nonnull utf8_pure int
utf8casecmp(const utf8_int8_t *src1, const utf8_int8_t *src2);

/* Append the utf8 string src onto the utf8 string dst. */
utf8_nonnull utf8_weak utf8_int8_t *
utf8cat(utf8_int8_t *utf8_restrict dst, const utf8_int8_t *utf8_restrict src);

/* Find the first match of the utf8 codepoint chr in the utf8 string src. */
utf8_constexpr14 utf8_nonnull utf8_pure utf8_int8_t *
utf8chr(const utf8_int8_t *src, utf8_int32_t chr);

/* Return less than 0, 0, greater than 0 if src1 < src2,
 * src1 == src2, src1 > src2 respectively. */
utf8_constexpr14 utf8_nonnull utf8_pure int utf8cmp(const utf8_int8_t *src1,
                                                    const utf8_int8_t *src2);

/* Copy the utf8 string src onto the memory allocated in dst. */
utf8_nonnull utf8_weak utf8_int8_t *
utf8cpy(utf8_int8_t *utf8_restrict dst, const utf8_int8_t *utf8_restrict src);

/* Number of utf8 codepoints in the utf8 string src that consists entirely
 * of utf8 codepoints not from the utf8 string reject. */
utf8_constexpr14 utf8_nonnull utf8_pure size_t
utf8cspn(const utf8_int8_t *src, const utf8_int8_t *reject);

/* Duplicate the utf8 string src by getting its size, malloc'ing a new buffer
 * copying over the data, and returning that. Or 0 if malloc failed. */
utf8_weak utf8_int8_t *utf8dup(const utf8_int8_t *src);

/* Number of utf8 codepoints in the utf8 string str,
 * excluding the null terminating byte. */
utf8_constexpr14 utf8_nonnull utf8_pure size_t utf8len(const utf8_int8_t *str);

/* Similar to utf8len, except that only at most n bytes of src are looked. */
utf8_constexpr14 utf8_nonnull utf8_pure size_t utf8nlen(const utf8_int8_t *str,
                                                        size_t n);

/* Return less than 0, 0, greater than 0 if src1 < src2, src1 == src2, src1 >
 * src2 respectively, case insensitive. Checking at most n bytes of each utf8
 * string. */
utf8_constexpr14 utf8_nonnull utf8_pure int
utf8ncasecmp(const utf8_int8_t *src1, const utf8_int8_t *src2, size_t n);

/* Append the utf8 string src onto the utf8 string dst,
 * writing at most n+1 bytes. Can produce an invalid utf8
 * string if n falls partway through a utf8 codepoint. */
utf8_nonnull utf8_weak utf8_int8_t *
utf8ncat(utf8_int8_t *utf8_restrict dst, const utf8_int8_t *utf8_restrict src,
         size_t n);

/* Return less than 0, 0, greater than 0 if src1 < src2,
 * src1 == src2, src1 > src2 respectively. Checking at most n
 * bytes of each utf8 string. */
utf8_constexpr14 utf8_nonnull utf8_pure int
utf8ncmp(const utf8_int8_t *src1, const utf8_int8_t *src2, size_t n);

/* Copy the utf8 string src onto the memory allocated in dst.
 * Copies at most n bytes. If n falls partway through a utf8
 * codepoint, or if dst doesn't have enough room for a null
 * terminator, the final string will be cut short to preserve
 * utf8 validity. */

utf8_nonnull utf8_weak utf8_int8_t *
utf8ncpy(utf8_int8_t *utf8_restrict dst, const utf8_int8_t *utf8_restrict src,
         size_t n);

/* Similar to utf8dup, except that at most n bytes of src are copied. If src is
 * longer than n, only n bytes are copied and a null byte is added.
 *
 * Returns a new string if successful, 0 otherwise */
utf8_weak utf8_int8_t *utf8ndup(const utf8_int8_t *src, size_t n);

/* Locates the first occurrence in the utf8 string str of any byte in the
 * utf8 string accept, or 0 if no match was found. */
utf8_constexpr14 utf8_nonnull utf8_pure utf8_int8_t *
utf8pbrk(const utf8_int8_t *str, const utf8_int8_t *accept);

/* Find the last match of the utf8 codepoint chr in the utf8 string src. */
utf8_constexpr14 utf8_nonnull utf8_pure utf8_int8_t *
utf8rchr(const utf8_int8_t *src, utf8_int32_t chr);

/* Number of bytes in the utf8 string str,
 * including the null terminating byte. */
utf8_constexpr14 utf8_nonnull utf8_pure size_t utf8size(const utf8_int8_t *str);

/* Similar to utf8size, except that the null terminating byte is excluded. */
utf8_constexpr14 utf8_nonnull utf8_pure size_t
utf8size_lazy(const utf8_int8_t *str);

/* Similar to utf8size, except that only at most n bytes of src are looked and
 * the null terminating byte is excluded. */
utf8_constexpr14 utf8_nonnull utf8_pure size_t
utf8nsize_lazy(const utf8_int8_t *str, size_t n);

/* Number of utf8 codepoints in the utf8 string src that consists entirely
 * of utf8 codepoints from the utf8 string accept. */
utf8_constexpr14 utf8_nonnull utf8_pure size_t
utf8spn(const utf8_int8_t *src, const utf8_int8_t *accept);

/* The position of the utf8 string needle in the utf8 string haystack. */
utf8_constexpr14 utf8_nonnull utf8_pure utf8_int8_t *
utf8str(const utf8_int8_t *haystack, const utf8_int8_t *needle);

/* The position of the utf8 string needle in the utf8 string haystack, case
 * insensitive. */
utf8_constexpr14 utf8_nonnull utf8_pure utf8_int8_t *
utf8casestr(const utf8_int8_t *haystack, const utf8_int8_t *needle);

/* Return 0 on success, or the position of the invalid
 * utf8 codepoint on failure. */
utf8_constexpr14 utf8_nonnull utf8_pure utf8_int8_t *
utf8valid(const utf8_int8_t *str);

/* Similar to utf8valid, except that only at most n bytes of src are looked. */
utf8_constexpr14 utf8_nonnull utf8_pure utf8_int8_t *
utf8nvalid(const utf8_int8_t *str, size_t n);

/* Given a null-terminated string, makes the string valid by replacing invalid
 * codepoints with a 1-byte replacement. Returns 0 on success. */
utf8_nonnull utf8_weak int utf8makevalid(utf8_int8_t *str,
                                         const utf8_int32_t replacement);

/* Sets out_codepoint to the current utf8 codepoint in str, and returns the
 * address of the next utf8 codepoint after the current one in str. */
utf8_constexpr14 utf8_nonnull utf8_int8_t *
utf8codepoint(const utf8_int8_t *utf8_restrict str,
              utf8_int32_t *utf8_restrict out_codepoint);

/* Calculates the size of the next utf8 codepoint in str. */
utf8_constexpr14 utf8_nonnull utf8_pure size_t
utf8codepointcalcsize(const utf8_int8_t *str);

/* Returns the size of the given codepoint in bytes. */
utf8_constexpr14 utf8_pure size_t utf8codepointsize(utf8_int32_t chr);

/* Returns the number of terminal columns the given codepoint occupies when
 * printed with a fixed-width font: 0 for zero-width codepoints (the null
 * codepoint and combining marks), 2 for wide (double-width) codepoints, 1 for
 * ordinary codepoints, and -1 for non-printable control codepoints. */
utf8_constexpr14 utf8_pure int utf8codepointvisualwidth(utf8_int32_t chr);

/* Write a codepoint to the given string, and return the address to the next
 * place after the written codepoint. Pass how many bytes left in the buffer to
 * n. If there is not enough space for the codepoint, this function returns
 * null. */
utf8_nonnull utf8_weak utf8_int8_t *
utf8catcodepoint(utf8_int8_t *str, utf8_int32_t chr, size_t n);

/* Returns 1 if the given character is lowercase, or 0 if it is not. */
utf8_constexpr14 utf8_pure int utf8islower(utf8_int32_t chr);

/* Returns 1 if the given character is uppercase, or 0 if it is not. */
utf8_constexpr14 utf8_pure int utf8isupper(utf8_int32_t chr);

/* Transform the given string into all lowercase codepoints in place. This
 * function does not allocate memory. All currently supported case mappings
 * preserve the number of bytes in the encoded string. */
utf8_nonnull utf8_weak void utf8lwr(utf8_int8_t *utf8_restrict str);

/* Transform the given string into all uppercase codepoints in place. This
 * function does not allocate memory. All currently supported case mappings
 * preserve the number of bytes in the encoded string. */
utf8_nonnull utf8_weak void utf8upr(utf8_int8_t *utf8_restrict str);

/* Make a codepoint lower case if possible. */
utf8_constexpr14 utf8_pure utf8_int32_t utf8lwrcodepoint(utf8_int32_t cp);

/* Make a codepoint upper case if possible. */
utf8_constexpr14 utf8_pure utf8_int32_t utf8uprcodepoint(utf8_int32_t cp);

/* Sets out_codepoint to the current utf8 codepoint in str, and returns the
 * address of the previous utf8 codepoint before the current one in str. */
utf8_constexpr14 utf8_nonnull utf8_int8_t *
utf8rcodepoint(const utf8_int8_t *utf8_restrict str,
               utf8_int32_t *utf8_restrict out_codepoint);

/* Duplicate the utf8 string src by getting its size, calling alloc_func_ptr to
 * copy over data to a new buffer, and returning that. Or 0 if alloc_func_ptr
 * returned null. */
utf8_weak utf8_int8_t *utf8dup_ex(const utf8_int8_t *src,
                                  utf8_int8_t *(*alloc_func_ptr)(utf8_int8_t *,
                                                                 size_t),
                                  utf8_int8_t *user_data);

/* Similar to utf8dup, except that at most n bytes of src are copied. If src is
 * longer than n, only n bytes are copied and a null byte is added.
 *
 * Returns a new string if successful, 0 otherwise. */
utf8_weak utf8_int8_t *utf8ndup_ex(const utf8_int8_t *src, size_t n, utf8_int8_t *(*alloc_func_ptr)(utf8_int8_t *, size_t), utf8_int8_t *user_data);

#endif /* ULEUTF_H */
