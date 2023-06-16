/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:38:26 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/16 13:51:59 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	reverse_rotate_a_bonus(t_num **stack_a)
{
	t_num	*temp;
	t_num	*new_last;

	if (ft_lstsize_stack(*stack_a) > 1)
	{
		temp = ft_lstlast_stack(*stack_a);
		new_last = *stack_a;
		while (new_last->next->next)
			new_last = new_last->next;
		new_last->next = NULL;
		temp->next = *stack_a;
		*stack_a = temp;
	}
}

void	reverse_rotate_b_bonus(t_num **stack_b)
{
	t_num	*temp;
	t_num	*new_last;

	if (ft_lstsize_stack(*stack_b) > 1)
	{
		temp = ft_lstlast_stack(*stack_b);
		new_last = *stack_b;
		while (new_last->next->next)
			new_last = new_last->next;
		new_last->next = NULL;
		temp->next = *stack_b;
		*stack_b = temp;
	}
}

void	reverse_rotate_all_bonus(t_num **stack_a, t_num **stack_b)
{
	t_num	*temp;
	t_num	*new_last;

	if (ft_lstsize_stack(*stack_a) > 1)
	{
		temp = ft_lstlast_stack(*stack_a);
		new_last = *stack_a;
		while (new_last->next->next)
			new_last = new_last->next;
		new_last->next = NULL;
		temp->next = *stack_a;
		*stack_a = temp;
	}
	if (ft_lstsize_stack(*stack_b) > 1)
	{
		temp = ft_lstlast_stack(*stack_b);
		new_last = *stack_b;
		while (new_last->next->next)
			new_last = new_last->next;
		new_last->next = NULL;
		temp->next = *stack_b;
		*stack_b = temp;
	}
}
