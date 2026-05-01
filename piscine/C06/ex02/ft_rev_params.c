/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:02:03 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/19 16:08:31 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*str;
	int		i;

	i = 1;
	while (i < argc)
	{
		str = argv[argc - i];
		while (*str)
			write(1, str++, 1);
		write(1, "\n", 1);
		i++;
	}
}
