/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 02:08:57 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/05 02:09:00 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int	main(void) {
	int a = 5;
	int b = 2;

	int div;
	int mod;

	ft_div_mod(a, b, &div, &mod);

	printf("div: %i | mod: %i\n", div, mod);
}*/
