all:
	gcc -Wall -Werror -Wextra													\
	-I includes																		\
	srcs/printfs/*.c srcs/*.c
