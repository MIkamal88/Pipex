# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 13:27:21 by mshehata          #+#    #+#              #
#    Updated: 2023/01/09 09:41:11 by mshehata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Library = libft

PART1 =	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c\
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c\
		ft_calloc.c ft_strdup.c\

PART2 = ft_striteri.c ft_strmapi.c ft_putchar_fd.c ft_putendl_fd.c ft_split.c\
		ft_putstr_fd.c ft_strjoin.c ft_strtrim.c ft_substr.c ft_putnbr_fd.c\
		ft_itoa.c\

BONUS = ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_lstmap.c\
		ft_lstadd_front.c ft_lstadd_back.c ft_lstiter.c ft_lstclear.c\

CC = gcc

FLAGS = -Wall -Wextra -Werror -c

OUTN = $(Library).a

SRC = $(PART1) $(PART2)

B_OFILES = $(BONUS:.c=.o)

M_OFILES = $(SRC:.c=.o)

NAME = $(OUTN)

$(NAME):
		$(CC) $(FLAGS) $(SRC) -I./
		ar -rc $(OUTN) $(M_OFILES)

all: $(NAME)

bonus:	$(M_OFILES) $(B_OFILES)
		ar -rc $(OUTN) $(B_OFILES)

clean:
	rm -f $(M_OFILES) $(B_OFILES)

fclean:	clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
