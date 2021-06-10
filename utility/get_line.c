/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:22:33 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/10 15:46:54 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_line.h"

int	get_line(char **line)
{
	char	*buffer;
	int		read_;

	if (!line)
		return (-1);
	buffer = (char *)malloc(sizeof(char) * 2);
	if (!buffer)
		return (-1);
	*line = ft_strdup("");
	if (!*line)
		return (-1);
	while (1)
	{
		read_ = read(0, buffer, 1);
		if (read_ <= 0 || buffer[0] == '\n')
			break ;
		buffer[read_] = '\0';
		*line = ft_strjoin(*line, buffer);
	}
	if (read_ <= 0)
		return (read_);
	free(buffer);
	return (1);
}
