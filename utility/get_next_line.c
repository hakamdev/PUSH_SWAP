/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:22:33 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/03 16:17:47 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

static int	ft_find_index(const char *s, char c)
{
	int		i;

	if (s)
	{
		i = 0;
		while ((char)s[i])
		{
			if ((char)s[i] == c)
				return (i);
			i++;
		}
	}
	return (ERR);
}

static int	ft_handle_nl(char **line, char **temp, char **rest)
{
	int		nl_index;
	char	*addup;

	nl_index = ft_find_index(*temp, NL);
	if (nl_index != ERR)
	{
		if (!(addup = ft_strsub(temp, 0, nl_index)))
			return (ERR);
		if (!(*line = ft_strjoin(*line, addup)))
			return (ERR);
		if (!(*rest = ft_strdup(&temp[0][nl_index + 1])))
			return (ERR);
		ft_free(&addup);
		ft_free(temp);
		return (1);
	}
	return (INULL);
}

static int	ft_handle_rest(char **line, char **temp, char **rest)
{
	int		ret;

	if (*rest)
	{
		if (ft_find_index(*rest, NL) > ERR)
		{
			ft_free(temp);
			*temp = *rest;
			if ((ret = ft_handle_nl(line, temp, rest)) != INULL)
				return (ret);
		}
		else
		{
			if (!(*line = ft_strjoin(*line, *rest)))
				return (ERR);
			ft_free(rest);
		}
	}
	return (INULL);
}

int			get_next_line(int fd, char **line)
{
	static char	*rest[MAXFD];
	char		*temp;
	int			sread;
	int			ret;

	if (!line || !(temp = malloc(BUFFER_SIZE + 1)))
		return (ERR);
	sread = 0;
	if (!(*line = ft_strdup("")))
		return (ERR);
	if ((ret = ft_handle_rest(line, &temp, &rest[fd])) != INULL)
		return (ret);
	while ((sread = read(fd, temp, BUFFER_SIZE)) > INULL)
	{
		temp[sread] = CNULL;
		if (ft_find_index(temp, NL) > ERR)
			if ((ret = ft_handle_nl(line, &temp, &rest[fd])) != INULL)
				return (ret);
		if (!(*line = ft_strjoin(*line, temp)))
			return (ERR);
	}
	if (!sread)
		ft_free(&temp);
	if (sread > 0)
		return (1);
	return (sread);
}
