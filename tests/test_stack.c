/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 21:21:29 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/03 19:38:12 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int		main(void)
{
	/* Test Basic Functions */
	t_stack *s = new_stack();
	t_stack *s2 = new_stack();

	push(s, 100);
	push(s2, 1000);
	push(s, 453);
	push(s2, 4530);
	push(s, 2);
	push(s2, 20);
	push(s, 67);
	push(s2, 670);
	push(s, 3);
	push(s, 9);
	push(s2, 90);
	push(s2, 100000);
	
	// for (int i = 0; i < 200; i++)
	// 	if (i % 35 == 0)
	// 		s->push(s, i);

	display(s, true);
	display(s2, true);

	printf ("POPED:\t\t%d\n", s->pop(s));
	printf ("POPED:\t\t%d\n", s->pop(s2));
	printf ("POPED:\t\t%d\n", s->pop(s));
	printf ("POPED:\t\t%d\n", s->pop(s2));
	printf ("POPED:\t\t%d\n", s->pop(s));
	printf ("POPED:\t\t%d\n", s->pop(s2));
	printf ("POPED:\t\t%d\n", s->pop(s));
	printf ("POPED:\t\t%d\n", s->pop(s));
	printf ("POPED:\t\t%d\n", s->pop(s));

	// printf ("\nPEEKED:\t\t%d\n\n", s->peek(s));
	// printf ("\nPEEKED:\t\t%d\n\n", s->peek(s));
	// printf ("\nPEEKED:\t\t%d\n\n", s->peek(s));

	// display(s);
	// display(s2);
	
	return (0);
}