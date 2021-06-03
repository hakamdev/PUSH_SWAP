/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:56:07 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/03 20:24:16 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"
#include "include/stack.h"

t_bool	is_valid_intruction(char *instr)
{
	int		i;

	const char	**instrs =
		{"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	i = -1;
	while (++i < 11)
		if (strcmp(instr, instrs[i]) == 0)
			return (true);
	return (false);
}

int		main(int argc, char **argv)
{
	int			read;
	char		*line;
	t_stack		*a;
	t_stack		*b;

	a = new_stack_arg(argc, argv);
	if (!a)
		p_error("No Args!");
	if (a->is_sorted(a))
	{
		printf("OK\n");
		return (0);
	}
	b = new_stack_s(argc / 2);
	while (true)
	{
		read = get_next_line(0, &line);
		if (read < 1)
			break ;
		if (is_valid_intruction(line));
		/////////
	}
	// Process;
	return (0);
}