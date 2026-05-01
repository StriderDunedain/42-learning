/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 22:37:13 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/13 22:47:25 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 0 && power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, --power));
}
/*int	main(void) {
	printf("Result: %i\n", ft_recursive_power(-5, 0));
}*/
