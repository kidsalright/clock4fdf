# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yberries <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 17:04:49 by yberries          #+#    #+#              #
#    Updated: 2020/09/22 23:38:04 by yberries         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror
INCLUDES = /
SRC = ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_countwords.c \
	  ft_itoa.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstcount.c \
	  ft_lstrev.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_isspace.c \
	  ft_root.c \
	  ft_realloc.c \
	  btree_create_node.c \
	  btree_insert_data.c \
	  get_next_line.c \
	  ft_nbrlen.c

OBJ = $(SRC:.c=.o)
PFT = ft_printf/
PFT_OBJ = $(PFT)/obj/*

S_CLN = \033[K
C_RED = \033[31m
C_GRN = \033[32m
C_CYAN = \033[36m


all: $(NAME)

%.o: %.c
	@printf "\r$(S_CLN)$(C_CYAN)Assembling $< > $@"
	@gcc $(FLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	@printf "\r$(S_CLN)$(C_GRN)Libft compiled\n"
	@make -sC $(PFT)
#	@printf "\r$(S_CLN)$(C_GRN)Ft_printf compiled\n"
	@ar rc $(NAME) $(OBJ) $(PFT_OBJ)
	@ranlib $(NAME)
	@printf "\r$(R_CLEAN)$(C_GRN)Libft built\n"

clean:
	@make -sC $(PFT) clean
	@printf "$(C_RED)Remove libft *.o\n"
	@rm -rf $(OBJ)

fclean: clean
	@printf "$(C_RED)Remove libft.a\n"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
