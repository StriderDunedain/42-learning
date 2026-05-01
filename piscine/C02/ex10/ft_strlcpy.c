/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 00:31:01 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/08 00:31:02 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
/*int	main(void)
{
	char	dest[] = "Olleh, World!";
	char	*src = "Hello";
	printf("Remade: %i\n", ft_strlcpy(dest, src, 0));
	printf("Dest: %s\n", dest);
}*/
