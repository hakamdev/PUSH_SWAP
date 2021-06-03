/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:52:57 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/03 19:58:59 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"
#include "utility.h"



typedef struct s_stack
{
	int		*data;
	int		size;
	int		limit;
	int		top;
	int		tail;
	void	(*push)(struct s_stack *this, int value);
	int		(*pop)(struct s_stack *this);
	int		(*peek)(struct s_stack *this);
	t_bool	(*is_sorted)(struct s_stack *this);
	t_bool	is_empty;
} t_stack;

/*
** FUNCTIONS FOR INITIALIZING A STACK
*/
t_stack *new_stack();
t_stack *new_stack_s(int limit);
t_stack	*new_stack_arg(int ac, char **av);
t_stack	*new_stack_from(t_stack *other);

/*
** BASIC OPERATIONS ON A STACK
*/
void	push(t_stack *this, int value);
int		pop(t_stack *this);
int		peek(t_stack *this);
t_bool	is_sorted(t_stack *this);

/*
** TESTING
*/
void	display(t_stack *stack, t_bool meta);

/*
** ADVANCED OPERATIONS ON A STACK
*/
void	s(t_stack *stack);
void	ss(t_stack *a, t_stack *b);
void	p(t_stack *src, t_stack *dest);
void	r(t_stack *stack, t_bool reverse);
void	rr(t_stack *a, t_stack *b, t_bool reverse);

#endif