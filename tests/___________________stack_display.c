/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:51:39 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/09 20:52:51 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"

/*
** DISPLAY FUNCTIONS
*/
void	display(t_stack *stack, t_bool meta)
{
	int		i;

	if (meta)
	{
		printf("SIZE:\t\t%d\n", stack->size);
		printf("LIMIT:\t\t%d\n", stack->limit);
		printf("TOP:\t\t%d\n", stack->top);
		printf("TAIL:\t\t%d\n", stack->tail);
		printf("EMPTY:\t\t%s\n", stack->is_empty ? "TRUE" : "FALSE");
		printf("SORTED?:\t%s\n\n", stack->is_sorted(stack) ? "TRUE" : "FALSE");
	}
	i = stack->top;
	printf("[");
	while (i > -1)
	{
		printf(" %d%s", stack->data[i], i > 0 ? "," : "");
		--i;
	}
	printf("]\n\n");
}

void	display_list(t_list *list)
{
	int		i;

	i = -1;
	printf("[");
	while (++i < list->size)
	{
		printf(" %d%s", list->data[i], i < list->size-1 ? "," : "");
	}
	printf("]\n\n");
}
