# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 13:18:45 by mshehata          #+#    #+#              #
#    Updated: 2023/01/16 17:18:58 by m_kamal          ###   ########.fr        #
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

FLAGS = -Wall -Wextra -Werror

RM = rm -f

all :	$(NAME)

$(NAME):	ANNOUNCE $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

ANNOUNCE:
	@echo "\033[0;33mCompiling Pipex..."

clean:
	@echo "\033[31mRemoving .o files"
	@$(RM) $(OFILES)

fclean: clean
	@echo "\033[31mRemoving pipex"
	@$(RM) $(NAME)

re: fclean all

.SILENT: $(NAME) $(OFILES)

.PHONY: all clean fclean re
