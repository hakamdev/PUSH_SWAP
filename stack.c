/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:14:28 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/03 18:18:52 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"

/*
** FUNCTIONS FOR INITIALIZING A STACK
*/
t_stack *new_stack_s(int limit)
{
	int		i;
	t_stack	*new;

	if (limit < 1)
		return (NULL);
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = (int *)malloc(sizeof(int) * limit);
	if (!new->data)
	{
		free(new);
		return (NULL);
	}
	i = -1;
	new->is_empty = true;
	new->limit = limit;
	new->size = 0;
	new->top = -1;
	new->tail = 0;
	new->peek = peek;
	new->pop = pop;
	new->push = push;
	return (new);
}

t_stack *new_stack()
{
	return (new_stack_s(5));
}

t_stack	*new_stack_from(t_stack *other)
{
	int			i;
	t_stack		*new;

	if (!other)
		return (NULL);
	if (other->is_empty)
		return (new_stack_s(other->limit));
	i = -1;
	new = new_stack_s(other->limit);
	if (!new)
		return (NULL);
	while (++i < other->size)
		new->data[i] = other->data[i];
	new->top = other->top;
	new->size = other->size;
	new->tail = other->tail;
	new->is_empty = false;
	return (new);
}

static t_stack	*extend(t_stack *stack)
{
	int		i;
	int		*new_data;
	int		new_limit;

	if (!stack)
		return (NULL);
	new_limit = stack->limit + stack->limit / 2;
	new_data = (int *)malloc(sizeof(int) * new_limit);
	if (!new_data)
		return (NULL);
	i = -1;
	while (++i < stack->size)
		new_data[i] = stack->data[i];
	free(stack->data);
	stack->data = new_data;
	stack->limit = new_limit;
	return (stack);
}

/*
** BASIC OPERATIONS ON A STACK
*/
void	push(t_stack *this, int value)
{
	if (!this || !this->data)
		return ;
	if (this->size >= this->limit - 1)
		this = extend(this);
	this->data[++(this->top)] = value;
	this->size++;
	this->is_empty = false;
}

int		pop(t_stack *this)
{
	int		value;
	
	if (this->size == 0)
		p_error(E_UNDERFLOW);
	value = this->data[this->top--];
	this->size--;
	if (this->size == 0)
		this->is_empty = true;
	return (value);
}

int		peek(t_stack *this)
{
	return (this->data[this->top]);
}

/*
** TESTING
*/
void	display(t_stack *stack)
{
	int		i;

	printf("SIZE:\t\t%d\n", stack->size);
	printf("LIMIT:\t\t%d\n", stack->limit);
	printf("TOP:\t\t%d\n", stack->top);
	printf("TAIL:\t\t%d\n", stack->tail);
	printf("EMPTY:\t\t%s\n\n", stack->is_empty ? "TRUE" : "FALSE");

	i = stack->top;
	printf("[");
	while (i > -1)
	{
		printf(" %d%s", stack->data[i], i > 0 ? "," : "");
		--i;
	}
	printf("]\n\n");
}


