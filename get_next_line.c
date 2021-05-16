/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:51:19 by sameye            #+#    #+#             */
/*   Updated: 2021/05/17 00:07:12 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_has_return(char *res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		if (res[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_put_rest_in_mem(char **line, char *mem)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while ((*line[i]))
	{
		if (*line[i] == '\n')
		{
			while (*line[i + j])
			{
				mem[j] = *line[i + j];
				j++;
			}
			mem[j] = '\0';
			*line[i] = '\0';

			return (1);
		}
		i++;
	}
	return (-1);
}


int	ft_get_line(int fd, char **line)
{
	char	*buff;
	int		err;
	char	*newline;
	static char	mem[BUFFER_SIZE + 1];

	newline = ft_strjoin(*line, mem);
	free(*line);
	ft_bzero(mem, BUFFER_SIZE + 1);
	*line = newline;

	while (!(ft_has_return(*line)))
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		ft_bzero(buff, BUFFER_SIZE + 1);
		if (buff == NULL)
			return (-1);
		err = read(fd, buff, BUFFER_SIZE);
		if (err == -1)
			return (-1);
		newline = ft_strjoin(*line, buff);
		free(*line);
		*line = newline;
	}
	ft_put_rest_in_mem(line, mem);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			err;
	char		*res;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	res = malloc(sizeof(char));
	if (res == NULL)
		return (-1);
	res[0] = '\0';
	*line = res;
	err = ft_get_line(fd, line);
	if (err == -1)
		return (-1);
	return (1);
}
