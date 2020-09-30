#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "printf_bufsize_const.h"
#include "ft_printf.h"
#include "print_config.h"
#include "print_formatted.h"
#include "buffer_api.h"

static t_buffer buffer_init();

int	ft_asprintf(char **strptr, const char *format, ...)
{
	t_print_config	config;
	va_list			args;
	int				ret;

	// TODO: инициализировать buffer и appender
	config = config_init(INT32_MAX, buffer_init());
	va_start(args, format);
	ret = print_formatted(format, args, config);
	va_end(args);
	// TODO: записывать в *strptr результат
	*strptr = NULL;
	return (ret);
}

static t_buffer buffer_init()
{
	t_buffer buffer;
	t_appender appender;
	t_output output;

	output = output_str_create(NULL, ASPRINTF);
	appender = appender_create(output);
	buffer = buf_create(appender);
	return buffer;
}