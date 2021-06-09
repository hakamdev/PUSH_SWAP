/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 18:22:59 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/09 19:15:16 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"

int		ps_handle_3(t_stack *a, t_stack *b)
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
	return (0);
}

int		ps_handle_5(t_stack *a, t_stack *b)
{
	int		i;
	int		moves;
	int		median;
	t_list	*lst;

	if (a->is_sorted(a))
		return (printf(""));
	lst = new_list_from(a);
	median = lst->data[(lst->size - 1) / 2];
	while (a->size > 3)
	{
		i = a->top + 1;
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

		if (a->top - i < i + 1)
		{
			moves = a->top - i + 1;
			while (--moves > 0)
				r(a, false, true);
		}
		else
		{
			moves = i + 2;
			while (--moves > 0)
				r(a, true, true);
		}
		p(a, b, true);
	}
	if (b->data[b->top] < b->data[b->top - 1])
		s(b, true);
	ps_handle_3(a, b);
	p(b, a, true);
	p(b, a, true);
	return (0);
}

char	*handle_chunk(t_stack *a, t_stack *b, int from, int to)
{
	int		i;
	int		moves;
	int num = to - from;

	t_list *lst = new_list_from(a);
	while (num-- >= 0)
	{
		i = -1;
		while (++i < a->size)
		{
			if (a->data[i] >= lst->data[from] && a->data[i] <= lst->data[to])
			{
				break;
			}
			if (a->data[a->top - i] >= lst->data[from] && a->data[a->top - i] <= lst->data[to])
			{
				i = a->top - i;
				break;
			}
		}
		if (a->top - i < i + 1)
		{
			moves = a->top - i + 1;
			while (--moves > 0)
				r(a, false, true);
		}
		else
		{
			moves = i + 2;
			while (--moves > 0)
				r(a, true, true);
		}
		p(a, b, true);
	}
	free(lst);
	return (NULL);
}

int		chunk_stack(t_stack *a, t_stack *b, int chunks)
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
	return (chunks);
}

char	*ps_handle_all(t_stack *a, t_stack *b, int chunks)
{
	int		i;
	int		j;
	int		moves;
	t_list *lst = new_list_from(a);

	chunks = chunk_stack(a, b, chunks);
	i = lst->size;
	while (--i >= 0)
	{
		j = -1;
		while (++j < b->size)
		{
			if (b->data[j] == lst->data[i])
				break;
			if (b->data[b->top - j] == lst->data[i])
			{
				j = b->top - j;
				break;
			}
		}

		if (b->top - j < j + 1)
		{
			moves = b->top - j + 1;
			while (--moves > 0)
				r(b, false, true);
		}
		else
		{
			moves = j + 2;
			while (--moves > 0)
				r(b, true, true);
		}
		p(b, a, true);
	}
	return (NULL);
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	if (argc < 2)
		return (0);
	a = new_stack_arg(argc, argv, 'a');
	if (!a)
		return (0);
	b = new_stack_s(argc, 'b');
	if (a->size <= 3)
		ps_handle_3(a, b);
	else if (a->size <= 5)
		ps_handle_5(a, b);
	else if (a->size <= 100)
		ps_handle_all(a, b, 6);
	else
		ps_handle_all(a, b, 15);
	return (0);
}

// funcion (line) {
// 	temp
// 	while (read(temp))
// 	{
// 		temp();
// 		join line temp;
// 		work();
// 	}
// 	if (!line empty isatty()) {
// 		funtion(line);
// 	}
// 	exit();
// }