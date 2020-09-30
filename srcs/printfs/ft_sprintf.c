#include <stddef.h>
#include <stdint.h>

#include "ft_printf.h"
#include "print_config.h"
#include "print_formatted.h"
#include "output_api.h"

static t_appender appender_init();

int	ft_sprintf(char *dest, const char *format, ...)
{
	t_print_config	config;
	va_list			args;
	int				ret;

	// TODO: инициализировать buffer и appender
	config = config_init(INT32_MAX, NULL, appender_create(NULL, VPRINTF));
	va_start(args, format);
	ret = print_formatted(format, args, config);
	va_end(args);
	return (ret);

		(void)dest;
}

static t_appender appender_init(char *dest_str)
{
	t_appender appender;
	t_output output;

	output = output_str_create(dest_str);
	appender = appender_create(output, SPRINTF);
}