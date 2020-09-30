#ifndef PRINTF_APPENDER_H
#define PRINTF_APPENDER_H

struct		s_appender
{
	void	*dest;
	void	(*append)(const char *src, int bytes, void *dest);
};

#endif
