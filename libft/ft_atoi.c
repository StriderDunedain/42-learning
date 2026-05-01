/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:05:08 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/05/01 14:56:14 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		sign;
	int		idx;
	int		res;

	idx = 0;
	res = 0;
	sign = 1;
	str = (char *)nptr;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
		res = res * 10 + str[idx++] - '0';
	if (idx)
		return (sign * res);
	return (0);
}
