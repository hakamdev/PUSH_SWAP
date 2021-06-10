/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:52:57 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/10 16:16:13 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "types.h"
# include "utility.h"

typedef struct s_stack
{
	int		*data;
	int		size;
	int		limit;
	int		top;
	int		tail;
	char	label;
	void	(*push)(struct s_stack *this, int value);
	int		(*pop)(struct s_stack *this);
	int		(*peek)(struct s_stack *this);
	t_bool	(*is_sorted)(struct s_stack *this);
	t_bool	is_empty;
}				t_stack;

typedef struct s_list
{
	int		*data;
	int		size;
}				t_list;

/*
** FUNCTIONS FOR INITIALIZING A STACK
*/
t_stack	*new_stack_s(int limit, char label);
t_stack	*new_stack_arg(int ac, char **av, char label);
t_list	*new_list_from(t_stack *stack);
int		ft_atoi_err(char *str);

/*
** DESTRUCTORS
*/
void	free_stack(t_stack *s);
void	free_list(t_list *s);

/*
** BASIC OPERATIONS ON A STACK
*/
void	push(t_stack *this, int value);
int		pop(t_stack *this);
int		peek(t_stack *this);
t_bool	is_sorted(t_stack *this);

/*
** ADVANCED OPERATIONS ON A STACK
*/
void	s(t_stack *stack, t_bool print);
void	ss(t_stack *a, t_stack *b, t_bool print);
void	p(t_stack *src, t_stack *dest, t_bool print);
void	r(t_stack *stack, t_bool reverse, t_bool print);
void	rr(t_stack *a, t_stack *b, t_bool reverse, t_bool print);

/*
** CHECKER FUNCTIONS
*/
t_bool	apply(t_stack *a, t_stack *b, char *instr);
t_bool	is_valid(char *instr);

/*
** PUSH SWAP FUNCTIONS
*/
void	move_to_top(t_stack *s, int index);
void	handle_chunk(t_stack *a, t_stack *b, int from, int to);
void	chunk_stack(t_stack *a, t_stack *b, int chunks);
void	ps_handle_3(t_stack *a);
int		ps_handle_5(t_stack *a, t_stack *b);
int		ps_handle_all(t_stack *a, t_stack *b, int chunks);
t_bool	ps_handle_sorted(t_stack *a, t_stack *b);
int		get_index_less(t_stack *stack, int median);
int		get_index_of(t_stack *stack, int value);

#endif