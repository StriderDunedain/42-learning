/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:09:02 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/19 16:08:09 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_args(char **argv)
{
	char	*str;

	argv++;
	while (*argv)
	{
		str = *argv++;
		while (*str)
			write(1, str++, 1);
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc)
		print_args(argv);
	else
		print_args(argv);
}
