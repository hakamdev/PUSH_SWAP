# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 18:20:02 by ehakam            #+#    #+#              #
#    Updated: 2021/06/03 21:43:53 by ehakam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_STK =	stack.c \
			instructions.c \
			utility/utility.c \
			tests/test_stack.c

SRC_STK2=	stack.c \
			instructions.c \
			utility/utility.c \
			tests/test_stack_arg.c
			

SRC_CHKR=	stack.c \
			checker.c \
			instructions.c \
			utility/utility.c \
			utility/get_next_line.c \

SRC_INST=	stack.c \
			instructions.c \
			utility/utility.c \
			tests/test_instr.c

all: test_checker

test_checker: $(SRC_CHKR)
	@gcc $(SRC_CHKR) -o checker

test_stack: $(SRC_STK)
	@gcc $(SRC_STK) -o stk_test.exe

test_stack2: $(SRC_STK2)
	@gcc $(SRC_STK2) -o stk2_test.exe

test_instr: $(SRC_INST)
	@gcc $(SRC_INST) -o intr_test.exe