#include <stddef.h>

#include "ft_printf.h"
#include "print_config.h"
#include "print_formatted.h"

int	ft_snprintf(char *dest, int max, const char *format, ...)
{
	t_print_config	config;
	va_list			args;

	config.appendable = false;
	config.to_str = true;
	config.str = dest;
	config.fd = -1;
	config.max_to_print = max;
	config.printed = 0;
	va_start(args, format);

	int ret = print_formatted(format, args, config);
	return (ret);
}
