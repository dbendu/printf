#include <stddef.h>

#include "ft_printf.h"
#include "print_config.h"
#include "print_formatted.h"

int	ft_snprintf(char *dest, int max, const char *format, ...)
{
	t_print_config	config;
	va_list			args;
	int				ret;

	// TODO: инициализировать buffer и appender
	config = config_init(max, NULL, appender_create(NULL, SNPRINTF));
	va_start(args, format);
	ret = print_formatted(format, args, config);
	return (ret);

		(void)dest;
}
