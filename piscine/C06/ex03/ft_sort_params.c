/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:14:56 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/19 15:14:56 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned int)*s1 - (unsigned int)*s2);
}

void	print(char **argv)
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
	char	*tmp;
	int		i;
	int		j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[j];
				argv[j] = tmp;
			}
			j++;
		}
		i++;
	}
	print(argv);
}
