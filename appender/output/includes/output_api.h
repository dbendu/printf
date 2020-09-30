#ifndef PRINTF_OUTPUT_API_H
#define PRINTF_OUTPUT_API_H

typedef struct s_output *t_output;

t_output		output_fd_create(int dest_fd);
t_output		output_str_create(char *dest_str);

void			output_destroy(t_output output);

#endif //PRINTF_OUTPUT_API_H
