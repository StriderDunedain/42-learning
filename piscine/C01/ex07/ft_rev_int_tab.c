/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 04:23:43 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/05 04:23:44 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		i++;
		j--;
	}
}

/*int	main(void) {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	ft_rev_int_tab(arr, 10);
	int i = 0;
	while (i != 10)
		printf("%i, ", arr[i++]);
}*/
