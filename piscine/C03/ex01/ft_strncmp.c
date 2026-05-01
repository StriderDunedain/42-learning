/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:34:10 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/11 21:41:40 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && (i < n - 1))
		i++;
	return ((unsigned int)s1[i] - (unsigned int)s2[i]);
}
/*int	main(void) {
	printf("Result: %i\n", ft_strncmp("Hello", "Helln", 10));
}*/
