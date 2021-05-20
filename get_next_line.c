/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:51:19 by sameye            #+#    #+#             */
/*   Updated: 2021/05/20 11:10:46 by sameye           ###   ########.fr       */
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
	int	j;

	i = 0;
	j = 0;
	while (((*line)[i]))
	{
		if ((*line)[i] == '\n')
		{
			(*line)[i] = '\0';
			i++;
			while ((*line)[i + j])
			{
				mem[j] = (*line)[i + j];
				j++;
			}
			mem[j] = '\0';
			return (1);
		}
		i++;
	}
	return (-1);
}

int	ft_get_line(int fd, char **line)
{
	char		*buff;
	int			err;
	char		*newline;
	static char	mem[BUFFER_SIZE + 1];

	err = 1;
	newline = ft_strjoin(*line, mem);
	free(*line);
	*line = newline;
	ft_memset(mem, 0, BUFFER_SIZE + 1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (-1);
	while (!(ft_has_return(*line)) && err != 0)
	{
		ft_memset(buff, 0, BUFFER_SIZE + 1);
		err = read(fd, buff, BUFFER_SIZE);
		if (err == -1)
		{
			free(buff);
			return (-1);
		}
		newline = ft_strjoin(*line, buff);
		free(*line);
		*line = newline;
	}
	free(buff);
	ft_put_rest_in_mem(line, mem);
	if (err == 0 && ft_strlen(mem) == 0)
		return (0);
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
	{
		free(*line);
		*line = NULL;
	}
	return (err);
}
