#include <stdlib.h>

#include "output_api.h"
#include "output.h"

t_output output_fd_create(int fd)
{
	struct s_output *output;

	output = malloc(sizeof(struct s_output)); // TODO: проверять возврат
	output->fd = fd;
	output->to_str = false;
	return output;
}