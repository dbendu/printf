#ifndef PRINTF_APPENDER_API_H
#define PRINTF_APPENDER_API_H

#include "output_api.h"

typedef struct s_appender *t_appender;

typedef enum	e_printf_type
{
	PRINTF,
	FPRINTF,
	VPRINTF,
	SPRINTF,
	SNPRINTF,
	ASPRINTF
}				t_printf_type_enum;

t_appender	appender_create(t_output dest, t_printf_type_enum type);

void		appender_append(t_appender appender, const char *src, int bytes);

void		appender_destroy(t_appender appender);

#endif