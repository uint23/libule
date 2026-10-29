#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "ulepipe.h"

int
ulepipe_connect(ulepipe* ctx, const char* path)
{
	struct sockaddr_un addr = { 0 };
	int fd = -1;

	if (!ctx || !path) {
		errno = EINVAL;
		return -1;
	}

	if (strlen(path) >= sizeof(addr.sun_path)) {
		errno = ENAMETOOLONG;
		return -1;
	}

	fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if (fd == -1)
		return -1;

	memset(&addr, 0, sizeof(addr));
	addr.sun_family = AF_UNIX;
	strcpy(addr.sun_path, path);

	if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
		int saved_errno = errno;
		close(fd);
		errno = saved_errno;
		return -1;
	}

	ctx->fd = fd;
	return 0;
}

void
tpipe_close(ulepipe* ctx)
{
	if (!ctx)
		return;

	if (ctx->fd >= 0) {
		close(ctx->fd);
		ctx->fd = -1;
	}
}

