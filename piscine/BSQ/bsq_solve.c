/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <ypopovyc@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:01:31 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/02/18 18:43:22 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	ft_min(int a, int b, int c)
{
	int	m;

	m = a;
	if (m > b)
		m = b;
	if (m > c)
		m = c;
	return (m);
}

void	update_max(t_map *info, int size, int r, int c)
{
	if (size > info->max_size)
	{
		info->max_size = size;
		info->best_row = r;
		info->best_col = c;
	}
}

void	ft_solve_loop(t_map *info, int *curr, int *prev)
{
	int		r;
	int		c;
	long	idx;

	r = 0;
	while (r < info->height)
	{
		c = 0;
		while (c < info->width)
		{
			idx = (long)r * (info->width + 1) + c;
			if (info->map[idx] == info->obst)
				curr[c] = 0;
			else if (r == 0 || c == 0)
				curr[c] = 1;
			else
				curr[c] = ft_min(prev[c], curr[c - 1], prev[c - 1]) + 1;
			update_max(info, curr[c], r, c);
			c++;
		}
		c = -1;
		while (++c < info->width)
			prev[c] = curr[c];
		r++;
	}
}

int	ft_solve_bsq(t_map *info)
{
	int	*curr;
	int	*prev;
	int	i;

	i = 0;
	curr = malloc(sizeof(int) * info->width);
	prev = malloc(sizeof(int) * info->width);
	if (!curr || !prev)
	{
		free(curr);
		free(prev);
		return (0);
	}
	while (i < info->width)
	{
		prev[i] = 0;
		curr[i] = 0;
		i++;
	}
	ft_solve_loop(info, curr, prev);
	free(curr);
	free(prev);
	return (1);
}
