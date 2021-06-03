# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 18:20:02 by ehakam            #+#    #+#              #
#    Updated: 2021/06/03 18:27:55 by ehakam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_STK =	stack.c \
			instructions.c \
			utility/utility.c \
			tests/test_stack.c
SRC_CHKR=	stack.c \
			checker.c \
			instructions.c \
			utility/utility.c \
			utility/get_next_line.c \

all: test_stack

test_stack: $(SRC_STK)
	@gcc $(SRC_STK) -o stk_test.exe