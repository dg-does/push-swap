# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 17:36:02 by digulraj          #+#    #+#              #
#    Updated: 2025/10/21 15:33:24 by digulraj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. 

SRC = 
OBJ = $(SRC:.c=.o)

all: $(NAME)
	
$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Object files deleted"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ)
	@echo "Executable and object files deleted"

re: fclean all

.PHONY: all clean fclean re $(NAME)