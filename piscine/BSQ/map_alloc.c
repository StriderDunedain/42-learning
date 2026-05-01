/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <ypopovyc@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 22:58:18 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/02/18 18:43:53 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "library.h"

char	*append_char(char *str, char c, int len)
{
	char	*new_str;
	int		i;

	new_str = malloc(sizeof(char) * (len + 2));
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	free(str);
	return (new_str);
}

int	get_width(int fd, char **first_line, t_map *info)
{
	char	c;
	int		len;

	len = 0;
	*first_line = malloc(sizeof(char) * 1);
	if (!*first_line)
		return (0);
	(*first_line)[0] = '\0';
	while (read(fd, &c, 1) > 0)
	{
		*first_line = append_char(*first_line, c, len);
		if (!*first_line)
			return (0);
		len++;
		if (c == '\n')
			break ;
	}
	if (len == 0)
		return (free(*first_line), 0);
	info->width = len - 1;
	return (1);
}

int	read_remainder(t_map *info, int fd, int already_read)
{
	long	total_expected;
	long	total_read;
	int		ret;

	total_expected = (long)(info->width + 1) * info->height;
	total_read = already_read;
	while (total_read < total_expected)
	{
		ret = read(fd, info->map + total_read, total_expected - total_read);
		if (ret <= 0)
			return (0);
		total_read += ret;
	}
	if (read(fd, info->map, 1) > 0)
		return (0);
	return (1);
}

int	fill_map(int fd, char *first_line, t_map *info)
{
	int		i;
	long	full_size;

	if (info->width <= 0 || info->height <= 0)
		return (free(first_line), 0);
	full_size = (long)(info->width + 1) * info->height;
	info->map = malloc(sizeof(char) * (full_size + 1));
	if (!info->map)
		return (free(first_line), 0);
	i = -1;
	while (++i <= info->width)
		info->map[i] = first_line[i];
	free(first_line);
	if (!read_remainder(info, fd, info->width + 1))
		return (0);
	info->map[full_size] = '\0';
	return (1);
}

int	check_valid_map(t_map *info)
{
	long	i;
	long	size;

	if (info->height <= 0 || info->width <= 0)
		return (0);
	i = 0;
	size = (long)(info->width + 1) * info->height;
	while (i < size)
	{
		if ((i + 1) % (info->width + 1) == 0)
		{
			if (info->map[i] != '\n')
				return (0);
		}
		else if (info->map[i] != info->empty && info->map[i] != info->obst)
			return (0);
		i++;
	}
	return (1);
}
