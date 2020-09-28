all:
	gcc -Wall -Werror -Wextra													\
	-I includes																	\
	srcs/printfs/*.c  srcs/printf_config/*.c srcs/*.c
