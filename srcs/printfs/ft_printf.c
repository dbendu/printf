#include <stddef.h>
#include <stdint.h>

#include "ft_printf.h"
#include "print_config.h"
#include "print_formatted.h"

int	ft_printf(const char *format, ...)
{
	t_print_config	config;
	va_list			args;
	int				ret;

	// TODO: инициализировать buffer и appender
	config = config_init(INT32_MAX, NULL, NULL);
	va_start(args, format);
	ret = print_formatted(format, args, config);
	va_end(args);
	return (ret);
}
