#include "printf_appenders.h"

void	snprintf_appender(const char *src, int bytes, void *dest)
{
	printf_appender(src, bytes, dest);
}