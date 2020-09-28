#include <stdlib.h>

#include "buffer_api.h"
#include "buffer.h"

t_buffer	buf_create(void *appender)
{
	t_buffer	buffer;

	buffer = malloc(sizeof(struct s_buffer) + BUFFER_SIZE); // TODO: проверять результат
	buffer->appender = appender;
	buffer->data = (void*)buffer + sizeof(struct s_buffer);
	buffer->position = 0;
	return buffer;
}
