/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:46:45 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/05/01 15:03:18 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		s_len;
	int		i;

	i = 0;
	s_len = 0;
	while (s[s_len])
		s_len++;
	dest = malloc(sizeof(char) * (s_len + 1));
	if (!dest)
		return (NULL);
	while (i < s_len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
