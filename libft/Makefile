# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/21 04:18:40 by tkleiner          #+#    #+#              #
#    Updated: 2020/05/21 18:34:01 by tkleiner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC_DIR = ./libft
OBJ_DIR = ./libft

MAIN_SRCS =	ft_memset.c		ft_memchr.c		ft_memcpy.c		ft_memcmp.c		ft_memmove.c	ft_memccpy.c \
			ft_bzero.c		ft_calloc.c \
			ft_isalnum.c	ft_isalpha.c	ft_isascii.c	ft_isdigit.c	ft_isprint.c \
			ft_tolower.c	ft_toupper.c \
			ft_strchr.c		ft_strlen.c		ft_strdup.c		ft_strlcat.c	ft_strlcpy.c	ft_strncmp.c \
			ft_strnstr.c	ft_strrchr.c \
			ft_atoi.c		ft_itoa.c \
			ft_strtrim.c	ft_strmapi.c	ft_substr.c		ft_split.c		ft_strjoin.c \
			ft_putendl_fd.c	ft_putnbr_fd.c	ft_putchar_fd.c	ft_putstr_fd.c \
			ft_rmchar.c		ft_abs.c
MAIN_OBJS = $(MAIN_SRCS:.c=.o)
BONUS_SRC = ft_lstsize.c	ft_lstnew.c		ft_lstlast.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstdelone.c	ft_lstclear.c \
			ft_lstiter.c	ft_lstmap.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

ifdef MAKE_BONUS
SRC = $(BONUS_SRC) $(MAIN_SRCS)
OBJ = $(BONUS_OBJ) $(MAIN_OBJS)
else
SRC = $(MAIN_SRCS)
OBJ = $(MAIN_OBJS)
endif

SRC := $(addprefix $(SRC_DIR)/, $(MAIN_SRCS))
OBJ := $(addprefix $(OBJ_DIR)/, $(MAIN_OBJS))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c $(SRC)
	@gcc $(FLAGS) -c $< -o $@

bonus:
	@$(MAKE) MAKE_BONUS=1 all

clean:
	@rm -rf $(OBJ_DIR)/*.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
