/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:26:09 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/09 21:07:00 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "utility.h"

#  define NL '\n'
#  define CNULL '\0'
#  define INULL 0
#  define ERR -1
#  define MAXFD 4864
#  define BUFFER_SIZE 5

int		get_next_line(int fd, char **line);

#endif
