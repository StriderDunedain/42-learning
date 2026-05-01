/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <ypopovyc@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:36:59 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/02/18 18:42:31 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	handle_error(void)
{
	write(2, "map error\n", 10);
}

void	run_bsq_logic(t_map *info)
{
	if (check_valid_map(info))
	{
		ft_solve_bsq(info);
		ft_print_bsq(info);
	}
	else
		handle_error();
	free(info->map);
}

int	read_and_init(int fd, char *header, char **first_line, t_map *info)
{
	if (!read_header(fd, header))
		return (0);
	if (!parse_header(header, info))
		return (0);
	if (!get_width(fd, first_line, info))
		return (0);
	return (1);
}

void	process_map(int fd)
{
	t_map	info;
	char	header[32];
	char	*first_line;

	info.map = NULL;
	info.max_size = 0;
	info.best_row = 0;
	info.best_col = 0;
	if (!read_and_init(fd, header, &first_line, &info))
	{
		handle_error();
		return ;
	}
	if (fill_map(fd, first_line, &info))
		run_bsq_logic(&info);
	else
		handle_error();
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	if (argc == 1)
		process_map(0);
	else
	{
		i = 1;
		while (i < argc)
		{
			if (i > 1)
				write(1, "\n", 1);
			fd = open(argv[i], O_RDONLY);
			if (fd >= 0)
			{
				process_map(fd);
				close(fd);
			}
			else
				handle_error();
			i++;
		}
	}
	return (0);
}
