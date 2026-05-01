/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:42:19 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/11 15:31:55 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
unsigned int	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	dest_len;
	unsigned int	i;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
/*int	main(void) {
	char	*src = "World!";
	char	dest[50] = "Hello, ";

	printf("%s\n", ft_strcat(dest, src));
}*/
