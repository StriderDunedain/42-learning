/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:01:21 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/01 00:01:24 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_alphabet(void)
{
	write(1, "abcdefghijklmnopqrstuvwxyz", 26);
}

/*int   main(void) {
        int i = 97;
        while (i != 97 + 26) {
                write(1, &i, 1);
                i++;
        }
        write(1, "\n", 1);
        ft_print_alphabet();
}*/
