/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:42:29 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/15 19:18:04 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	sort_3(t_num **stack_a)
{
	int	highest;

	highest = get_highest_value(*stack_a);
	if ((*stack_a)->value == highest)
		rotate_a(stack_a);
	else if ((*stack_a)->next->value == highest)
		reverse_rotate_a(stack_a);
	if (!is_sorted(*stack_a))
		swap_a(stack_a);
}

static void	clean_a(t_num **stack_a)
{
	int	lowest;

	lowest = get_lowest_value(*stack_a);
	if (find_index(*stack_a, lowest) <= ft_lstsize_stack(*stack_a) / 2)
	{
		while ((*stack_a)->value != lowest)
			rotate_a(stack_a);
	}
	else
	{
		while ((*stack_a)->value != lowest)
			reverse_rotate_a(stack_a);
	}
}

static void	empty_ordered_b(t_num **stack_a, t_num **stack_b)
{
	int	nb;
	int	index_target;

	while (*stack_b)
	{
		index_target = find_target_bigger(*stack_a, (*stack_b)->value);
		nb = find_number_from_index(*stack_a, index_target);
		if (index_target <= ft_lstsize_stack(*stack_a) / 2)
		{
			while ((*stack_a)->value != nb)
				rotate_a(stack_a);
		}
		else
		{
			while ((*stack_a)->value != nb)
				reverse_rotate_a(stack_a);
		}
		push_a(stack_a, stack_b);
	}
}

static void	sort_b_till_3(t_num **stack_a, t_num **stack_b)
{
	int		nb;
	t_moves	move;

	while (ft_lstsize_stack(*stack_a) > 3)
	{
		nb = find_best_move(*stack_a, *stack_b, &move);
		calculate_moves(*stack_a, *stack_b, nb, &move);
		do_best_move(stack_a, stack_b, &move);
	}
}

void	sort_stack(t_num **stack_a, t_num **stack_b)
{
	int	size_a;

	size_a = ft_lstsize_stack(*stack_a);
	if (size_a == 2)
		swap_a(stack_a);
	else
	{
		if (size_a > 3)
			push_b(stack_a, stack_b);
		if (size_a > 3)
			push_b(stack_a, stack_b);
		if (size_a > 3)
			sort_b_till_3(stack_a, stack_b);
		sort_3(stack_a);
		empty_ordered_b(stack_a, stack_b);
		clean_a(stack_a);
	}
}
