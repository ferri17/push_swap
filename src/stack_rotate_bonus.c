/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:01:50 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/16 13:52:14 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rotate_a_bonus(t_num **stack_a)
{
	t_num	*temp;

	if (ft_lstsize_stack(*stack_a) > 1)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_lstlast_stack(*stack_a)->next = temp;
		temp->next = NULL;
	}
}

void	rotate_b_bonus(t_num **stack_b)
{
	t_num	*temp;

	if (ft_lstsize_stack(*stack_b) > 1)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		ft_lstlast_stack(*stack_b)->next = temp;
		temp->next = NULL;
	}
}

void	rotate_all_bonus(t_num **stack_a, t_num **stack_b)
{
	t_num	*temp_a;
	t_num	*temp_b;

	if (ft_lstsize_stack(*stack_a) > 1)
	{
		temp_a = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_lstlast_stack(*stack_a)->next = temp_a;
		temp_a->next = NULL;
	}
	if (ft_lstsize_stack(*stack_b) > 1)
	{
		temp_b = *stack_b;
		*stack_b = (*stack_b)->next;
		ft_lstlast_stack(*stack_b)->next = temp_b;
		temp_b->next = NULL;
	}
}
