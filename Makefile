NAME=pipex
SRCS = pipex.c ft_putstr.c ft_init.c ft_arg_check.c \
	   ft_empty_check.c ft_path_parser.c ft_pipe_open.c \
	   ft_pipe_close.c ft_pipe_setup.c ft_run_cmd.c ft_input_fd.c \
	   ft_output_fd.c ft_free2.c ft_wait.c ft_lstsize.c ft_split.c \
	   ft_strapp.c ft_strdup.c ft_strlcpy.c ft_strlen.c ft_substr.c \
	   ft_strjoin.c ft_strncmp.c ft_lstadd_back.c ft_lstlast.c ft_lstnew.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)
clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re