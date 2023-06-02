/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:25:03 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/02 14:24:54 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	swap_a(t_num **stack_a)
{
	t_num	*second;

	if (ft_lstsize_stack(*stack_a) > 1)
	{
		second = *stack_a;
		*stack_a = (*stack_a)->next;
		second->next = (*stack_a)->next;
		(*stack_a)->next = second;
		ft_printf("sa");
	}
}

void	swap_b(t_num **stack_b)
{
	t_num	*second;

	if (ft_lstsize_stack(*stack_b) > 1)
	{
		second = *stack_b;
		*stack_b = (*stack_b)->next;
		second->next = (*stack_b)->next;
		(*stack_b)->next = second;
		ft_printf("sb");
	}
}