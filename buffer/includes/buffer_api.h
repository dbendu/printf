#ifndef BUFFER_API_H
# define BUFFER_API_H

#include "appender_api.h"

typedef struct s_buffer *t_buffer;

t_buffer	buf_create(t_appender appender);
void		buf_destroy(t_buffer buffer);

void		buf_add_str(t_buffer buffer, const char *str);
void		buf_add_char(t_buffer buffer, char c);
void		buf_add_nchar(t_buffer buffer, char c, int times);

void		buf_flush(t_buffer buffer);

#endif
