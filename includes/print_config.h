#ifndef PRINT_DATA_H
#define PRINT_DATA_H

#include <stdarg.h>
#include <stdbool.h>

/*
 * max_to_print показывает максимальное кол-во символов, которое
 * printf может записать в указанное место.
 *
 * printed -- сколько символов записано на данный момент
 *
 * buffer -- структура для буферизации
 *
 * appender -- структура для вывода результата
 *
 * NOTE
 * buffer и appender пока не реализованы
*/
typedef struct	s_print_config
{
	int			max_to_print;
	int			printed;

	void		*buffer;
	void		*appender;
}				t_print_config;

t_print_config	config_init(int max_to_print, void *buffer, void *appender);

#endif
