/* Copyright 2026 uint (and contributors)
   Copyright 2019-2025 Laslo Hunhold <dev@frign.de>

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

/* uleutf is based on Laslo Hunhold's libgrapheme which is hosted on
   suckless.org */

#ifndef ULEUTF_H
#define ULEUTF_H

#include <stddef.h>

#include "uletypes.h"

#define GRAPHEME_INVALID_CODEPOINT UINT32_C(0xFFFD)

enum uleutf_bidirectional_direction {
	ULEUTF_BIDIRECTIONAL_DIRECTION_NEUTRAL,
	ULEUTF_BIDIRECTIONAL_DIRECTION_LTR,
	ULEUTF_BIDIRECTIONAL_DIRECTION_RTL
};

size_t uleutf_bidirectional_get_line_embedding_levels(const ule_u32*, size_t, ule_i8*, size_t);
size_t uleutf_bidirectional_preprocess_paragraph(const ule_u32*, size_t, enum uleutf_bidirectional_direction, ule_u32*, size_t, enum uleutf_bidirectional_direction*);
size_t uleutf_bidirectional_reorder_line(const ule_u32 *, const ule_u32 *, size_t, ule_u32 *, size_t);

size_t uleutf_decode_utf8(const char *, size_t, ule_u32 *);
size_t uleutf_encode_utf8(ule_u32, char *, size_t);

ule_i8 uleutf_is_character_break(ule_u32, ule_u32, ule_u16 *);

ule_i8 uleutf_is_lowercase(const ule_u32 *, size_t, size_t *);
ule_i8 uleutf_is_titlecase(const ule_u32 *, size_t, size_t *);
ule_i8 uleutf_is_uppercase(const ule_u32 *, size_t, size_t *);

ule_i8 uleutf_is_lowercase_utf8(const char *, size_t, size_t *);
ule_i8 uleutf_is_titlecase_utf8(const char *, size_t, size_t *);
ule_i8 uleutf_is_uppercase_utf8(const char *, size_t, size_t *);

size_t uleutf_next_character_break(const ule_u32 *, size_t);
size_t uleutf_next_line_break(const ule_u32 *, size_t);
size_t uleutf_next_sentence_break(const ule_u32 *, size_t);
size_t uleutf_next_word_break(const ule_u32 *, size_t);

size_t uleutf_next_character_break_utf8(const char *, size_t);
size_t uleutf_next_line_break_utf8(const char *, size_t);
size_t uleutf_next_sentence_break_utf8(const char *, size_t);
size_t uleutf_next_word_break_utf8(const char *, size_t);

size_t uleutf_to_lowercase(const ule_u32 *, size_t, ule_u32 *, size_t);
size_t uleutf_to_titlecase(const ule_u32 *, size_t, ule_u32 *, size_t);
size_t uleutf_to_uppercase(const ule_u32 *, size_t, ule_u32 *, size_t);

size_t uleutf_to_lowercase_utf8(const char *, size_t, char *, size_t);
size_t uleutf_to_titlecase_utf8(const char *, size_t, char *, size_t);
size_t uleutf_to_uppercase_utf8(const char *, size_t, char *, size_t);

#endif /* ULEUTF_H */

