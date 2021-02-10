#include <stddef.h>
#include <stdint.h>

#include "ft_printf.h"
#include "print_config.h"
#include "print_formatted.h"
#include "output_api.h"
#include "appender_api.h"
#include "buffer_api.h"

static t_buffer buffer_init();

int	ft_vprintf(const char *format, va_list args)
{
	t_print_config	config;
	int				ret;

	// TODO: инициализировать buffer и appender
	config = config_init(INT32_MAX, buffer_init());
	ret = print_formatted(format, args, config);
	return (ret);
}

static t_buffer buffer_init()
{
	t_buffer buffer;
	t_appender appender;
	t_output output;

	output = output_fd_create(1);
	appender = appender_create(output, VPRINTF);
	buffer = buf_create(appender);
	return buffer;
}