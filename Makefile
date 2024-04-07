NAME = push_swap

CC = gcc

FLAGS = -g -Wall -Wextra -Werror

SOURCE  =  source/push_swap_main.c \
		   source/utils.c \
		   source/han_errors/*.c \
		   source/stack/*.c \
		   source/libft/*.c \
		   source/initial_commands/*.c

$(NAME):
	$(CC) $(FLAGS) $(SOURCE) -I includes -o $(NAME)

all: $(NAME)

clean:
	@rm -rf source/push_swap_main.o
	@rm -rf source/utils.o
	@rm -rf source/han_errors/*.o
	@rm -rf source/initial_commands/*.o
	@rm -rf source/stack/*.o
	@rm -rf source/libft/*.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all