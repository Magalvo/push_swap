# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 17:43:19 by dde-maga          #+#    #+#              #
#    Updated: 2024/02/29 17:49:14 by dde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_UTILS = ft_split.c
SRC_COMMANDS = push.c rev_rotate.c rotate.c sort_stacks.c sort_three.c \
				swap.c


SRC =	$(addprefix ./srcs/commands/, $(SRC_COMMANDS)) \
		$(addprefix ./srcs/custom/get_next_line/, $(SRC_UTILS)) \



SRCOBJ = obj/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = $(addprefix $(SRCOBJ), $(SRC:./srcs/%.c=%.o))


all: $(NAME)

$(NAME): $(OBJ)
	@${CC} ${CFLAGS} -g3 main.c ${OBJ} -o $(NAME)

$(SRCOBJ)%.o: srcs/%.c
	@mkdir -p $(SRCOBJ)
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -rf $(SRCOBJ)


fclean: clean
	@rm -rf $(NAME)

re: fclean all
