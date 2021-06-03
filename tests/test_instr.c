/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:39:29 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/03 19:49:48 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int main(int ac, char **av) {
	t_stack *a = new_stack_arg(ac, av);
	t_stack *b = new_stack();

	if (!a)
		p_error("Args Motherfucker!");
	
	printf("INIT\n");
	display(a, false);
	display(b, false);

	s(a);
	printf("SA:\n");
	display(a, false);
	display(b, false);
	
	p(a, b); p(a, b); p(a, b);
	printf("PB PB PB:\n");
	display(a, false);
	display(b, false);
	
	rr(a, b, false);
	printf("RR:\n");
	display(a, false);
	display(b, false);
	
	rr(a, b, true);
	printf("RRR:\n");
	display(a, false);
	display(b, false);	

	s(a);
	printf("SA:\n");
	display(a, false);
	display(b, false);

	p(b, a); p(b, a); p(b, a);
	printf("PA PA PA:\n");
	display(a, false);
	display(b, false);
	
	return (0);
}
