#include <stddef.h>
#include <stdint.h>

#include "ft_printf.h"
#include "print_config.h"
#include "print_formatted.h"

int	ft_vprintf(const char *format, va_list args)
{
	t_print_config	config;
	int				ret;

	// TODO: инициализировать buffer и appender
	config = config_init(INT32_MAX, NULL, NULL);
	ret = print_formatted(format, args, config);
	return (ret);
}
