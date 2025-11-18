# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 17:36:02 by digulraj          #+#    #+#              #
#    Updated: 2025/11/18 16:01:56 by digulraj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
FLAGS = -Wall -Wextra -Werror -I. 

SRC = ft_split.c init_utils.c initialisation.c push_ops.c push_swap.c swap_ops.c rotate_ops.c revrotate_ops.c sorting_small.c sorting_utils.c sorting_utils2.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)
	
$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
	
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Object files deleted"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ)
	@echo "Executable and object files deleted"

re: fclean all

.PHONY: all clean fclean re $(NAME)