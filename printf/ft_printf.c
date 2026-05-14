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

int	spec_handler(va_list *lst, char c)
{
	if (c == 'c')
		return (print_char((char)va_arg(*lst, int)));
	else if (c == 's')
		return (print_str(va_arg(*lst, char *)));
	else if (c == 'p')
		return (print_ptr(va_arg(*lst, void *)));
	else if (c == 'd' || c == 'i')
		return (print_int(va_arg(*lst, int)));
	else if (c == 'u')
		return (print_ubase(va_arg(*lst, unsigned int), DEC_BASE, DEC));
	else if (c == 'x')
		return (print_ubase(va_arg(*lst, unsigned int), HEX_BASE, HEX_LOWER));
	else if (c == 'X')
		return (print_ubase(va_arg(*lst, unsigned int), HEX_BASE, HEX_UPPER));
	return (print_char(c));
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		size;
	int		tmp;

	size = 0;
	va_start(lst, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			tmp = spec_handler(&lst, *(++str));
			if (tmp == -1)
				return (va_end(lst), -1);
			size += tmp;
		}
		else
		{
			if (write(1, str, 1) == -1)
				return (va_end(lst), -1);
			size++;
		}
		str++;
	}
	va_end(lst);
	return (size);
}

// int	main(void) {
// 	printf("%i\n", printf(""));
// 	printf("%i\n", ft_printf(""));
// 	printf("%i\n", printf("%"));
// 	printf("%i\n", ft_printf("%"));
// 	printf("%i\n", printf("fdj%wff", 55));
// 	printf("%i\n", ft_printf("fdj%wff", 55));
// }