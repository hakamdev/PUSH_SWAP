/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 18:22:59 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/06 21:33:43 by ehakam           ###   ########.fr       */
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
	int		val1;
	int		val2;
	int		median;
	t_list	*lst;

	i = -1;
	lst = new_list_from(a);
	median = lst->data[lst->size / 2];
	while (++i < a->size)
		if (a->data[i] < median)
			val1 = a->data[i];
	while (++i < a->size)
		if (a->data[i] < median)
			val1 = a->data[i];
	
	
	return (final_str);
}

char	*push_swap(t_stack *a, t_stack *b)
{
	if (a->size == 3)
		return (ps_handle_3(a, b));
	return (NULL);
}

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
	final_instr = NULL;
	final_instr = push_swap(a, b);
	dprintf(2, "%s", final_instr);
	printf("%s", final_instr);
	return (0);
}