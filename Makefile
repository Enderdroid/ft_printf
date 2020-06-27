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

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
SRC_DIR = ./srcs
OBJ_DIR = ./obj
HEADERS = $(SRC_DIR)/libftprintf.h $(LIBFT_DIR)/libft.h


MAIN_SRCS	:=	ft_printf.c		ft_parse.c		ft_pattern.c \
				ft_printf.c		ft_print.c		ft_printstr.c \
				ft_print_c.c	ft_print_hex.c	ft_print_i.c	ft_print_u.c	ft_print_s.c \
				ft_s_reset.c	ft_validate.c	ft_free_p.c		ft_putchar.c
MAIN_OBJS	= $(MAIN_SRCS:.c=.o)
LIBFT_SRCS	:=	ft_strchr.c		ft_rmchar.c		ft_atoi.c		ft_isdigit.c \
				ft_strjoin.c	ft_strlcat.c	ft_calloc.c	\
				ft_strlen.c		ft_itoa.c		ft_putchar_fd.c	\
				ft_putstr_fd.c	ft_memset.c		ft_bzero.c		ft_substr.c		ft_strlcpy.c	ft_strdup.c ft_memcpy.c	ft_abs.c
LIBFT_OBJS	= $(LIBFT_SRCS:.c=.o)
BONUS_SRC	:=	ft_lstsize.c	ft_lstnew.c		ft_lstlast.c \
				ft_lstadd_front.c \
				ft_lstadd_back.c \
				ft_lstdelone.c	ft_lstclear.c \
				ft_lstiter.c	ft_lstmap.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

ifdef MAKE_BONUS
SRC = $(BONUS_SRC) $(MAIN_SRCS) $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRCS))
OBJ = $(BONUS_OBJ) $(MAIN_OBJS) $(addprefix $(LIBFT_DIR)/, $(LIBFT_OBJS))
else
SRC := $(addprefix $(SRC_DIR)/, $(MAIN_SRCS)) $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRCS))
OBJ := $(addprefix $(OBJ_DIR)/, $(MAIN_OBJS)) $(addprefix $(OBJ_DIR)/, $(LIBFT_OBJS))
endif

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $?
	@ranlib $@

$(OBJ_DIR)/%.o: ./*/%.c $(HEADERS) | $(OBJ_DIR)
	@gcc $(FLAGS) -I. -c $< -o $@

bonus:
	@$(MAKE) MAKE_BONUS=1 all

clean:
	@rm -rf ./obj/*.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
