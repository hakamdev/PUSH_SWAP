/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:35:01 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/03 18:27:20 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utility.h"

int		p_error(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n\n", 2);
	exit(1);
}

void	ft_free(char **s)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
}

char	*ft_strsub(char **s, unsigned int start, size_t n)
{
	char			*ss;
	unsigned int	lens;
	unsigned int	i;

	i = 0;
	if (*s == NULL)
		return (NULL);
	lens = ft_strlen(*s);
	if (start > lens)
		n = 0;
	if (!(ss = (char *)malloc(n + 1)))
		return (NULL);
	while (i < n && start < lens)
		*(ss + i++) = *(*s + start++);
	*(ss + i) = '\0';
	return (ss);
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
	if (!(ss = malloc(len1 + len2 + 1)))
		return (NULL);
	while (++i < len1)
		*(ss + i) = *((char *)(s1 + i));
	while (j < len2)
		*(ss + i++) = *((char *)(s2 + j++));
	*(ss + i) = '\0';
	ft_free(&s1);
	return (ss);
}

char	*ft_strdup(const char *s)
{
	char	*ss;
	size_t	lens;
	size_t	i;

	i = 0;
	lens = ft_strlen(s);
	if (!(ss = (char *)malloc(lens + 1)))
		return (NULL);
	while (i < lens)
	{
		ss[i] = s[i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}






