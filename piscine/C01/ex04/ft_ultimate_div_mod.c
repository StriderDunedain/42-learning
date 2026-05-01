/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 04:09:34 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/05 04:09:36 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *a / *b;
	*b = tmp % *b;
}

/*int	main(void) {
	int a = 5;
	int b = 2;
	ft_ultimate_div_mod(&a, &b);
	printf("a: %i | b: %i\n", a, b);
}*/
