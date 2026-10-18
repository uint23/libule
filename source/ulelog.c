#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "ulelog.h"

static void log(FILE* fd, const char* fmt, va_list ap)
{
	fprintf(fd, "Magnolia: ");
	vfprintf(fd, fmt, ap);
	fputc('\n', fd);
	fflush(fd);
}

void ulelog(int code, const char* fmt, ...)
{

}

void ulelog_die(int code, const char* fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	vlog(stderr, fmt, ap);
	va_end(ap);

	fprintf(stderr, "Died with ErrorCode [%d]\n", code);
	exit(code);
}

void mg_log(const char* fmt, ...)
{
#ifndef NDEBUG
	int debug = 1;
#else
	int debug = 0;
#endif
	FILE*   fd;
	va_list ap;

	if (lt == LOG_DBG && !debug)
		return;

	if (lt == LOG_DBG || lt == LOG_ERR) {
		fd = stderr;
	}
	else {
		fd = stdout;
	}

	va_start(ap, fmt);
	vlog(fd, fmt, ap);
	va_end(ap);
}

