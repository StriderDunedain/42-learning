/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:52:24 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/13 19:16:01 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	len(char *s)
{
	unsigned int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	has_duplicates(char *base, unsigned int base_len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < base_len)
	{
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	base_valid(char *base)
{
	if (len(base) <= 1 || has_duplicates(base, len(base)))
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (0);
		base++;
	}
	return (1);
}

void	print(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_len;
	long int		n;

	if (!base || !base_valid(base))
		return ;
	base_len = len(base);
	n = (long int)nbr;
	if (n < 0)
	{
		print('-');
		n *= -1;
	}
	if (n >= base_len)
		ft_putnbr_base(n / base_len, base);
	print(base[n % base_len]);
}
/*int	main(void) {
	ft_putnbr_base(-15, "012345");
}*/
