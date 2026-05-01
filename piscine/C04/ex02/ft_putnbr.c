/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:17:43 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/11 18:00:57 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int	n;

	n = (long int)nb;
	if (n < 0)
	{
		print('-');
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	print((n % 10) + '0');
}
/*int	main(void) {
	ft_putnbr(-2147483648);
}*/
