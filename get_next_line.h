/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:45:05 by sameye            #+#    #+#             */
/*   Updated: 2021/05/16 23:48:37 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

int	get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);

int ft_get_line(int fd, char **line);
int	ft_put_rest_in_mem(char **line, char *mem);


void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);


#endif