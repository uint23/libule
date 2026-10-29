#ifndef ULEUPIPE_H
#define ULEUPIPE_H

typedef struct {
	int fd;
} ulepipe;

int ulepipe_connect(ulepipe* ctx, const char* path);

#endif /* ULEUPIPE_H */

