/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:53:31 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/15 18:59:19 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	get_highest_value(t_num *stack)
{
	int	highest;

	highest = stack->value;
	while (stack)
	{
		if (stack->value > highest)
			highest = stack->value;
		stack = stack->next;
	}
	return (highest);
}

int	get_lowest_value(t_num *stack)
{
	int	lowest;

	lowest = stack->value;
	while (stack)
	{
		if (stack->value < lowest)
			lowest = stack->value;
		stack = stack->next;
	}
	return (lowest);
}

int	find_target_smaller(t_num *stack, int nb)
{
	int	target;
	int	index;
	int	index_target;
	int	highest;

	index = 0;
	highest = get_highest_value(stack);
	if (nb < get_lowest_value(stack) || nb > highest)
		index_target = find_index(stack, highest);
	else
	{
		target = INT_MIN;
		while (stack)
		{
			if (stack->value < nb && stack->value > target)
			{
				target = stack->value;
				index_target = index;
			}
			index++;
			stack = stack->next;
		}
	}
	return (index_target);
}

int	find_target_bigger(t_num *stack, int nb)
{
	int	target;
	int	index;
	int	highest;
	int	lowest;
	int	index_target;

	index = 0;
	target = INT_MAX;
	highest = get_highest_value(stack);
	lowest = get_lowest_value(stack);
	if (nb > highest)
		return (find_index(stack, lowest));
	while (stack)
	{
		if (stack->value > nb && stack->value < target)
		{
			target = stack->value;
			index_target = index;
		}
		index++;
		stack = stack->next;
	}
	return (index_target);
}

int	find_number_from_index(t_num *stack, int index)
{
	while (index)
	{
		index--;
		stack = stack->next;
	}
	return (stack->value);
}
