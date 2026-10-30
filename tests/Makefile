.POSIX:

CC = cc
CFLAGS = -std=c11 -Wall -Wextra -g3 -O0
CPPFLAGS = -I../include

ulepng:
	${CC} ${CFLAGS} ${CPPFLAGS} ulepng_test.c ../build/libulepng.a -o ulepng_test.bin

ulepipe:
	${CC} ${CFLAGS} ${CPPFLAGS} ulepipe_test.c ../build/libulepipe.a -o ulepipe_test.bin
	${CC} ${CFLAGS} ${CPPFLAGS} ulepipe_test_ctl.c ../build/libulepipe.a -o ulepipe_test_ctl.bin

