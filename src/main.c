/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:10:49 by fbosch            #+#    #+#             */
/*   Updated: 2023/05/30 00:14:15 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(void)
{
	int ft_print;
	int real;

	char c = 'P';
	char *str1 = "Hola";
	char *str2 = NULL;
	int x = -2147483648;
	unsigned int y = 4147483648;
	int z = 255;

	ft_print = ft_printf("Char: %c, Str: %s, Str(null): %s, Pointer: %p, Decimal: %d, Integer: %i, Unsigned: %u, Hexa_low: %x, Hexa_upper: %X, %% \n", c, str1, str2, str1, ft_atoi("-23t4"), x, y, z, z);
	real = printf("Char: %c, Str: %s, Str(null): %s, Pointer: %p, Decimal: %d, Integer: %i, Unsigned: %u, Hexa_low: %x, Hexa_upper: %X, %% \n", c, str1, str2, str1, ft_atoi("-23t4"), x, y, z, z);
	printf("ft_print: %i\n", ft_print);
	printf("real: %i\n", real);
}
