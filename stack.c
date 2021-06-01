/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:14:28 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/01 20:34:55 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"

t_stack *new_stack_s(int limit)
{
	int		i;
	t_stack	*new;

	if (limit < 1)
		return (NULL);
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = (int *)malloc(sizeof(int) * limit);
	if (!new->data)
	{
		free(new);
		return (NULL);
	}
	i = -1;
	new->is_empty = true;
	new->limit = limit;
	new->size = 0;
	new->top = 0;
	new->tail = 0;
	new->peek = peek;
	new->pop = pop;
	new->push = push;
	return (new);
}

t_stack *new_stack()
{
	return (new_stack_s(10));
}

t_stack	*new_stack_from(t_stack *other)
{
	int			i;
	t_stack		*new;

	if (!other)
		return (NULL);
	if (other->is_empty)
		return (new_stack_s(other->limit));
	i = -1;
	new = new_stack_s(other->limit);
	if (!new)
		return (NULL);
	while (++i < other->size)
		new->data[i] = other->data[i];
	new->top = other->top;
	new->size = other->size;
	new->tail = other->tail;
	new->is_empty = false;
	return (new);
}







