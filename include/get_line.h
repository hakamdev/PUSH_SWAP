/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:26:09 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/11 17:21:56 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_LINE_H
# define GET_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "utility.h"

int		get_line(char **line);
void	put_line(char *instr, char label);

#endif
