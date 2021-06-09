# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 18:20:02 by ehakam            #+#    #+#              #
#    Updated: 2021/06/09 21:25:29 by ehakam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_CKR	=	checker.c \
			stack_core.c \
			stack_init.c \
			instructions.c \
			stack_display.c \
			utility/utility.c \
			stack_init_utils.c \
			utility/get_next_line.c

SRC_PS	=	push_swap.c \
			stack_core.c \
			stack_init.c \
			instructions.c \
			stack_display.c \
			push_swap_utils.c \
			utility/utility.c \
			stack_init_utils.c \

NAME	=	push_swap
NAME_BNS=	checker

all: $(NAME) $(NAME_BNS)

$(NAME): $(SRC_PS)
	@gcc $(SRC_PS) -o $(NAME)

$(NAME_BNS): $(SRC_CKR)
	@gcc $(SRC_CKR) -o $(NAME_BNS)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME) $(NAME_BNS)

re: fclean all
