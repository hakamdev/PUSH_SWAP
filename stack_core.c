/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:14:28 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/09 21:30:09 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"

/*
** CORE OPERATIONS ON A STACK
*/
static t_stack	*extend(t_stack *stack)
{
	int		i;
	int		*new_data;
	int		new_limit;

	if (!stack)
		return (NULL);
	new_limit = stack->limit + stack->limit / 2;
	new_data = (int *)malloc(sizeof(int) * new_limit);
	if (!new_data)
		return (NULL);
	i = -1;
	while (++i < stack->size)
		new_data[i] = stack->data[i];
	free(stack->data);
	stack->data = new_data;
	stack->limit = new_limit;
	return (stack);
}

void	push(t_stack *this, int value)
{
	if (!this || !this->data)
		return ;
	if (this->size >= this->limit - 1)
		this = extend(this);
	this->data[++(this->top)] = value;
	this->size++;
	this->is_empty = false;
}

int	pop(t_stack *this)
{
	int		value;

	if (this->size == 0)
		p_error(E_UNDERFLOW);
	value = this->data[this->top--];
	this->size--;
	if (this->size == 0)
		this->is_empty = true;
	return (value);
}

int	peek(t_stack *this)
{
	if (this->size == 0)
		p_error(E_UNDERFLOW);
	return (this->data[this->top]);
}

t_bool	is_sorted(t_stack *this)
{
	int		i;

	if (!this || this->is_empty)
		return (false);
	if (this->size == 1)
		return (true);
	i = this->size;
	while (--i > 0)
	{
		if (this->data[i] > this->data[i - 1])
			return (false);
	}
	return (true);
}
