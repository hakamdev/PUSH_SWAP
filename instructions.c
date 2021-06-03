/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:18:54 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/03 18:19:14 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"

/*
** ADVANCED OPERATIONS ON A STACK
*/
void	s(t_stack *stack)
{
	int		value;

	if (!stack || stack->size < 2)
		return ;
	value = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = value;
}

void	ss(t_stack *a, t_stack *b)
{
	s(a);
	s(b);
}

void	p(t_stack *src, t_stack *dest)
{
	int		value;

	if (!src || !dest || src->is_empty)
		return ;
	value = src->pop(src);
	dest->push(dest, value);
}

void	r(t_stack *stack, t_bool reverse)
{
	int		i;
	int		value;
	
	if (!stack || stack->size < 2)
		return ;
	if (!reverse)
	{
		value = stack->data[stack->top];
		i = stack->top;
		while (i > 0)
		{
			stack->data[i] = stack->data[i - 1];
			--i;
		}
		stack->data[0] = value;
	}
	else
	{
		value = stack->data[0];
		i = -1;
		while (++i < stack->top)
			stack->data[i] = stack->data[i + 1];
		stack->data[stack->top] = value;
	}
}

void	rr(t_stack *a, t_stack *b, t_bool reverse)
{
	r(a, reverse);
	r(b, reverse);
}

