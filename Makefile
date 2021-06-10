# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 18:20:02 by ehakam            #+#    #+#              #
#    Updated: 2021/06/10 15:44:26 by ehakam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_CKR	=	src/checker.c \
			src/stack_core.c \
			src/stack_init.c \
			utility/utility.c \
			utility/get_line.c \
			src/instructions.c \
			src/stack_init_utils.c

SRC_PS	=	src/push_swap.c \
			src/stack_core.c \
			src/stack_init.c \
			utility/utility.c \
			src/instructions.c \
			src/push_swap_utils.c \
			src/stack_init_utils.c

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
