#include <stddef.h>

#include "appender_api.h"
#include "appender.h"
#include "printf_appenders.h"

static void	*select_append_func(t_printf_type_enum type)
{
	if (type == PRINTF)
		return printf_appender;
	else if (type == VPRINTF)
		return vprintf_appender;
	else if (type == FPRINTF)
		return fprintf_appender;
	else if (type == SPRINTF)
		return sprintf_appender;
	else if (type == SNPRINTF)
		return snprintf_appender;
	else if (type == ASPRINTF)
		return asprintf_appender;
	else
		return NULL;
}

t_appender	appender_create(void *dest, t_printf_type_enum type)
{
	t_appender appender;

	appender.dest = dest;
	appender.append = select_append_func(type);
	return appender;
}