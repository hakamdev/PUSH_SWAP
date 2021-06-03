/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:00:50 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/03 19:03:41 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int main(int ac, char **av)
{
	if (ac > 1) {
		int vl = ft_atoi_err(av[1]);
		printf("OUTPUT: |%s| = atoi => |%d|\n", av[1], vl);
	} else
		p_error("Provide One Arg!");
	return (0);
}