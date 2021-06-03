/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:20:44 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/03 19:00:36 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

# include <stdlib.h>
# include <unistd.h>

#define E_UNDERFLOW "Stack Underflow, caused by POP Operation on an Empty Stack!"
#define E_INVALID_TYPE "Invalid Data Type, caused by Non-Numeric value!"
#define E_MALLOC "Memory allocation failed, caused by malloc failure!"

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strsub(char **s, unsigned int start, size_t n);
int		ft_atoi_err(char *str);
int		p_error(char *message);


#endif