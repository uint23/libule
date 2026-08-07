#include <stdio.h>
#include <stdlib.h>

#include "ulepng.h"

ulepng ulepng_init(void)
{
	ulepng png = { NULL, 0, ULEPNG_ERR_NONE };
	return png;
}

ulepng ulepng_init_file(const char* path)
{
	ulepng png = ulepng_init();
	FILE* file = NULL;

	file = fopen(path, "rb");
	if (file == NULL) {
		png.err = ULEPNG_ERR_FOPEN;
		return png;
	}

	/* get file size */
	fseek(file, 0L, SEEK_END);
	png.size = ftell(file);
	rewind(file);

	png.data = malloc(png.size);
	if (png.data == NULL) {
		png.err = ULEPNG_ERR_OOM;
		goto cleanup;
	}

	fread(png.data, 1, png.size, file);

cleanup:
	fclose(file);
	return png;
}

