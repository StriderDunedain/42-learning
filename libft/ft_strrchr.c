/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:27:57 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/05/01 15:04:13 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ans;

	ans = NULL;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			ans = (char *)s;
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		ans = (char *)s;
	return (ans);
}
