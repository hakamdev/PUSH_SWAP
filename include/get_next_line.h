/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:26:09 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/03 16:22:42 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "utility.h"

# ifndef NL
#  define NL '\n'
# endif

# ifndef CNULL
#  define CNULL '\0'
# endif

# ifndef INULL
#  define INULL 0
# endif

# ifndef ERR
#  define ERR -1
# endif

# ifndef MAXFD
#  define MAXFD 4864
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int		get_next_line(int fd, char **line);
void	ft_free(char **s);

#endif
