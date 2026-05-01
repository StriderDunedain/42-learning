/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:23:33 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/19 16:07:27 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *name)
{
	while (*name)
		write(1, name++, 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc || argv)
		print(argv[0]);
	else
		print(argv[0]);
}
