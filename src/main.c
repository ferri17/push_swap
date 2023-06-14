/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:21:20 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/14 22:22:27 by fbosch           ###   ########.fr       */
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
		exit_error();
	stack_a = NULL;
	stack_b = NULL;
	if (init_stacks(&stack_a, argc, argv) < 0)
		exit_error();
	//print_stacks(stack_a, stack_b);

	t_num	*new;
	new = ft_lstnew_stack(1);
	ft_lstadd_back_stack(&stack_b, new);
	new = ft_lstnew_stack(6);
	ft_lstadd_back_stack(&stack_b, new);
	new = ft_lstnew_stack(9);
	ft_lstadd_back_stack(&stack_b, new);

	if (!is_sorted(stack_a))
		sort_stack(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	ft_lstclear_stack(&stack_a);
	ft_lstclear_stack(&stack_b);
	return (0);
}
