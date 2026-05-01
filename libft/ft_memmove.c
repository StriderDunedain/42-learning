/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:47:39 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/05/01 15:42:24 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*cast_src;
	unsigned char		*cast_dest;
	size_t				i;

	i = 0;
	cast_src = src;
	cast_dest = dest;
	if (cast_src < cast_dest && cast_src + n > cast_dest)
		while (n--)
			cast_dest[n] = cast_src[n];
	else
	{
		while (i < n)
		{
			cast_dest[i] = cast_src[i];
			i++;
		}
	}
	return (dest);
}
