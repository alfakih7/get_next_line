/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almohame <almohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:38:50 by almohame          #+#    #+#             */
/*   Updated: 2024/02/17 13:44:57 by almohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check(char *storage)
{
	int	i;

	i = 0;
	while (storage[i])
	{
		if (storage[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*line_maker(int fd, char *buf, char *storage)
{
	int	r_size;

	r_size = read(fd, buf, BUFFER_SIZE);
	if (r_size < 0)
		return (NULL);
	while (r_size > 0)
	{
		buf[r_size] = '\0';
		if (!storage)
			storage = ft_strdup(buf);
		else
			storage = my_strjoin(storage, buf);
		if (storage == NULL)
			return (NULL);
		if (ft_check(storage) != -1)
			return (storage);
		r_size = read(fd, buf, BUFFER_SIZE);
		if (r_size < 0)
			return (NULL);
	}
	if (storage && storage[0] != '\0')
		return (storage);
	return (free(storage), NULL);
}

char	*get_remaining_line(char *line)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	tmp = ft_strdup(line + i + 1);
	if (tmp == NULL)
		return (NULL);
	if (tmp[0] == '\0')
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	char		*temp2;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = line_maker(fd, buf, storage);
	if (line == NULL)
	{
		free(buf);
		buf = NULL;
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = get_remaining_line(line);
	temp2 = ft_strdup(line);
	free(line);
	line = NULL;
	free(buf);
	return (temp2);
}
