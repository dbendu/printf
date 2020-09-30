#ifndef PRINTF_OUTPUT_H
#define PRINTF_OUTPUT_H

#include <stdbool.h>

struct		s_output
{
	bool	to_str;

	char	*str;
	int		fd;
};

#endif //PRINTF_OUTPUT_H
