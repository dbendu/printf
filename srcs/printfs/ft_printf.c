#include <stddef.h>
#include <stdint.h>

#include "ft_printf.h"
#include "print_config.h"
#include "print_formatted.h"

int	ft_printf(const char *format, ...)
{
	t_print_config	config;
	va_list			args;

	config.appendable = false;
	config.to_str = false;
	config.str = NULL;
	config.fd = 1;
	config.max_to_print = INT32_MAX;
	config.printed = 0;
	va_start(args, format);

	int ret = print_formatted(format, args, config);
	return (ret);
}
