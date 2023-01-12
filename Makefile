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

OFILES =	$(LIBFT:.c=.o) $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

RM = rm -f

all :	$(NAME)

$(NAME):	$(OFILES)
	@echo "\033[0;33mCompiling Pipex..."
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

clean:
	@echo "\033[31mRemoving .o files"
	@$(RM) $(OFILES)

fclean: clean
	@echo "\033[31mRemoving pipex"
	@$(RM) $(NAME)

re: fclean all

.SILENT: $(NAME) $(OFILES)

.PHONY: all clean fclean re
