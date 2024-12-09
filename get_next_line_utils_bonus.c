/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:17:47 by ijoubair          #+#    #+#             */
/*   Updated: 2024/12/09 15:50:42 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*s3;
	int		i;
	int		j;
	
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(len * sizeof(char) + 1);
	if (!s3)
		return (free((char *)s1), NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		s3[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';

	free((char *)s1);
	return (s3);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	char	*p;
	size_t	i;

	arr = malloc(count * size);
	if (!arr)
		return (NULL);
	p = (char *)arr;
	i = 0;
	while (i < count * size)
	{
		p[i] = 0;
		i++;
	}
	return (arr);
}
