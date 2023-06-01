/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:21:20 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/01 14:17:11 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ini_stacks(t_numbers **stack_a, t_numbers **stack_b, int argc, char **argv)
{
	char **num_array;
	t_list new;
	int number;
	int len;
	int i;

	i = 0;
	if (argc == 2)
	{
		num_array = ft_split(argv[1], ' ');
		if (!num_array)
			return (-1);
		while (num_array[i])
			len++;
	}
	else
	{
		argv++;
		num_array = argv;
		len = argc - 1;
	}
	i = 0;
	while (i < len)
	{
		new = ft_lstnew(ft_atoi(*num_array));
		ft_lstadd_back(stack_a, new);
		num_array++;
	}
	return (0);
} 

int	main(int argc, char **argv)
{
	t_numbers *stack_a;
	t_numbers *stack_b; 
	
	if (argc < 2)
		return (0);
	if (check_arguments(argc, argv) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	//if (ini_stacks(&stack_a, &stack_b, argc, argv) < 0)

	return (0);
}
