# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 13:27:21 by mshehata          #+#    #+#              #
#    Updated: 2023/01/11 14:40:38 by mshehata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Library = libft

PART1 =	ft_strlen.c ft_strchr.c\
		ft_strncmp.c ft_strdup.c\

PART2 =	ft_split.c ft_strjoin.c ft_substr.c\

CC = gcc

FLAGS = -Wall -Wextra -Werror -c

OUTN = $(Library).a

SRC = $(PART1) $(PART2)

M_OFILES = $(SRC:.c=.o)

NAME = $(OUTN)

$(NAME):
		$(CC) $(FLAGS) $(SRC) -I./
		ar -rc $(OUTN) $(M_OFILES)

all: $(NAME)

clean:
	rm -f $(M_OFILES) $(B_OFILES)

fclean:	clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
