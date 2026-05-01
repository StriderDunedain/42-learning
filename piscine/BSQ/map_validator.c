/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 22:36:32 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/18 18:41:31 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	read_header(int fd, char *buffer)
{
	char	c;
	int		i;

	i = 0;
	while (read(fd, &c, 1) > 0 && c != '\n' && i < 30)
		buffer[i++] = c;
	buffer[i] = '\0';
	return (i > 0);
}

int	is_valid_legend(t_map *map)
{
	if (map->empty < 32 || map->empty > 126
		|| map->obst < 32 || map->obst > 126
		|| map->full < 32 || map->full > 126)
		return (0);
	if (map->empty == map->obst || map->empty == map->full
		|| map->obst == map->full)
		return (0);
	return (1);
}

int	extract_height(char *str, int len)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (len <= 0)
		return (-1);
	while (i < len)
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		res = res * 10 + (str[i] - '0');
		if (res < 0)
			return (-1);
		i++;
	}
	return (res);
}

int	parse_header(char *str, t_map *map)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	if (len < 4)
		return (0);
	map->full = str[len - 1];
	map->obst = str[len - 2];
	map->empty = str[len - 3];
	if (!is_valid_legend(map))
		return (0);
	map->height = extract_height(str, len - 3);
	if (map->height <= 0)
		return (0);
	return (1);
}
