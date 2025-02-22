# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qcyril-a <qcyril-a@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/21 19:06:13 by qcyril-a          #+#    #+#              #
#    Updated: 2025/02/21 20:18:48 by qcyril-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

SRC = get_next_line

OBJ = $(SRC:=.o)

CC = gcc
CFLAG = -Wall -Wextra -Werror -D BUFFER_SIZE=n
RM = rm -f
AR = ar rc

all:$(NAME)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

${NAME}:$(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
