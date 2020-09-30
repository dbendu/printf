#ifndef PRINT_CONFIG_H
#define PRINT_CONFIG_H

#include "buffer_api.h"

/*
 * max_to_print показывает максимальное кол-во символов, которое
 * printf может записать в указанное место.
 *
 * printed -- сколько символов записано на данный момент
 *
 * buffer -- структура для буферизации
*/
typedef struct	s_print_config
{
	int			max_to_print;
	int			printed;

	t_buffer	buffer;
}				t_print_config;

t_print_config	config_init(int max_to_print, t_buffer buffer);

#endif
