#include <stdlib.h>

#include "buffer_api.h"
#include "buffer.h"

void	buf_destroy(t_buffer buffer)
{
	free(buffer);
}
