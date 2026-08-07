#ifndef ULEPNG_H
#define ULEPNG_H

#include <stddef.h>

typedef enum {
	ULEPNG_ERR_NONE,
	ULEPNG_ERR_FAIL,

	ULEPNG_ERR_FOPEN,
	ULEPNG_ERR_OOM,

	ULEPNG_ERR_LAST
} UlePNGErr;

typedef struct {
	unsigned char* data;
	size_t         size;
	UlePNGErr      err;
} ulepng;

/* Initialise a ulepng with 0 values */
ulepng ulepng_init(void);

/* Initialise a ulepng with an image loaded from disk */
ulepng ulepng_init_file(const char* path);

#endif /* ULEPNG_H */

