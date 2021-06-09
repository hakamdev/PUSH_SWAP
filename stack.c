/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:14:28 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/09 15:58:45 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"

/*
** FUNCTIONS FOR INITIALIZING A STACK
*/
t_stack *new_stack(char label)
{
	return (new_stack_s(5, label));
}

t_stack *new_stack_s(int limit, char label)
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
	new->label = label;
	new->peek = peek;
	new->pop = pop;
	new->push = push;
	new->is_sorted = is_sorted;
	return (new);
}

t_stack	*new_stack_from(t_stack *other, char label)
{
	int			i;
	t_stack		*new;

	if (!other)
		return (NULL);
	if (other->is_empty)
		return (new_stack_s(other->limit, label));
	i = -1;
	new = new_stack_s(other->limit, label);
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

t_bool	contains(t_stack *this, int value)
{
	int		i;

	i = -1;
	if (!this || this->is_empty)
		return (false);
	while (++i < this->size)
		if (this->data[i] == value)
			return (true);
	return (false);
}

t_stack	*new_stack_arg(int ac, char **av, char label)
{
	int		i;
	int		value;
	t_stack	*new;

	i = ac;
	if (!av || ac < 2)
		return (NULL);
	new = new_stack_s(ac, label);
	while (--i > 0)
	{
		value = ft_atoi_err(av[i]);
		if (contains(new, value))
			p_error("Duplicate Values!");
		new->push(new, value);
	}
	return (new);
}

void	put_value_sorted(int *data, int size, int value)
{
	int		i;

	i = size;
	data[i] = value;
	while (i > 0)
	{
		if (data[i] < data[i - 1])
		{
			data[i] = data[i - 1];
			data[i - 1] = value;
		}
		else
			break ;
		--i;
	}
}

t_list	*new_list_from(t_stack *stack)
{
	int		i;
	t_list	*lst;

	if (!stack || stack->is_empty)
		return (NULL);
	lst = malloc(sizeof(t_list));
	if (!lst)
		p_error(E_MALLOC);
	lst->data = malloc(sizeof(int) * (stack->size + 1));
	if (!lst->data)
		p_error(E_MALLOC);
	i = -1;
	lst->size = 0;
	while (++i < stack->size)
		put_value_sorted(lst->data, lst->size++, stack->data[i]);
	return (lst);
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
	if (this->size == 0)
		p_error(E_UNDERFLOW);
	return (this->data[this->top]);
}

t_bool	is_sorted(t_stack *this)
{
	int		i;

	if (!this || this->is_empty)
		return (false);
	if (this->size == 1)
		return (true);
	i = this->size;
	while (--i > 0)
	{
		if (this->data[i] > this->data[i - 1])
			return (false);
	}
	return (true);
}

/*
** TESTING
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
		// printf("TOP VAL:\t%d\n\n", stack->peek(stack));
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


