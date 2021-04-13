#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: goosterl <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/28 14:03:10 by goosterl      #+#    #+#                  #
#    Updated: 2019/12/04 13:26:41 by goosterl      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = libft.a

CC = gcc

CCFLAGS = -Wall -Werror -Wextra -Ofast

SRC = 	ft_strlen.c 		ft_toupper.c 		ft_tolower.c	\
		ft_isprint.c 		ft_isascii.c 		ft_isalnum.c	\
		ft_isdigit.c		ft_isalpha.c		ft_atoi.c		\
		ft_memcpy.c			ft_memset.c			ft_bzero.c		\
		ft_strlcpy.c		ft_strchr.c			ft_strlcat.c	\
		ft_memccpy.c		ft_memcmp.c			ft_memmove.c	\
		ft_memchr.c			ft_strchr.c			ft_strrchr.c	\
		ft_strnstr.c		ft_strncmp.c		ft_calloc.c		\
		ft_strdup.c			ft_substr.c			ft_strjoin.c	\
		ft_strtrim.c		ft_putchar_fd.c		ft_putstr_fd.c	\
		ft_split.c			ft_itoa.c			ft_putnbr_fd.c	\
		ft_strmapi.c		ft_putendl_fd.c		ft_strntok.c	\
		ft_atof.c			ft_strspn.c			ft_match.c		\
		ft_isspace.c											\
		ft_lstnew_bonus.c		ft_lstadd_front_bonus.c			\
		ft_lstsize_bonus.c		ft_lstlast_bonus.c				\
		ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c			\
		ft_lstclear_bonus.c		ft_lstiter_bonus.c				\
		ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)
INCLUDE = libft.h
LIB = ar rcs
RM =  rm -f

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

all: $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
