/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <ypopovyc@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:38:43 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/02/18 18:42:01 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	ft_print_bsq(t_map *info)
{
	int		row;
	int		col;
	long	line_len;

	line_len = info->width + 1;
	if (info->max_size > 0)
	{
		row = info->best_row;
		while (row > info->best_row - info->max_size)
		{
			col = info->best_col;
			while (col > info->best_col - info->max_size)
			{
				info->map[(long)row * line_len + col] = info->full;
				col--;
			}
			row--;
		}
	}
	write(1, info->map, line_len * info->height);
}
