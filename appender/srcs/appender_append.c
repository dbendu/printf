#include "appender_api.h"
#include "appender.h"

void	appender_append(t_appender appender, const char *src, int bytes)
{
	appender->append(src, bytes, appender->dest);
}