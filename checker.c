/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:56:07 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/05 18:27:59 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"
#include "include/stack.h"

int		main(int argc, char **argv)
{
	int			read;
	char		*instr;
	t_stack		*a;
	t_stack		*b;

	if (argc < 2)
		return (0);
	a = new_stack_arg(argc, argv);
	if (!a)
		return (0);
	b = new_stack_s(argc);
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