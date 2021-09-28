/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:05:13 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/01 16:05:16 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * i + 1);
	if (!copy)
		return (0);
	copy[i] = '\0';
	while (i >= 0)
	{
		copy[i] = s1[i];
		i--;
	}
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		n;

	if (!s1)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	n = 0;
	while (s2[n])
	{
		ret[i] = s2[n];
		n++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*s2;

	if (n == 0)
		return ;
	i = 0;
	s2 = (char *)s;
	while (i != (int)n)
	{
		s2[i] = '\0';
		i++;
	}
}
