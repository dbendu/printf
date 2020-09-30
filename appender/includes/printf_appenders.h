#ifndef PRINTF_PRINTF_APPENDERS_H
#define PRINTF_PRINTF_APPENDERS_H

void	printf_appender(const char *src, int bytes, void *dest);
void	sprintf_appender(const char *src, int bytes, void *dest);
void	snprintf_appender(const char *src, int bytes, void *dest);
void	asprintf_appender(const char *src, int bytes, void *dest);
void	fprintf_appender(const char *src, int bytes, void *dest);
void	vprintf_appender(const char *src, int bytes, void *dest);

#endif
