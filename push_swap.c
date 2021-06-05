/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 18:22:59 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/05 21:43:10 by ehakam           ###   ########.fr       */
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

int		ps_handle_3(t_stack *a, t_stack *b, char *final_instr)
{
	while (!a->is_sorted(a))
	{
		if (a->data[2] > a->data[1] && a->data[2] > a->data[0])
		{
			r(a, false);
			final_instr = add(final_instr, RA);
		}
		else if (a->data[1] > a->data[0] && a->data[1] > a->data[2])
		{
			r(a, true);
			final_instr = add(final_instr, RRA);
		}
		if (a->data[2] > a->data[1])
		{
			s(a);
			final_instr = add(final_instr, SA);
		}
	}
	return (0);
}

void	push_swap(t_stack *a, t_stack *b, char *final_instr)
{
	if (a->size == 3)
		ps_handle_3(a, b, final_instr);
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
	// push_swap(a, b, final_instr);
	ps_handle_3(a, b, final_instr);
	printf("%s", final_instr);
	return (0);
}