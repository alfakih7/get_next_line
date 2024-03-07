/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almohame <almohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:31:27 by almohame          #+#    #+#             */
/*   Updated: 2024/02/17 13:34:13 by almohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

int		my_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_check(char *storage);
char	*line_maker(int fd, char *buf, char *storage);
char	*get_remaining_line(char *line);
char	*get_next_line(int fd);
char	*my_strjoin(char const *s1, char const *s2);

#endif