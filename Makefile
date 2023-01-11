# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 13:18:45 by mshehata          #+#    #+#              #
#    Updated: 2023/01/11 15:35:10 by mshehata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT =	./Libft/ft_split.c\
		./Libft/ft_strjoin.c\
		./Libft/ft_strncmp.c\
		./Libft/ft_strchr.c\
		./Libft/ft_strlen.c\
		./Libft/ft_substr.c\
		./Libft/ft_strdup.c\

SRCS =	./srcs/utils.c\
		./srcs/pipex.c\

OFILES = $(LIBFT:.c=.o) $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

RM = rm -f

all :	$(NAME)

$(NAME):
		$(CC) $(FLAGS) $(LIBFT) $(SRCS) -I./

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
