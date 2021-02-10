#include <stddef.h>

#include "tests.h"
#include "output_api.h"
#include "output.h"

void	test_fd_output(void);
void	test_str_output(void);

void	output_test(void)
{
	test_fd_output();
	test_str_output();
}

void	test_fd_output(void)
{
	t_output output = output_fd_create(1);
	assert(output->fd == 1);
	assert(output->to_str == false);
	output_destroy(output);
}

void	test_str_output(void)
{
	t_output output = output_str_create(NULL);
	assert(output->str == NULL);
	assert(output->to_str == true);
	output_destroy(output);

	output = output_str_create((char *) 0xffaa);
	assert(output->str == (char*)0xffaa);
	assert(output->to_str == true);
	output_destroy(output);
}