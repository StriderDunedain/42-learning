/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:38:39 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/05/08 19:38:45 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

int	print_str(char *str);
int	print_char(char c);
int	print_int(int n);
int	print_ubase(unsigned long n, unsigned long base, char *alphabet);
int	print_ptr(void *n);
int	spec_handler(va_list lst, char c);
int	ft_printf(const char *str, ...);