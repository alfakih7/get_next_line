/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almohame <almohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:30:27 by almohame          #+#    #+#             */
/*   Updated: 2024/02/13 22:55:37 by almohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	my_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	j = my_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (j + 1));
	if (s2 == NULL)
		return (0);
	while (i < j)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*my_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*sc;

	if (s1 == 0 || s2 == 0)
		return (0);
	j = 0;
	i = 0;
	sc = (char *)malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
	if (sc == NULL)
		return (0);
	while (s1[i])
	{
		sc[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		sc[i + j] = s2[j];
		j++;
	}
	sc[i + j] = '\0';
	free((void *)s1);
	s1 = NULL;
	return (sc);
}
