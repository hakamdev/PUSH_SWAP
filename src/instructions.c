/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:18:54 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/10 15:42:32 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

/*
** ADVANCED OPERATIONS ON A STACK
*/
void	s(t_stack *stack, t_bool print)
{
	int		value;

	if (!stack || stack->size < 2)
		return ;
	value = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top - 1];
	stack->data[stack->top - 1] = value;
	if (print)
		printf("s%c\n", stack->label);
}

void	ss(t_stack *a, t_stack *b, t_bool print)
{
	s(a, false);
	s(b, false);
	if (print)
		printf("ss\n");
}

void	p(t_stack *src, t_stack *dest, t_bool print)
{
	int		value;

	if (!src || !dest || src->is_empty)
		return ;
	value = src->pop(src);
	dest->push(dest, value);
	if (print)
		printf("p%c\n", dest->label);
}

void	r(t_stack *stack, t_bool reverse, t_bool print)
{
	int		i;
	int		value;

	if (!stack || stack->size < 2)
		return ;
	if (!reverse)
	{
		value = stack->data[stack->top];
		i = stack->size;
		while (--i > 0)
			stack->data[i] = stack->data[i - 1];
		stack->data[0] = value;
		if (print)
			printf("r%c\n", stack->label);
	}
	else
	{
		value = stack->data[0];
		i = -1;
		while (++i < stack->top)
			stack->data[i] = stack->data[i + 1];
		stack->data[stack->top] = value;
		if (print)
			printf("rr%c\n", stack->label);
	}
}

void	rr(t_stack *a, t_stack *b, t_bool reverse, t_bool print)
{
	r(a, reverse, false);
	r(b, reverse, false);
	if (print)
	{
		if (!reverse)
			printf("rr\n");
		else
			printf("rrr\n");
	}
}
