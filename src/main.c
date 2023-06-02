/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:21:20 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/02 14:22:57 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_num	*stack_a;
	t_num	*stack_b;

	if (argc < 2)
		return (0);
	if (check_arguments(argc, argv) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (init_stacks(&stack_a, &stack_b, argc, argv) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	
	/* if (is_sorted(stack_a) == 0)
		ft_printf("It's sorted");
	else
		ft_printf("It's not sorted"); */
	//if (!is_sorted)
	//	sort_numbers();
	print_stacks(stack_a, stack_b);
	swap_a(&stack_a);
	swap_a(&stack_b);
	print_stacks(stack_a, stack_b);
	ft_lstclear_stack(&stack_a);
	ft_lstclear_stack(&stack_b);
	return (0);
}
