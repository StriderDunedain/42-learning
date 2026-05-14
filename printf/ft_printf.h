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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

# ifndef DEC_BASE
#  define DEC_BASE 10
# endif

# ifndef HEX_BASE
#  define HEX_BASE 16
# endif

# ifndef DEC
#  define DEC "0123456789"
# endif

# ifndef HEX_LOWER
#  define HEX_LOWER "0123456789abcdef"
# endif

# ifndef HEX_UPPER
#  define HEX_UPPER "0123456789ABCDEF"
# endif

int	print_str(const char *str);
int	print_char(char c);
int	print_int(int n);
int	print_ubase(uintmax_t n, uintmax_t base, const char *alphabet);
int	print_ptr(void *n);
int	spec_handler(va_list *lst, char c);
int	ft_printf(const char *str, ...);

#endif