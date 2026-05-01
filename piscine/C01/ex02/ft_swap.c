/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 02:03:58 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/05 02:04:02 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*int	main(void) {
	int i = 5;
	int j = 10;
	int *a = &i;
	int *b = &j;
	printf("a: %i | b: %i\n", *a ,*b);
	ft_swap(a, b);
	printf("a: %i | b: %i\n", *a ,*b);
}*/
