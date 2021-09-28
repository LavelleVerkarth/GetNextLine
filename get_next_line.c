/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:30:44 by lverkart          #+#    #+#             */
/*   Updated: 2021/04/29 17:30:47 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	const char	*s2;
	size_t		i;

	s2 = src;
	if (!src)
		return ;
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < dstsize)
	{
		dst[i] = '\0';
		i++;
	}
}

static int	gnl_process_work_2(char *buf, char **line, char **n)
{
	int		i;

	i = 0;
	if (buf)
	{
		*n = ft_strchr(buf, '\n');
		if (*n)
		{
			*n[0] = '\0';
			*line = ft_strdup(buf);
			ft_strlcpy(buf, *n + 1, BUFFER_SIZE);
		}
		else
		{
			*line = ft_strdup(buf);
			ft_bzero(buf, BUFFER_SIZE);
		}
		if (!(*line))
			return (0);
	}
	return (1);
}

static int	gnl_process_work(char *buf, char **n, char **line)
{
	char	*tmp;

	if (!(*line))
	{
		*line = ft_strdup("");
		if (!(*line))
			return (0);
	}
	*n = ft_strchr(buf, '\n');
	if (*n)
	{
		*n[0] = '\0';
		*n += 1;
	}
	tmp = ft_strjoin(*line, buf);
	free(*line);
	if (!(tmp))
		return (0);
	*line = tmp;
	if (*n)
		ft_strlcpy(buf, *n, BUFFER_SIZE);
	else
		ft_bzero(buf, BUFFER_SIZE);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int				balance;
	static char		buf[10240][BUFFER_SIZE + 1];
	char			*n;

	balance = 1;
	n = NULL;
	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, 0, 0) < 0 || !(line))
		return (-1);
	buf[fd][BUFFER_SIZE] = '\0';
	if (!(gnl_process_work_2(buf[fd], line, &n)))
		return (-1);
	if ((n))
		return (1);
	while (!n && balance)
	{
		balance = read(fd, buf[fd], BUFFER_SIZE);
		if (balance < 0)
			return (-1);
		if (!(gnl_process_work(buf[fd], &n, line)))
			return (-1);
	}
	if (balance || ft_strlen(buf[fd]))
		return (1);
	return (0);
}
