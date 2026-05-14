/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 20:27:57 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/05/08 19:55:45 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(const char *str)
{
	int	count;

	if (!str)
		str = "(null)";
	count = 0;
	while (*str)
	{
		if (write(1, str++, 1) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_int(int n)
{
	long	nb;
	int		res;
	int		sign;

	nb = n;
	sign = 0;
	if (nb < 0)
	{
		if (print_char('-') == -1)
			return (-1);
		nb = -nb;
		sign = 1;
	}
	res = print_ubase(nb, DEC_BASE, DEC);
	if (res == -1)
		return (-1);
	return (res + sign);
}

int	print_ubase(uintmax_t n, uintmax_t base, const char *alphabet)
{
	int	count;
	int	res;

	count = 0;
	if (n >= base)
	{
		res = print_ubase(n / base, base, alphabet);
		if (res == -1)
			return (-1);
		count += res;
	}
	if (print_char(alphabet[n % base]) == -1)
		return (-1);
	return (count + 1);
}

int	print_ptr(void *ptr)
{
	int	res;

	if (!ptr)
		return (print_str("(nil)"));
	if (print_str("0x") == -1)
		return (-1);
	res = print_ubase((uintmax_t)(uintptr_t)ptr, HEX_BASE, HEX_LOWER);
	if (res == -1)
		return (-1);
	return (res + 2);
}
