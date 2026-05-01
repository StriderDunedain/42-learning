/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 04:32:59 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/10 00:03:46 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned int n)
{
	char	c;

	if (n < 10)
		c = '0' + n;
	else
		c = 'a' + (n - 10);
	write(1, &c, 1);
}

void	print_chars(unsigned char *bytes, unsigned int line_bytes)
{
	unsigned int	i;

	i = 0;
	while (i < line_bytes)
	{
		if (bytes[i] >= ' ' && bytes[i] <= '~')
			write(1, &bytes[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	print_addr(void *addr)
{
	unsigned long	address;
	int				i;

	address = (unsigned long)addr;
	i = 15;
	while (i >= 0)
	{
		print_hex((address >> (i * 4)) & 0xF);
		i--;
	}
	write(1, ": ", 2);
}

void	print_padded_bytes(unsigned char *bytes, unsigned int size)
{
	unsigned char	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			print_hex((bytes[i] >> 4) & 0xF);
			print_hex(bytes[i] & 0xF);
		}
		else
			write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*bytes;
	unsigned int	line_bytes;
	unsigned int	offset;

	offset = 0;
	bytes = (unsigned char *)addr;
	while (offset < size)
	{
		line_bytes = 16;
		if (size - offset < 16)
			line_bytes = size - offset;
		print_addr(addr + offset);
		print_padded_bytes(bytes + offset, line_bytes);
		print_chars(bytes + offset, line_bytes);
		write(1, "\n", 1);
		offset += line_bytes;
	}
	return (addr);
}
/*int	main(void) {
	void	*void_ptr = "This\n is a message!\n It's supposed to be very cool!";

	ft_print_memory(void_ptr, 75);
	write(1, "\n5-char iteration\n", 18);
	ft_print_memory(void_ptr, 5);
}*/
