#ifndef PRINT_FORMATTED_H
# define PRINT_FORMATTED_H

# include "print_config.h"

typedef		struct	s_specifier
{
	char	flag;
	long	width;
	long	precision;
	char	size;
	bool	double_h;
	bool	double_l;
	char	type;
}					t_specifier;


int	print_formatted(const char *format, va_list args, t_print_config config);

#endif
