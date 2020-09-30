#ifndef BUFFER_H
# define BUFFER_H

#include "appender_api.h"

# define BUFFER_SIZE	1024

/*
 * data -- массив для буферизации данных
 *
 * appender -- структура, с помощью которой посредством ее API будет
 * осуществляться вывод по мере заполнения буфера
 */
struct			s_buffer
{
	int			position;
	char		*data;

	t_appender	appender;
};

#endif
