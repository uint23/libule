#ifndef ULEPNG_H
#define ULEPNG_H

#include <stddef.h>

typedef enum {
	ULEPNG_ERR_NONE,
	ULEPNG_ERR_OOM, /* Out of memory */

	ULEPNG_ERR_LAST
} UlePNGErr;

typedef struct {
	unsigned char* data;
	size_t         size;
	UlePNGErr      err;
} ulepng;

ulepng* ulepng_init(void);
ulepng* ulepng_load_file(const char* path);

#endif /* ULEPNG_H */

