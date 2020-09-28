#include "print_formatted.h"
#include "ft_printf.h"
#include <unistd.h>
#include "libft.h"

bool	check_size(const char c);
bool	check_type(const char c);

void	insert_precision(const char **format, t_specifier *spec, va_list args)
{
	char	num[PRINTF_BUFSIZE];
	int		i;

	num[PRINTF_BUFSIZE - 1] = '\0';
	if (**format == '*')
	{
		spec->width = va_arg(args, int);
		++*format;
	}
	else if (**format != '\0' && **format == '.')
	{
		++*format;
		if (**format == '*')
		{
			spec->width = va_arg(args, int);
			++*format;
		}
		else
		{
			i = 0;
			while (**format != '\0' && !(check_type(**format)) &&
					!(check_size(**format)))
			{
				num[i] = **format;
				++i;
				++*format;
			}
			num[i] = '\0';
			if (i != 0)
				spec->width = ft_atoi(num);
		}
	}
}

bool	insert_width(const char **format, t_specifier *spec, va_list args)
{
	char	num[PRINTF_BUFSIZE];
	int		i;

	num[PRINTF_BUFSIZE - 1] = '\0';
	if (**format == '*')
	{
		spec->width = va_arg(args, int);
		++*format;
		return (true);
	}
	else if (**format != '\0' && **format != '*' && **format != '.' &&
				!(check_type(**format)) && !(check_size(**format)))
	{
		i = 0;
		while (**format != '\0' && **format != '*' && **format != '.' &&
				!(check_type(**format)) && !(check_size(**format)))
		{
			num[i] = **format;
			++i;
			++*format;
		}
		num[i] = '\0';
		spec->width = ft_atoi(num);
		return (true);
	}
	return (false);
}

bool	check_size(const char c)
{
	int		i;
	char	sizes[7] = {'l', 'h', 'j', 'z', 't', 'L', '\0'};

	i = 0;
	while (sizes[i] != '\0')
	{
		if (c == sizes[i])
			return (true);
		++i;
	}
	return (false);
}

void	insert_flags(t_specifier *spec, const char **format)
{
	if (**format == '-')
		spec->flag = '-';
	else if (**format == '+')
		spec->flag = '+';
	else if (**format == ' ')
		spec->flag = ' ';
	else if (**format == '#')
		spec->flag = '#';
	else if (**format == '0')
		spec->flag = '0';
	if (spec->flag != 0)
		++*format;
}

bool	check_type(const char c)
{
	int		i;
	char	types[20] = {'d', 'i', 'o', 'u', 'x', 'X', 'f', 'F', 'e', 'E',
					'g', 'G', 'a', 'A', 'c', 's', 'S', 'p', 'n', '\0'};

	i = 0;
	while (types[i] != '\0')
	{
		if (c == types[i])
			return (true);
		++i;
	}
	return (false);
}

bool	init_specifier(t_specifier	*spec)
{
	if (!(spec = (t_specifier *)malloc(sizeof(t_specifier))))
		return (false);
	spec->flag = 0;
	spec->width = 0;
	spec->precision = 0;
	spec->size = 0;
	spec->double_h = false;
	spec->double_l = false;
	spec->type = 0;
	return (true);
}

/*
 * main_handle - функция, с которой будет стартовать обработка спецификаторов
 */

int		main_handle(const char **format, va_list args)
{
	t_specifier		*spec;
	int				res;
	char			c;

	res = 0;
	if (!(init_specifier(spec)))
		return (-1);
	insert_flags(spec, format);
	if (**format == '.' || (insert_width(format, spec, args)))
		insert_precision(format,spec, args);


	// while (!(**format >= 'a' && **format <= 'z') && !(**format >= 'A' && **format <= 'Z'))
	// {
	// 	++*format;
	// }
	// if (**format == 'c')
	// {
	// 	c = (char)va_arg(args, int);
	// 	write(1, &c, 1);
	// 	++res;
	// }

	return (res);
}

int		print_formatted(const char *format, va_list args, t_print_config config)
{
	int		res;

	res = 0;
	/*------DON'T ASK!-----*/
	/*------JUST NEED------*/
	int		i;
	if (config.printed == 0)
		i = 5;
	/*---------------------*/
	while (*format && *format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			++format;
			++res;
		}
		else
		{
			++format;
			/*
			 * Если "%%" просто печатаем "%"
			*/
			if (*format != '\0' && *format == '%')
			{
				write(1, format, 1);
				++format;
				++res;
			}
			else
				res += main_handle(&format, args);
		}
	}
	return (res);
}
