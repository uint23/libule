#include <stdio.h>
#include <stdlib.h>

#include "ulepng.h"

int main(int argc, char* argv[])
{
	ulepng png;
	unsigned char* x;
	unsigned char* diff;

	if (argc < 2) {
		fprintf(stderr, "Provide an argument (path to image)\n");
		return EXIT_FAILURE;
	}

	png = ulepng_init_file(argv[1]);
	if (png.err != ULEPNG_ERR_NONE) {
		fprintf(stderr, "Failed to open PNG file [ERR: %d]\n", png.err);
		return png.err;
	}

	diff = png.data + png.size;
	for (x = png.data; x < diff; x++)
		printf("%x", *x);

	printf("\n");

	return EXIT_SUCCESS;
}

