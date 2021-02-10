#include <stddef.h>
#include <stdlib.h>

#include "appender_api.h"
#include "appender.h"
#include "printf_appenders.h"

static void	*select_appender_func(t_printf_type_enum type);

t_appender	appender_create(t_output dest, t_printf_type_enum type)
{
	struct s_appender *appender;

	appender = malloc(sizeof(struct s_appender)); // TODO: проверять возврат
	appender->dest = dest;
	appender->append = select_appender_func(type);
	return appender;
}

static void	*select_appender_func(t_printf_type_enum type)
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