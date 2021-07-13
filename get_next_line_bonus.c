/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copie_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:51:19 by sameye            #+#    #+#             */
/*   Updated: 2021/07/13 18:36:37 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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
			i++;
			while ((*line)[i + j])
			{
				mem[j] = (*line)[i + j];
				j++;
			}
			mem[j] = '\0';
			(*line)[i] = '\0';
			return (1);
		}
		i++;
	}
	return (-1);
}

int	ft_read_until_return (int fd, char **line, char *buff)
{
	int		err;
	char	*templine;

	err = 1;
	while (!(ft_has_return(*line)) && err > 0)
	{
		ft_memset(buff, 0, BUFFER_SIZE + 1);
		err = read(fd, buff, BUFFER_SIZE);
		templine = ft_strjoin(*line, buff);
		free(*line);
		*line = templine;
	}
	return (err);
}

int	ft_get_line(int fd, char **line, char *mem)
{
	char		buff[BUFFER_SIZE + 1];
	int			err;
	char		**newline;
	char		*vnewline;

	newline = &vnewline;
	*newline = ft_strjoin(mem, "");
	if (*newline == NULL)
		return (-1);
	ft_memset(mem, 0, BUFFER_SIZE + 1);
	err = ft_read_until_return (fd, newline, buff);
	ft_put_rest_in_mem(newline, mem);
	*line = ft_strjoin(*newline, "");
	free(*newline);
	if (err == -1)
		return (-1);
	if (err == 0 && (ft_strlen(mem) == 0) && (ft_strlen(*line) == 0))
		return (-1);
	return (1);
}

char	*get_next_line(int fd)
{
	int			err;
	static char	*mem[1024];
	char		**line;
	char		*line2;

	line = &line2;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (NULL);
	if (mem[fd] == NULL)
	{
		mem[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (mem[fd] == NULL)
			return (NULL);
		ft_memset(mem[fd], 0, BUFFER_SIZE + 1);
	}
	err = ft_get_line(fd, line, mem[fd]);
	if (err == 0)
	{
		free(mem[fd]);
		mem[fd] = NULL;
	}
	if (err == -1)
	{
		free(mem[fd]);
		mem[fd] = NULL;
		free(*line);
		*line = NULL;
	}
	return (*line);
}