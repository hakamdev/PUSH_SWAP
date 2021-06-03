/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:16:28 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/03 19:31:56 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int main(int ac, char **av)
{
	t_stack	*a = new_stack_arg(ac, av);
	if (a)
	{
		display(a);
	}
	else
		p_error("Provide Args!");
	return (0);
}