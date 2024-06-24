# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 19:38:04 by ohertzbe          #+#    #+#              #
#    Updated: 2024/06/24 22:01:46 by ohertzbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Canonical
CC = c++
CFLAGS = -Wall -Wextra -Werror
SRC = main.cpp Fixed.cpp
OBJ = $(patsubst %.cpp, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re