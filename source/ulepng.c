#include <stdio.h>
#include <stdlib.h>

#include "ulepng.h"

ulepng* ulepng_init(void)
{
	ulepng* png = malloc(sizeof(ulepng));
	if (png == NULL)
		return NULL;

	png->data = NULL;
	png->size = 0;

	return png;
}

ulepng* ulepng_load_file(const char* path)
{
	ulepng* png = ulepng_init();
	FILE* file = NULL;

	file = fopen(path, "rb");
	if (file == NULL)
		return NULL;

	/* get file size */
	fseek(file, 0L, SEEK_END);
	png->size = ftell(file);
	rewind(file);

	png->data = malloc(png->size);
	if (png->data == NULL) {
		png->err = ULEPNG_ERR_OOM;
		goto cleanup;
	}

	fread(png->data, 1, png->size, file);

cleanup:
	fclose(file);
	return png;
}

