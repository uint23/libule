#include <stdlib.h>
#include <string.h>

#include "ulepipe.h"

#define sockpath "/tmp/ulepipe_test.sock"
#define ssame(a, b) (!strcmp(a, b))

enum type {
	TEST_STOP,
	TEST_NAME_CHANGE,
} type;

typedef struct {
	int       x, y;
	char      name[64];
	enum type type;
} some_data_layout;

int main(int argc, char* argv[])
{
	const char* cmd = argv[1];
	
	if (argc < 2)
		return EXIT_FAILURE;

	if (ssame(cmd, "stop")) {
		some_data_layout stop_data = {0, 0, "die", TEST_STOP};
		ulepipe_send(sockpath, &stop_data, sizeof(stop_data));
	}

	if (ssame(cmd, "name_change")) {
		some_data_layout name_change_data = {0, 0, "tester123", TEST_NAME_CHANGE};
		ulepipe_send(sockpath, &name_change_data, sizeof(name_change_data));
	}

	return EXIT_SUCCESS;
}

