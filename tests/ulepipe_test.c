#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ulepipe.h"

#define sockpath "/tmp/ulepipe_test.sock"

enum type {
	TEST_STOP,
	TEST_NAME_CHANGE,
} type;

typedef struct {
	int       x, y;
	char      name[64];
	enum type type;
} some_data_layout;

some_data_layout data;
char name[64] = { 0 };

int main(void)
{
	ulepipe master = { 0 };
	ulepipe_open(&master, sockpath);
	if (master.fd < 0)
		return EXIT_FAILURE;
	
	for (;;) {
		ssize_t n = ulepipe_receive(&master, &data, sizeof(data));
		if (!(n == sizeof(data))) {
			printf("received data too small\n");
			continue;
		}
		
		switch (data.type) {
		case TEST_STOP:
			printf("received stop\n");
			fflush(stdout);
			goto end;
		case TEST_NAME_CHANGE:
			printf("received name_change\n");
			fflush(stdout);
			strncpy(name, data.name, 64);
		default:
			continue;
			break;
		}
	}
	
end:
	printf("%s\n", name);

	ulepipe_close(&master);
	return EXIT_SUCCESS;
}

