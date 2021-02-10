#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_sprintf(char *dest, const char *format, ...);
int	ft_snprintf(char *dest, int max, const char *format, ...);
int	ft_asprintf(char **destptr, const char *format, ...);
int	ft_fprintf(int fd, const char *format, ...);
int	ft_vprintf(const char *format, va_list args_ptr);

#endif
