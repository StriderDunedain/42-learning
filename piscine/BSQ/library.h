/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <ypopovyc@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:57:40 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/02/17 11:02:38 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBRARY_H
# define LIBRARY_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_map
{
	char	*map;
	int		width;
	int		height;
	int		max_size;
	int		best_row;
	int		best_col;
	char	empty;
	char	obst;
	char	full;
}	t_map;

void	process_map(int fd);
int		read_header(int fd, char *buffer);
void	print(char *str);
int		parse_header(char *str, t_map *map);
int		ft_solve_bsq(t_map *info);
void	ft_print_bsq(t_map *info);
int		get_width(int fd, char **first_line, t_map *info);
int		fill_map(int fd, char *first_line, t_map *info);
int		check_valid_map(t_map *info);
int		ft_min(int a, int b, int c);

#endif