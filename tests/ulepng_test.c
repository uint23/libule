#include <stdio.h>

#include "ulepng.h"

int main(int argc, char* argv[])
{
	ulepng* png;
	unsigned char* x;
	unsigned char* diff;

	if (argc < 2)
		return 1;

	png = ulepng_load_file(argv[1]);

	diff = png->data + png->size;
	for (x = png->data; x < diff; x++)
		printf("%x", *x);

	printf("\n");

	return 0;
}

