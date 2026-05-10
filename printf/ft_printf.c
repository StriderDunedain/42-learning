/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:50:48 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/05/10 13:24:14 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	spec_handler(va_list lst, char c)
{
	int	size;

	size = 0;
	if (c == 'c')
		size += print_char((char)va_arg(lst, int));
	else if (c == 's')
		size += print_str(va_arg(lst, char *));
	else if (c == 'p')
		size += print_ptr(va_arg(lst, void *));
	else if (c == 'd' || c == 'i')
		size += print_int(va_arg(lst, int));
	else if (c == 'u')
		size += print_ubase(va_arg(lst, unsigned int), 10, "0123456789");
	else if (c == 'x')
		size += print_ubase(va_arg(lst, unsigned int), 16, "0123456789abcdef");
	else if (c == 'X')
		size += print_ubase(va_arg(lst, unsigned int), 16, "0123456789ABCDEF");
	else
		size += print_char(c);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		size;

	size = 0;
	va_start(lst, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
			size += spec_handler(lst, *(++str));
		else
			size += write(1, str, 1);
		str++;
	}
	va_end(lst);
	return (size);
}

/*int	main(void) {
	#include <stdio.h>
	printf("%i:\n");
	ft_printf("%i:\n\n");
	printf("%h:\n");
	ft_printf("%h:\n\n");
	printf("%:\n");
	ft_printf("%:\n\n");
	printf("%%:\n");
	ft_printf("%%:\n\n");
}*/
