/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:56:07 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/09 21:11:24 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"
#include "include/stack.h"

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
		s(a, false);
	else if (strcmp(instr, "sb") == 0)
		s(b, false);
	else if (strcmp(instr, "ss") == 0)
		ss(a, b, false);
	else if (strcmp(instr, "pa") == 0)
		p(b, a, false);
	else if (strcmp(instr, "pb") == 0)
		p(a, b, false);
	else if (strcmp(instr, "ra") == 0)
		r(a, false, false);
	else if (strcmp(instr, "rb") == 0)
		r(b, false, false);
	else if (strcmp(instr, "rr") == 0)
		rr(a, b, false, false);
	else if (strcmp(instr, "rra") == 0)
		r(a, true, false);
	else if (strcmp(instr, "rrb") == 0)
		r(b, true, false);
	else if (strcmp(instr, "rrr") == 0)
		rr(a, b, true, false);
	return (true);
}

int		main(int argc, char **argv)
{
	int			read;
	char		*instr;
	t_stack		*a;
	t_stack		*b;

	if (argc < 2)
		return (0);
	a = new_stack_arg(argc, argv, 'a');
	if (!a)
		return (0);
	b = new_stack_s(argc, 'b');
	while (true)
	{
		read = get_next_line(0, &instr);
		if (read < 1)
			break ;
		if (!apply(a, b, instr))
			p_error("Invalid Instruction!");
		free(instr);
	}
	if (a->is_sorted(a) && b->is_empty)
		printf("OK\n");
	else
		printf("KO\n");
	return (0);
}
