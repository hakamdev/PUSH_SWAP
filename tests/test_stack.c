/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 21:21:29 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/05 18:11:17 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int		main(void)
{
	/* Test Basic Functions */
	t_stack *s = new_stack();
	//t_stack *s2 = new_stack();

	push(s, 1);
	push(s, 1000);
	push(s, 453);
	push(s, 4530);
	push(s, 2);
	push(s, 20);
	push(s, 67);
	push(s, 670);
	push(s, 3);
	push(s, 9);
	push(s, 90);
	push(s, 100000);
	
	// for (int i = 0; i < 200; i++)
	// 	if (i % 35 == 0)
	// 		s->push(s, i);

	display(s, true);

	display_list(new_list_from(s));
	// display(s2, true);

	// printf ("POPED:\t\t%d\n", s->pop(s));
	// printf ("POPED:\t\t%d\n", s->pop(s2));
	// printf ("POPED:\t\t%d\n", s->pop(s));
	// printf ("POPED:\t\t%d\n", s->pop(s2));
	// printf ("POPED:\t\t%d\n", s->pop(s));
	// printf ("POPED:\t\t%d\n", s->pop(s2));
	// printf ("POPED:\t\t%d\n", s->pop(s));
	// printf ("POPED:\t\t%d\n", s->pop(s));
	// printf ("POPED:\t\t%d\n", s->pop(s));

	// printf ("\nPEEKED:\t\t%d\n\n", s->peek(s));
	// printf ("\nPEEKED:\t\t%d\n\n", s->peek(s));
	// printf ("\nPEEKED:\t\t%d\n\n", s->peek(s));

	// display(s);
	// display(s2);
	
	return (0);
}