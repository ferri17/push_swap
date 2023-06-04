/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:38:26 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/04 02:50:39 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	reverse_rotate_a(t_num **stack_a)
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
		ft_printf("rra\n");
	}
}

void	reverse_rotate_b(t_num **stack_b)
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
		ft_printf("rrb\n");
	}
}

void	reverse_rotate_all(t_num **stack_a, t_num **stack_b)
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
	ft_printf("rrr\n");
}
