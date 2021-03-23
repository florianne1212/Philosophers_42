/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:11:13 by fcoudert          #+#    #+#             */
/*   Updated: 2021/03/09 19:01:52 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo_two.h"
#include <string.h>

int			calc_size(char const *s1, char const *s2,
char const *s3, char const *s4)
{
	size_t	ss1;
	size_t	ss2;
	size_t	ss3;
	size_t	ss4;
	size_t	total;

	ss1 = ft_strlen((char *)s1);
	ss2 = ft_strlen((char *)s2);
	ss3 = ft_strlen((char *)s3);
	ss4 = ft_strlen((char *)s4);
	total = ss1 + ss2 + ss3 + ss4;
	return (total);
}

char		*finish_join(char *s, char const *s3,
char const *s4, int i)
{
	int		j;
	int		size;

	j = 0;
	size = ft_strlen((char *)s3);
	while (j < (size))
		s[i++] = s3[j++];
	j = 0;
	size = ft_strlen((char *)s4);
	while (j < (size))
		s[i++] = s4[j++];
	s[i] = '\0';
	return (s);
}

char		*ft_strjoin(char const *s1, char const *s2,
char const *s3, char const *s4)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*s;

	size = calc_size(s1, s2, s3, s4);
	if (s1)
	{
		i = 0;
		j = 0;
		if (!(s = malloc(sizeof(char) * (size + 1))))
			return (0);
		size = ft_strlen((char *)s1);
		while (i < (size))
		{
			s[i] = s1[i];
			i++;
		}
		size = ft_strlen((char *)s2);
		while (j < (size))
			s[i++] = s2[j++];
		s = finish_join(s, s3, s4, i);
		return (s);
	}
	return (NULL);
}
