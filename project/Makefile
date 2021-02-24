# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sazalee <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/02 11:34:32 by sazalee           #+#    #+#              #
#    Updated: 2020/03/03 20:17:14 by sazalee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -O2

LIBFT = libft

DIR_S = srcs

DIR_O = objectives

HEADER = includes

C = clang

SOURCES = ft_printf.c handle.c handlehelp.c handlehelpfive.c handlehelpfour.c handlehelpone.c \
	handlehelpthree.c handlehelptwo.c handleone.c parseall.c parsehelp.c support.c handlehelpsix.c \
	handlehelpseven.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
		@make -C $(LIBFT)
		@cp libft/libft.a ./$(NAME)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
		@mkdir -p objectives
		@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
		@rm -f $(OBJS)
		@rm -rf $(DIR_O)
		@make clean -C $(LIBFT)

fclean: clean
		@rm -f $(NAME)
		@make fclean -C $(LIBFT)

re: fclean all
