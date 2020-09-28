#ifndef PRINT_DATA_H
#define PRINT_DATA_H

#include <stdarg.h>
#include <stdbool.h>

/*
 * Вывод может осуществляться в файловый дескриптор или в строку.
 * Это отображает состояние переменной to_str:
 * true — выводится в строку, false — в дескриптор.
 *
 * appendable используется при работе ft_asprintf и показывает,
 * должен ли ft_printf увеличивать объем строки
 * по мере заполнения.
 *
 * max_to_print и printed используются при работе ft_snprintf.
 * max_to_printf показывает максимальное кол-во символов,
 * которое может быть записано в строку.
 * printed — сколько символов записано в данный момент.
 *
 * str -- указатель на указатель, а не просто указатель,
*/
typedef struct	s_print_config
{
	int			fd;
	char		*str;

	int			max_to_print;
	int			printed;

	bool		appendable;
	bool		to_str;
}				t_print_config;

#endif
