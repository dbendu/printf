#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "printf_bufsize_const.h"
#include "ft_printf.h"
#include "print_config.h"
#include "print_formatted.h"

int	ft_aprintf(char **strptr, const char *format, ...)
{
	t_print_config	config;
	va_list			args;

	config.appendable = true;
	config.to_str = true;
	config.str = malloc(PRINTF_BUFSIZE); // TODO: проверить возврат
	config.fd = -1;
	config.max_to_print = INT32_MAX;
	config.printed = 0;
	va_start(args, format);

	int ret = print_formatted(format, args, config);
	*strptr = config.str;
	return (ret);
}
