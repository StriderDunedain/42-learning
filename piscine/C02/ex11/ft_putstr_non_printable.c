/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 03:08:09 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/08 03:08:09 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned int n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		print_hex(n / 16);
	write(1, &hex[n % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	c;

	while (*str)
	{
		c = (unsigned char)*str;
		if (c >= ' ' && c <= '~')
			write(1, str, 1);
		else
		{
			write(1, "\\", 1);
			if (c <= 15)
				write(1, "0", 1);
			print_hex(c);
		}
		str++;
	}
}
/*int	main(void) {
	ft_putstr_non_printable("This is\177\n \t \v \b the message");
}*/
