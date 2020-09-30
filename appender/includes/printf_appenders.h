#ifndef PRINTF_PRINTF_APPENDERS_H
#define PRINTF_PRINTF_APPENDERS_H

#include "output_api.h"

void	printf_appender(const char *src, int bytes, t_output dest);
void	sprintf_appender(const char *src, int bytes, t_output dest);
void	snprintf_appender(const char *src, int bytes, t_output dest);
void	asprintf_appender(const char *src, int bytes, t_output dest);
void	fprintf_appender(const char *src, int bytes, t_output dest);
void	vprintf_appender(const char *src, int bytes, t_output dest);

#endif
