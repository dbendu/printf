#ifndef PRINTF_APPENDER_H
#define PRINTF_APPENDER_H

#include "output_api.h"

struct			s_appender
{
	t_output	dest;
	void		(*append)(const char *src, int bytes, t_output dest);
};

#endif
