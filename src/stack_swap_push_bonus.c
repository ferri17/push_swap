/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap_push_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:25:03 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/16 13:52:27 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	swap_a_bonus(t_num **stack_a)
{
	t_num	*temp;

	if (ft_lstsize_stack(*stack_a) > 1)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = (*stack_a)->next;
		(*stack_a)->next = temp;
	}
}

void	swap_b_bonus(t_num **stack_b)
{
	t_num	*temp;

	if (ft_lstsize_stack(*stack_b) > 1)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = (*stack_b)->next;
		(*stack_b)->next = temp;
	}
}

void	swap_all_bonus(t_num **stack_a, t_num **stack_b)
{
	t_num	*temp_a;
	t_num	*temp_b;

	if (ft_lstsize_stack(*stack_a) > 1)
	{
		temp_a = *stack_a;
		*stack_a = (*stack_a)->next;
		temp_a->next = (*stack_a)->next;
		(*stack_a)->next = temp_a;
	}
	if (ft_lstsize_stack(*stack_b) > 1)
	{
		temp_b = *stack_b;
		*stack_b = (*stack_b)->next;
		temp_b->next = (*stack_b)->next;
		(*stack_b)->next = temp_b;
	}
}

void	push_a_bonus(t_num **stack_a, t_num **stack_b)
{
	t_num	*temp;

	if (*stack_b)
	{
		temp = *stack_a;
		*stack_a = *stack_b;
		*stack_b = (*stack_b)->next;
		(*stack_a)->next = temp;
	}
}

void	push_b_bonus(t_num **stack_a, t_num **stack_b)
{
	t_num	*temp;

	if (*stack_a)
	{
		temp = *stack_b;
		*stack_b = *stack_a;
		*stack_a = (*stack_a)->next;
		(*stack_b)->next = temp;
	}
}
