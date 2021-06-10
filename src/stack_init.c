/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:43:21 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/10 16:13:34 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

/*
** FUNCTIONS FOR INITIALIZING A STACK
*/
static t_bool	contains(t_stack *this, int value)
{
	int		i;

	i = -1;
	if (!this || this->is_empty)
		return (false);
	while (++i < this->size)
		if (this->data[i] == value)
			return (true);
	return (false);
}

t_stack	*new_stack_s(int limit, char label)
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
	new->top = -1;
	new->label = label;
	new->peek = peek;
	new->pop = pop;
	new->push = push;
	new->is_sorted = is_sorted;
	return (new);
}

t_stack	*new_stack_arg(int ac, char **av, char label)
{
	int		i;
	int		value;
	t_stack	*new;

	i = ac;
	if (!av || ac < 2)
		return (NULL);
	new = new_stack_s(ac, label);
	while (--i > 0)
	{
		value = ft_atoi_err(av[i]);
		if (contains(new, value))
			p_error();
		new->push(new, value);
	}
	return (new);
}
