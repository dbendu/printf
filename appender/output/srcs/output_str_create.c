#include <stdlib.h>

#include "output_api.h"
#include "output.h"

t_output output_str_create(char *str)
{
	struct s_output *output;

	output = malloc(sizeof(struct s_output));
	output->str = str;
	output->to_str = true;
	return output;
}