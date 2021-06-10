/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 18:22:59 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/10 15:42:39 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

void	ps_handle_3(t_stack *a, t_stack *b)
{
	while (!a->is_sorted(a))
	{
		if (a->data[2] > a->data[1] && a->data[2] > a->data[0])
			r(a, false, true);
		else if (a->data[1] > a->data[0] && a->data[1] > a->data[2])
			r(a, true, true);
		if (a->data[2] > a->data[1])
			s(a, true);
	}
	printf("");
}

int	ps_handle_5(t_stack *a, t_stack *b)
{
	int		i;
	int		moves;
	int		median;
	t_list	*lst;

	if (a->is_sorted(a))
		return (printf(""));
	lst = new_list_from(a);
	median = lst->data[(lst->size - 1) / 2];
	free_list(lst);
	while (a->size > 3)
	{
		i = a->size;
		while (--i > 0)
		{
			if (a->data[i] < median)
				break ;
			if (a->data[a->top - i] < median)
			{
				i = a->top - i;
				break ;
			}
		}
		move_to_top(a, i);
		p(a, b, true);
	}
	if (b->data[b->top] < b->data[b->top - 1])
		s(b, true);
	ps_handle_3(a, b);
	p(b, a, true);
	p(b, a, true);
	return (0);
}

int	ps_handle_all(t_stack *a, t_stack *b, int chunks)
{
	int		i;
	int		j;
	int		moves;
	t_list	*lst;

	lst = new_list_from(a);
	chunk_stack(a, b, chunks);
	i = lst->size;
	while (--i >= 0)
	{
		j = -1;
		while (++j < b->size)
		{
			if (b->data[j] == lst->data[i])
				break ;
			if (b->data[b->top - j] == lst->data[i])
			{
				j = b->top - j;
				break ;
			}
		}
		move_to_top(b, j);
		p(b, a, true);
	}
	free_list(lst);
	return (0);
}

int	ps_handle_sorted(t_stack *a, t_stack *b)
{
	if (a->is_sorted(a) && b->is_empty)
	{
		printf("");
		return (true);
	}
	return (false);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	if (argc < 2)
		return (0);
	a = new_stack_arg(argc, argv, 'a');
	if (!a)
		return (0);
	b = new_stack_s(argc, 'b');
	if (ps_handle_sorted(a, b))
		return (0);
	if (a->size <= 3)
		ps_handle_3(a, b);
	else if (a->size <= 5)
		ps_handle_5(a, b);
	else if (a->size <= 100)
		ps_handle_all(a, b, 6);
	else
		ps_handle_all(a, b, 15);
	free_stack(a);
	free_stack(b);
	return (0);
}
