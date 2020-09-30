#ifndef PRINTF_APPENDER_API_H
#define PRINTF_APPENDER_API_H

typedef struct s_appender t_appender;

typedef enum	e_printf_type
{
	PRINTF,
	FPRINTF,
	VPRINTF,
	SPRINTF,
	SNPRINTF,
	ASPRINTF
}				t_printf_type_enum;

t_appender	appender_create(void *dest, t_printf_type_enum type);
void		appender_append(t_appender *appender, const char *src, int bytes);

#endif