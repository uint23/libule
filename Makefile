.POSIX:

CC = cc
AR = ar
CFLAGS = -ansi -pedantic -Wall -Wextra -O2
CPPFLAGS = -Iinclude

LIBS = build/libulepipe.a \
       build/libulepng.a \
       build/libulestr.a

all: ${LIBS}

# XXX
# build/libulelog.a: source/ulelog.c include/ulelog.h
# 	mkdir -p build
# 	${CC} ${CFLAGS} ${CPPFLAGS} -c source/ulelog.c -o build/ulelog.o
# 	${AR} rcs build/libulelog.a build/ulelog.o

build/libulepipe.a: source/ulepipe.c include/ulepipe.h
	mkdir -p build
	${CC} ${CFLAGS} ${CPPFLAGS} -c source/ulepipe.c -o build/ulepipe.o
	${AR} rcs build/libulepipe.a build/ulepipe.o

build/libulepng.a: source/ulepng.c include/ulepng.h
	mkdir -p build
	${CC} ${CFLAGS} ${CPPFLAGS} -c source/ulepng.c -o build/ulepng.o
	${AR} rcs build/libulepng.a build/ulepng.o

build/libulestr.a: source/ulestr.c include/ulestr.h
	mkdir -p build
	${CC} ${CFLAGS} ${CPPFLAGS} -c source/ulestr.c -o build/ulestr.o
	${AR} rcs build/libulestr.a build/ulestr.o

# XXX
# build/libuleutf.a: source/uleutf.c include/uleutf.h include/uletypes.h
# 	mkdir -p build
# 	${CC} ${CFLAGS} ${CPPFLAGS} -c source/uleutf.c -o build/uleutf.o
# 	${AR} rcs build/libuleutf.a build/uleutf.o

clean:
	rm -rf build

