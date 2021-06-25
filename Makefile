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
LFT = libft.a

MAIN_SRCS	:=	ft_printf.c		ft_parse.c		ft_pattern.c \
				ft_printf.c		ft_print.c		ft_printstr.c \
				ft_print_c.c	ft_print_hex.c	ft_print_i.c	ft_print_u.c	ft_print_s.c \
				ft_s_reset.c	ft_validate.c	ft_free_p.c		ft_putchar.c
MAIN_OBJS	= $(MAIN_SRCS:.c=.o)

LFT_OBJ		:=	ft_strchr.o		ft_rmchar.o		ft_atoi.o		ft_isdigit.o \
				ft_strjoin.o	ft_strlcat.o	ft_calloc.o	\
				ft_strlen.o		ft_itoa.o		ft_putchar_fd.o	\
				ft_putstr_fd.o	ft_memset.o		ft_bzero.o	\
				ft_substr.o		ft_strlcpy.o	ft_strdup.o	\
				ft_memcpy.o		ft_abs.o

SRC			:= $(addprefix $(SRC_DIR)/, $(MAIN_SRCS))
M_OBJ		:= $(addprefix $(OBJ_DIR)/, $(MAIN_OBJS)) 
L_OBJ		:= $(addprefix $(LIBFT_DIR)/, $(LFT_OBJ)) 

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME): $(M_OBJ)
	@make -f $(LIBFT_DIR)/Makefile
	@ar rc $@ $? $(L_OBJ)
	@ranlib $@

$(OBJ_DIR)/%.o: ./*/%.c $(HEADERS) | $(OBJ_DIR)
	@gcc $(FLAGS) -I. -c $< -o $@

clean:
	@make clean -f $(LIBFT_DIR)/Makefile
	@rm -rf ./obj/*.o

fclean: clean
	@make fclean -f $(LIBFT_DIR)/Makefile
	@rm -rf $(NAME)

re: fclean all
