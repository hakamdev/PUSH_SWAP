/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:35:01 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/10 15:45:11 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utility.h"

int	p_error()
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ss;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	if (!s1 && s2)
	{
		ss = ft_strdup(s2);
		return (ss);
	}
	i = -1;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ss = malloc(len1 + len2 + 1);
	if (!ss)
		return (NULL);
	while (++i < len1)
		ss[i] = s1[i];
	while (j < len2)
		ss[i++] = s2[j++];
	ss[i] = '\0';
	free(s1);
	return (ss);
}

char	*ft_strdup(const char *s)
{
	char	*ss;
	size_t	lens;
	size_t	i;

	i = -1;
	lens = ft_strlen(s);
	ss = (char *)malloc(lens + 1);
	if (!ss)
		return (NULL);
	while (++i < lens)
		ss[i] = s[i];
	ss[i] = '\0';
	return (ss);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}
