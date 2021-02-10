#include <stddef.h>

#include "print_config.h"
#include "buffer_api.h"

t_print_config	config_init(int max_to_print, t_buffer buffer)
{
	t_print_config config;

	config.buffer = buffer;
	config.max_to_print = max_to_print;
	config.printed = 0;
	return (config);
}
