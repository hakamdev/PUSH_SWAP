/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:45:46 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/10 16:13:41 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

/*
** UTIL FUNCTIONS FOR STACK/LIST
*/
static void	put_value_sorted(int *data, int size, int value)
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
		p_error();
	lst->data = malloc(sizeof(int) * (stack->size + 1));
	if (!lst->data)
		p_error();
	i = -1;
	lst->size = 0;
	while (++i < stack->size)
		put_value_sorted(lst->data, lst->size++, stack->data[i]);
	return (lst);
}

int	ft_atoi_err(char *str)
{
	int		i;
	int		n;
	long	r;

	i = 0;
	r = 0;
	n = 1;
	if (!str)
		p_error();
	while (str[i] > 0 && str[i] < 33 && str[i] != 27)
		i++;
	if (str[i] == 27)
		p_error();
	if (str[i] == '-' && ++i)
		n = -1;
	else if (str[i] == '+')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
		r = r * 10 + (str[i++] - '0');
	while (str[i] > 0 && str[i] < 33 && str[i] != 27)
		i++;
	if (str[i] != '\0')
		p_error();
	return (r * n);
}

void	free_stack(t_stack *s)
{
	if (!s)
		return ;
	if (s->data)
		free(s->data);
	free(s);
}

void	free_list(t_list *l)
{
	if (!l)
		return ;
	if (l->data)
		free(l->data);
	free(l);
}
