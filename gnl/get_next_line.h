/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almohame <almohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:38:25 by almohame          #+#    #+#             */
/*   Updated: 2024/02/17 13:00:11 by almohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3

# endif

int		my_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_check(char *storage);
char	*line_maker(int fd, char *buf, char *storage);
char	*get_remaining_line(char *line);
char	*get_next_line(int fd);
char	*my_strjoin(char const *s1, char const *s2);

#endif