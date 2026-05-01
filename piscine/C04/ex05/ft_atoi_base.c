/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:02:11 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/13 21:21:08 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	len(char *base)
{
	unsigned int	len;

	len = 0;
	while (base[len])
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

int	get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	sign;
	int	index;

	res = 0;
	sign = 1;
	if (!base || !base_valid(base))
		return (0);
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	index = get_index(*str, base);
	while (index != -1)
	{
		res = res * len(base) + index;
		str++;
		index = get_index(*str, base);
	}
	return (res * sign);
}
/*int	main(void) {
	printf("Result: %i\n", ft_atoi_base("     -+----+10", "01"));
}*/
