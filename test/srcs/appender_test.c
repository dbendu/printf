#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#include "tests.h"
#include "appender_api.h"
#include "appender.h"
#include "output_api.h"
#include "printf_appenders.h"

void test_appender_fields();
void test_appender_output();

void appender_test(void)
{
	test_appender_fields();
	test_appender_output();
}

void test_appender_fields()
{
	t_output output = output_fd_create(1);
	t_appender appender = appender_create(output, PRINTF);
	assert(appender->dest == output);
	assert(appender->append == printf_appender);
	appender_destroy(appender);

	output = output_fd_create(1);
	appender = appender_create(output, ASPRINTF);
	assert(appender->append == asprintf_appender);
	appender_destroy(appender);
}

void test_appender_output()
{
	const char FILE[] = "file";
	t_output output;
	t_appender appender;

	int fd = open(FILE, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);
	assert(fd != -1);
	output = output_fd_create(fd);
	appender = appender_create(output, PRINTF);
	appender->append("qwerty", 5, appender->dest);
	close(fd);
	fd = open(FILE, O_RDONLY);
	assert(fd != -1);
	char buf[100];
	ssize_t ret = read(fd, buf, 100);
	assert(strncmp("qwerty", buf, ret) == 0);
	remove(FILE);
}