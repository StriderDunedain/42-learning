/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 23:56:41 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/05/03 15:25:53 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

char	*get_next_line(int fd);
size_t	ft_len(char *str);
ssize_t	read_line(int fd, char *temp, char **line);
char	*append(char *line, char *temp);
char	*trim_line(char *line);
char	*extract_line(char *line);

#endif
