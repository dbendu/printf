#include <stdlib.h>

#include "output_api.h"
#include "output.h"

void output_destroy(t_output output)
{
	free(output);
}