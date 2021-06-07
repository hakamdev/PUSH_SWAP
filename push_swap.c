/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 18:22:59 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/07 19:59:06 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"

char	*add(char *str_instrs, int instr)
{
	const char	instrs[][11] =
		{"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	str_instrs = ft_strjoin(str_instrs, (char *)instrs[instr]);
	str_instrs = ft_strjoin(str_instrs, "\n");
	return (str_instrs);
}

char	*ps_handle_3(t_stack *a, t_stack *b, char *final_str)
{
	while (!a->is_sorted(a))
	{
		if (a->data[2] > a->data[1] && a->data[2] > a->data[0])
		{
			r(a, false);
			final_str = add(final_str, RA);
		}
		else if (a->data[1] > a->data[0] && a->data[1] > a->data[2])
		{
			r(a, true);
			final_str = add(final_str, RRA);
		}
		if (a->data[2] > a->data[1])
		{
			s(a);
			final_str = add(final_str, SA);
		}
	}
	if (!final_str)
		return (strdup(""));
	return (final_str);
}

char	*ps_handle_5(t_stack *a, t_stack *b, char *final_str)
{
	int		i;
	int		moves;
	int		median;
	t_list	*lst;

	if (a->is_sorted(a))
		return (ft_strjoin(final_str, ""));
	lst = new_list_from(a);
	median = lst->data[(lst->size - 1) / 2];
	while (a->size > 3)
	{
		i = a->top + 1;
		while (--i > 0)
		{
			if (a->data[i] < median)
				break;
		}
		if (a->top - i < i + 1)
		{
			moves = a->top - i + 1;
			while (--moves > 0)
			{
				r(a, false);
				final_str = add(final_str, RA);
			}
		}
		else
		{
			moves = i + 2;
			while (--moves > 0)
			{
				r(a, true);
				final_str = add(final_str, RRA);
			}
		}
		p(a, b);
		final_str = add(final_str, PB);
	}
	if (b->data[b->top] < b->data[b->top - 1])
	{
		s(b);
		final_str = add(final_str, SB);
	}
	final_str = ps_handle_3(a, b, final_str);
	p(b, a);
	p(b, a);
	final_str = add(final_str, PA);
	final_str = add(final_str, PA);
	return (final_str);
}

// char	*push_swap(t_stack *a, t_stack *b)
// {
// 	if (a->size == 3)
// 		return (ps_handle_3(a, b));
// 	return (NULL);
// }

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		*final_instr;

	if (argc < 2)
		return (0);
	a = new_stack_arg(argc, argv);
	if (!a)
		return (0);
	b = new_stack_s(argc);
	final_instr = NULL;
	final_instr = ps_handle_5(a, b, final_instr);
	dprintf(2, "%s", final_instr);
	printf("%s", final_instr);
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