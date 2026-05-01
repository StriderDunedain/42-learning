/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:36:56 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/11 22:04:44 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	i = 0;
	dest_len = 0;
	src_len = 0;
	while (dest[dest_len])
		dest_len++;
	while (src[src_len])
		src_len++;
	if (size < 1)
		return (src_len);
	if (size < dest_len)
		return (src_len + size);
	while (src[i] && dest_len + i < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*int	main(void) {
	char	*src = "World!";
	char	dest[50] = "Hello,  ";
	ft_strlcat(dest, src, 10);
	printf("%s\n", dest);	
}*/
