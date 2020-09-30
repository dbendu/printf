#include <stddef.h>

#include "print_config.h"

t_print_config	config_init(int max_to_print, void *buffer, t_appender appender)
{
	t_print_config config;

	config.buffer = buffer;
	config.appender = appender;
	config.max_to_print = max_to_print;
	config.printed = 0;
	return (config);
}
