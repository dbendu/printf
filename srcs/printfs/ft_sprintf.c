#include <stddef.h>
#include <stdint.h>

#include "ft_printf.h"
#include "print_config.h"
#include "print_formatted.h"
#include "output_api.h"
#include "appender_api.h"
#include "buffer_api.h"

static t_buffer buffer_init(char *str);

int	ft_sprintf(char *dest, const char *format, ...)
{
	t_print_config	config;
	va_list			args;
	int				ret;

	// TODO: инициализировать buffer и appender
	config = config_init(INT32_MAX, buffer_init(dest));
	va_start(args, format);
	ret = print_formatted(format, args, config);
	va_end(args);
	return (ret);

		(void)dest;
}

static t_buffer buffer_init(char *str)
{
	t_buffer buffer;
	t_appender appender;
	t_output output;

	output = output_str_create(str);
	appender = appender_create(output, SPRINTF);
	buffer = buf_create(appender);
	return buffer;
}