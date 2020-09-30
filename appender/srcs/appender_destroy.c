#include <stdlib.h>

#include "appender_api.h"
#include "appender.h"

void appender_destroy(t_appender appender)
{
	output_destroy(appender->dest);
	free(appender);
}