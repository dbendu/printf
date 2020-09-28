#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdarg.h>

/*
 * На эту величину так же увеличивается строка, формируемая в ft_asprintf
*/
# define PRINTF_BUFSIZE	1024

/*
 * printf   -- выводит обработанную строку в stdout
 *
 * sprintf  -- пишет вывод в переданную строку. Не следит за переполнением
 *
 * snprintf -- пишет в переданную строку не больше max байт
 *
 * asprintf -- сам выделяет память под строку для запись.
 * За освобождение памяти ответвенна вызывающая функция.
 *
 * fprintf  -- пишет вывод в указанный fd
 *
 * vprintf  -- получает на вход готовый va_list
*/
int	ft_printf(const char *format, ...);
int	ft_sprintf(char *dest, const char *format, ...);
int	ft_snprintf(char *dest, int max, const char *format, ...);
int	ft_asprintf(char **destptr, const char *format, ...);
int	ft_fprintf(int fd, const char *format, ...);
int	ft_vprintf(const char *format, va_list args_ptr);

#endif
