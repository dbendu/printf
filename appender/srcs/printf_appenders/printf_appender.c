#include <unistd.h>

#include "printf_appenders.h"

void	printf_appender(const char *src, int bytes, void *dest)
{
	(void)src;
	(void)bytes;
	(void)dest;
//	write(dest->fd, src, bytes);
//	dest->printed += bytes;
}