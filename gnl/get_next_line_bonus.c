/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almohame <almohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:34:14 by almohame          #+#    #+#             */
/*   Updated: 2024/02/17 13:41:54 by almohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*storage[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = line_maker(fd, buf, storage[fd]);
	if (line == NULL)
	{
		free(buf);
		buf = NULL;
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	storage[fd] = get_remaining_line(line);
	temp2 = ft_strdup(line);
	free(line);
	line = NULL;
	free(buf);
	return (temp2);
}
