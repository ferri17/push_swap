/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:21:20 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/16 17:34:00 by fbosch           ###   ########.fr       */
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
	if (!is_sorted(stack_a))
		sort_stack(&stack_a, &stack_b);
	ft_lstclear_stack(&stack_a);
	ft_lstclear_stack(&stack_b);
	return (0);
}
