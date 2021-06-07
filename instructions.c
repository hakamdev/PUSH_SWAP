/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:18:54 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/07 19:24:50 by ehakam           ###   ########.fr       */
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
	value = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top - 1];
	stack->data[stack->top - 1] = value;
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

t_bool	is_valid(char *instr)
{
	int		i;

	const char	instrs[][11] =
	{"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr", ""};
	i = -1;
	while (++i < 12)
		if (strcmp(instr, instrs[i]) == 0)
			return (true);
	return (false);
}

t_bool	apply(t_stack *a, t_stack *b, char *instr)
{
	if (!is_valid(instr))
		return (false);
	if (strcmp(instr, "sa") == 0)
		s(a);
	else if (strcmp(instr, "sb") == 0)
		s(b);
	else if (strcmp(instr, "ss") == 0)
		ss(a, b);
	else if (strcmp(instr, "pa") == 0)
		p(b, a);
	else if (strcmp(instr, "pb") == 0)
		p(a, b);
	else if (strcmp(instr, "ra") == 0)
		r(a, false);
	else if (strcmp(instr, "rb") == 0)
		r(b, false);
	else if (strcmp(instr, "rr") == 0)
		rr(a, b, false);
	else if (strcmp(instr, "rra") == 0)
		r(a, true);
	else if (strcmp(instr, "rrb") == 0)
		r(b, true);
	else if (strcmp(instr, "rrr") == 0)
		rr(a, b, true);
	return (true);
}

