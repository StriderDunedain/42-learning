/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 04:39:44 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/05 04:39:45 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
void	ft_sort_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
/*int	main(void) {
	int arr[] = { 1, 0, -1, 5, 4, 7, 10, 3, 8 };
	int i = 0;
        while (i < 9)
                printf("%i, ", arr[i++]);

	ft_sort_int_tab(arr, 9);
	i = 0;
	printf("\n");
	while (i < 9)
		printf("%i, ", arr[i++]);
}*/
