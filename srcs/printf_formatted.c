#include "print_formatted.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

void	insert_type(const char **format, t_specifier *spec)
{
	int		i;
	char	types[20] = {'d', 'i', 'o', 'u', 'x', 'X', 'f', 'F', 'e', 'E',
						 'g', 'G', 'a', 'A', 'c', 's', 'S', 'p', 'n', '\0'};

	i = 0;
	while (types[i] != '\0')
	{
		if (**format == types[i])
		{
			spec->type = types[i];
			++*format;
			break;
		}
		++i;
	}
}

void	insert_size(const char **format, t_specifier *spec)
{
	if (**format == 'l')
		spec->size = 'l';
	else if (**format == 'h')
		spec->size = 'h';
	else if (**format == 'j')
		spec->size = 'j';
	else if (**format == 'z')
		spec->size = 'z';
	else if (**format == 't')
		spec->size = 't';
	else if (**format == 'L')
		spec->size = 'L';
	if (spec->size != 0)
	{
		++*format;
		if (!(check_type(**format)) && **format != '\0' && check_size(**format))
		{
			if (**format == 'l')
				spec->double_l = true;
			else
				spec->double_h = true;
			++*format;
		}
	}
}

void	insert_precision(const char **format, t_specifier *spec, va_list args)
{
	char	num[PRINTF_BUFSIZE];
	int		i;

	num[PRINTF_BUFSIZE - 1] = '\0';
	if (**format == '*')
	{
		spec->precision = va_arg(args, int);
		++*format;
	}
	else if (**format != '\0' && **format == '.')
	{
		++*format;
		if (**format == '*')
		{
			spec->precision = va_arg(args, int);
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
				spec->precision = ft_atoi(num);
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

t_specifier	init_specifier(void)
{
	t_specifier		spec;

	spec.flag = 0;
	spec.width = 0;
	spec.precision = 0;
	spec.size = 0;
	spec.double_h = false;
	spec.double_l = false;
	spec.type = 0;
	return (spec);
}

/*
 * main_handle - функция, с которой будет стартовать обработка спецификаторов
 */

int		main_handle(const char **format, va_list args)
{
	t_specifier		spec;
	int				res;
	// char			c;

	res = 0;
	spec = init_specifier();
	insert_flags(&spec, format);
	if (**format == '.' || (insert_width(format, &spec, args)))
		insert_precision(format,&spec, args);
	insert_size(format, &spec);
	insert_type(format, &spec);

	printf("flag = %c\n", spec.flag);
	printf("width = %lu\n", spec.width);
	printf("precision = %lu\n", spec.precision);
	printf("size = %c\n", spec.size);
	printf("double_h = %d\n", spec.double_h);
	printf("double_l = %d\n", spec.double_l);
	printf("type = %c\n", spec.type);

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