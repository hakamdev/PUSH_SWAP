/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:55:28 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/09 20:55:57 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"

void	move_to_top(t_stack *s, int index)
{
	int		moves;

	if (s->top - index < index + 1)
	{
		moves = s->top - index + 1;
		while (--moves > 0)
			r(s, false, true);
	}
	else
	{
		moves = index + 2;
		while (--moves > 0)
			r(s, true, true);
	}
}

void	handle_chunk(t_stack *a, t_stack *b, int from, int to)
{
	int			i;
	int			moves;
	int			num;
	t_list		*lst;

	num = to - from;
	lst = new_list_from(a);
	while (num-- >= 0)
	{
		i = -1;
		while (++i < a->size)
		{
			if (a->data[i] >= lst->data[from] && a->data[i] <= lst->data[to])
				break;
			if (a->data[a->top - i] >= lst->data[from]
				&& a->data[a->top - i] <= lst->data[to])
			{
				i = a->top - i;
				break;
			}
		}
		move_to_top(a, i);
		p(a, b, true);
	}
	free_list(lst);
}

void	chunk_stack(t_stack *a, t_stack *b, int chunks)
{
	int	loops;
	int chunk_size = a->size / chunks;
		
	loops = -1;
	while (++loops < chunks)
		handle_chunk(a, b, 0, chunk_size - 1);
	if (a->size > 0)
	{
		handle_chunk(a, b, 0, a->top);
		chunks += 1;
	}
}
