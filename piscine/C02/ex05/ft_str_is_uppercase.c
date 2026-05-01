/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:29:28 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/07 19:29:31 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
int	ft_str_is_uppercase(char *str)
{
	while (*str)
	{
		if (!(*str >= 'A' && *str <= 'Z'))
			return (0);
		str++;
	}
	return (1);
}
/*int   main(void) {
	printf("Result: %i\n", ft_str_is_uppercase("JFJFJF"));
        printf("Result: %i\n", ft_str_is_uppercase("djdjd5"));
	printf("Result: %i\n", ft_str_is_uppercase("JKFjkvsjsje43"));
}*/
