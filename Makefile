all:
	gcc -Wall -Werror -Wextra													\
	                                                                            \
	-I includes -I appender/includes -I appender/output/includes				\
	-I buffer/includes -I test/includes                                         \
	                                                                            \
	srcs/printfs/*.c  srcs/printf_config/*.c test/srcs/*.c test/main.c          \
	buffer/srcs/*.c appender/srcs/*.c appender/output/srcs/*.c                  \
	appender/srcs/printf_appenders/*.c
