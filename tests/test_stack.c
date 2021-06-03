/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 21:21:29 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/03 16:43:12 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int		main(void)
{
	/* Test Basic Functions */
	t_stack *s = new_stack();

	push(s, 100);
	push(s, 453);
	push(s, 2);
	push(s, 67);
	push(s, 3);
	push(s, 9);
	
	// for (int i = 0; i < 200; i++)
	// 	if (i % 35 == 0)
	// 		s->push(s, i);

	display(s);

	printf ("\n\nPOPED:\t\t%d\n\n", s->pop(s));
	printf ("\n\nPOPED:\t\t%d\n\n", s->pop(s));
	printf ("\n\nPOPED:\t\t%d\n\n", s->pop(s));
	printf ("\n\nPOPED:\t\t%d\n\n", s->pop(s));
	printf ("\n\nPOPED:\t\t%d\n\n", s->pop(s));
	printf ("\n\nPOPED:\t\t%d\n\n", s->pop(s));
	printf ("\n\nPOPED:\t\t%d\n\n", s->pop(s));

	// printf ("\nPEEKED:\t\t%d\n\n", s->peek(s));
	// printf ("\nPEEKED:\t\t%d\n\n", s->peek(s));
	// printf ("\nPEEKED:\t\t%d\n\n", s->peek(s));

	display(s);
	
	return (0);
}