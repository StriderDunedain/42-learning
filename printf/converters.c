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

int	print_str(char *str)
{
	int	count;

	if (!str)
		return (write(1, "(null)", 6));
	count = 0;
	while (*str)
		count += write(1, str++, 1);
	return (count);
}

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_int(int n)
{
	int	count;

	if (n == INT_MIN)
		return (print_str("-2147483648"));
	count = 0;
	if (n < 0)
	{
		count += print_str("-");
		n = -n;
	}
	if (n >= 10)
		count += print_int(n / 10);
	count += print_char((n % 10) + '0');
	return (count);
}

int	print_ubase(unsigned long n, unsigned long base, char *alphabet)
{
	int	count;

	count = 0;
	if (n >= base)
		count += print_ubase(n / base, base, alphabet);
	count += print_char(alphabet[n % base]);
	return (count);
}

int	print_ptr(void *ptr)
{
	if (!ptr)
		return (print_str("(nil)"));
	print_str("0x");
	return (print_ubase((unsigned long)ptr, 16, "0123456789abcdef") + 2);
}

/*int	main(void) {
	int	i = 5;
	printf(": %i\n", printf("%i", i));
	printf(": %i\n", print_int(i));
}*/
