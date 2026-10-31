#ifndef ULEUPIPE_H
#define ULEUPIPE_H

#include <stddef.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#ifndef ULEPIPE_TIMEOUT
#define ULEPIPE_TIMEOUT 5
#endif

typedef struct {
	int       fd;
	socklen_t peer_len;

	struct sockaddr_un addr;
	struct sockaddr_un peer;
} ulepipe;

/* Open a ulepipe socket */
int ulepipe_open(ulepipe* conn, const char* path);

/* Close a ulepipe */
void ulepipe_close(ulepipe* conn);

/* Send data to a ulepipe socket */
ssize_t ulepipe_send(const char* path, void* data, size_t size);

/* Reply response to connected client */
ssize_t ulepipe_reply(const ulepipe* conn, const void* data, size_t size);

/* Receive data from a ulepipe socket */
ssize_t ulepipe_receive(ulepipe* conn, void* data, size_t size);

#endif /* ULEUPIPE_H */

