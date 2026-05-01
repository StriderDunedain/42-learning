/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:32:36 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/11 21:44:54 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j] && str[i + j] && to_find[j])
				j++;
			if (to_find[j] == '\0')
				return (str + i);
			j = 0;
		}
		i++;
	}
	return (0);
}
/*int	main(void) {
	char	*str = "haystack";
	char	*to_find = "";

	printf("%s\n", ft_strstr(str, to_find));
}*/
