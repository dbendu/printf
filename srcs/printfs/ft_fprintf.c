#include <stddef.h>
#include <stdint.h>

#include "ft_printf.h"
#include "print_config.h"
#include "print_formatted.h"
#include "output_api.h"

t_appender appender_init(int fd);

int	ft_fprintf(int fd, const char *format, ...)
{
	t_print_config	config;
	va_list			args;
	int				ret;

	// TODO: инициализировать buffer и appender
	config = config_init(INT32_MAX, NULL, appender_init(fd));
	va_start(args, format);
	ret = print_formatted(format, args, config);
	va_end(args);
	return (ret);

		(void)fd;
}

static t_appender appender_init(int fd)
{
	t_appender appender;
	t_output output;

	output = output_fd_create(fd);
	appender = appender_create(output, FPRINTF);
	return appender;
}