/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:17:39 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/02/07 20:17:39 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
void	lower(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	in_word;
	int	i;

	in_word = 0;
	i = 0;
	lower(str);
	while (str[i])
	{
		if (((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= '0' && str[i] <= '9'))
			&& (!in_word))
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
				str[i] -= 32;
			in_word = 1;
			i++;
		}
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= '0' && str[i] <= '9')))
			in_word = 0;
		i++;
	}
	return (str);
}
/*int	main(void) {
	char	s[] = "  jligh iowKFkdkEEDkDDD FiF   ";
	char	n[] = "hi, how are you? 42words forty-two; fifty+and+one";
	printf("Result: '%s'\n", ft_strcapitalize(s));
	printf("Result: '%s'\n", ft_strcapitalize(n));
}*/
