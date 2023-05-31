/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:21:20 by fbosch            #+#    #+#             */
/*   Updated: 2023/05/31 22:16:41 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	compare_numbers(const char *s1, const char *s2)
{
	return (ft_atoi(s1) - ft_atoi(s2));
}

int	check_int(char *s_num)
{
	int	result;
	int sign;

	sign = 1;
	if (*s_num == '+' || *s_num == '-')
	{
		if (*s_num == '-')
			sign *= -1;
		s_num++;
	}
	result = 0;
	while (*s_num >= '0' && *s_num <= '9')
	{
		if ((sign == 1 && (result > INT_MAX / 10
			|| (result == INT_MAX / 10 && (*s_num - '0') > INT_MAX % 10))))
				return (-1);
		if ((sign == -1 && (result > -(INT_MIN / 10)
			|| (result == -(INT_MIN / 10)
				&& (*s_num - '0') > -(INT_MIN % 10)))))
					return (-1);
		result = result * 10 + *s_num - '0';
		s_num++;
	}
	return (0);
}

int	check_duplicates(int argc, char **argv, int index)
{
	int j;

	j = index + 1;
	while (j < argc)
	{
		if (compare_numbers(argv[index], argv[j]) == 0)
			return (-1);
		j++;
	}
	return (0);
}
int	check_arguments(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (argv[i][j] == '\0')
			return (-1);
		while (argv[i][j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
				return (-1);
		}
		if (check_duplicates(argc, argv, i) < 0 || check_int(argv[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}
#include <stdio.h>
int	main(int argc, char **argv)
{
	//t_numbers *stack_a;
	//t_numbers *stack_b;
	
	if (argc < 2)
		return (0);
	if (check_arguments(argc, argv) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
		//fill_stack(stack_a);
	return (0);
}