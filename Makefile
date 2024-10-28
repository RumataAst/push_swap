# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 19:44:01 by akretov           #+#    #+#              #
#    Updated: 2024/04/14 15:39:48 by akretov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	cc

CFLAGS		=	-g -Wall -Wextra -Werror

INCLUDE		=	-I.

LIB			=	-L./libft -lft

SRCS		=	srcs/main.c 		 			\
				srcs/utils.c        			\
				srcs/alg_utils_0.c              \
				srcs/alg_utils_1.c              \
				srcs/stack_init.c				\
				srcs/operations_rr_1.c    		\
				srcs/operations_sa_ra_0.c 		\
				srcs/operations_push_2.c 		\
				srcs/mini_sort.c				\
				srcs/turk_alg_0.c               \
				srcs/turk_alg_1.c               \
				srcs/turk_alg_2.c               \
				srcs/han_errors.c

OBJS		= 	$(SRCS:.c=.o)

LIBPATH		= 	libft/

all:		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C $(LIBPATH)
			$(CC) $(CFLAGS) $^ $(INCLUDE) $(LIB) -o $@

clean:
			$(MAKE) clean -C $(LIBPATH)
			rm -f srcs/*.o

fclean:		clean
			$(MAKE) fclean -C $(LIBPATH)
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
