#include "printf_appenders.h"

void	fprintf_appender(const char *src, int bytes, void *dest)
{
	printf_appender(src, bytes, dest);
}
