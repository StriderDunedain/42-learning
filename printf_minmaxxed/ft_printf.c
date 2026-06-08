/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:50:48 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/06/08 16:34:43 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(const char *s)
{
	int	count;

	if (!s)
		s = "(null)";
	count = 0;
	while (*s && write(1, s++, 1) != -1)
		++count;
	return (!*s * count - *s);
}

int	print_ubase(uintmax_t n, uintmax_t base, const char *alphabet)
{
	int	res;

	if (n >= base)
	{
		res = print_ubase(n / base, base, alphabet);
		if (res < 0 || write(1, &alphabet[n % base], 1) == -1)
			return (-1);
		return (res + 1);
	}
	return (write(1, &alphabet[n], 1));
}

int	print_int(int n)
{
	int	res;

	if (n < 0 && write(1, "-", 1) == -1)
		return (-1);
	res = print_ubase((long)(n)*((n >= 0) - (n < 0)), DEC_BASE, DEC);
	return (res + (n < 0 && res >= 0));
}

int	spec_handler(va_list *lst, char c)
{
	int		res;
	void	*ptr;

	if (c == 'c')
		return (write(1, &(char){va_arg(*lst, int)}, 1));
	if (c == 's')
		return (print_str(va_arg(*lst, char *)));
	if (c == 'd' || c == 'i')
		return (print_int(va_arg(*lst, int)));
	if (c == 'u')
		return (print_ubase(va_arg(*lst, unsigned int), DEC_BASE, DEC));
	if (c == 'x')
		return (print_ubase(va_arg(*lst, unsigned int), HEX_BASE, HEX_LOWER));
	if (c == 'X')
		return (print_ubase(va_arg(*lst, unsigned int), HEX_BASE, HEX_UPPER));
	if (c != 'p')
		return (write(1, &c, 1));
	ptr = va_arg(*lst, void *);
	if (!ptr)
		return (print_str("(nil)"));
	if (print_str("0x") < 0)
		return (-1);
	res = print_ubase((uintptr_t)ptr, HEX_BASE, HEX_LOWER);
	return (res + 2 * !!~res);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		size;
	int		bytes;

	size = 0;
	va_start(lst, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
			bytes = spec_handler(&lst, *(++str));
		else
			bytes = write(1, str, 1);
		if (bytes < 0)
			return (va_end(lst), -1);
		size += bytes;
		++str;
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
