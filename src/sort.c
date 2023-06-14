/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:42:29 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/14 03:25:33 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	get_highest_value(t_num *stack)
{
	int		highest;
	
	highest = stack->value;
	while (stack)
	{
		if (stack->value > highest)
			highest = stack->value;
		stack = stack->next;
	}
	return (highest);
}

static int	get_lowest_value(t_num *stack)
{
	int		lowest;
	
	lowest = stack->value;
	while (stack)
	{
		if (stack->value < lowest)
			lowest = stack->value;
		stack = stack->next;
	}
	return (lowest);
}

static void	sort_3(t_num **stack_a, t_num **stack_b)
{
	int		highest;
	
	highest = 0;
	if (stack_b)
		highest = get_highest_value(*stack_a);
	if ((*stack_a)->value == highest)
		rotate_a(stack_a);
	else if ((*stack_a)->next->value == highest)
		reverse_rotate_a(stack_a);
	if (!is_sorted(*stack_a))
		swap_a(stack_a);
}

void	sort_5(t_num **stack_a, t_num **stack_b)
{
	t_num *temp;
	int size;
	int lowest;
	int	i;
	
	size = ft_lstsize_stack(*stack_a);
	while (size > 3)
	{
		temp = *stack_a;
		lowest = get_lowest_value(temp);
		i = 0;
		while (temp->value != lowest)
		{
			temp = temp->next;
			i++;
		}
		while ((*stack_a)->value != lowest)
		{
			if (i < size / 2)
				rotate_a(stack_a);
			else
				reverse_rotate_a(stack_a);
		}
		push_b(stack_a, stack_b);
		size = ft_lstsize_stack(*stack_a);
	}
	sort_3(stack_a, stack_b);
	while (*stack_b)
		push_a(stack_a, stack_b);
	if (!is_sorted(*stack_a))
		swap_a(stack_a);
}

void	sort_all(t_num **stack_a, t_num **stack_b)
{
	t_num *temp;
	int size;
	int lowest;
	int	i;
	
	size = ft_lstsize_stack(*stack_a);
	while (size > 1)
	{
		temp = *stack_a;
		lowest = get_lowest_value(temp);
		i = 0;
		while (temp->value != lowest)
		{
			temp = temp->next;
			i++;
		}
		while ((*stack_a)->value != lowest)
		{
			if (i < size / 2)
				rotate_a(stack_a);
			else
				reverse_rotate_a(stack_a);
		}
		push_b(stack_a, stack_b);
		size = ft_lstsize_stack(*stack_a);
	}
	while (*stack_b)
		push_a(stack_a, stack_b);
}

int	find_best_move(t_num **stack_a, t_num **stack_b)
{

}

void	sort_b_till_3(t_num **stack_a, t_num **stack_b)
{
	int		nb;
	t_num	*tmp;

	while (ft_lstsize_stack(*stack_a) > 3)
	{
		tmp = *stack_a;
		nb = find_best_move(stack_a, stack_b);
		do_best_move(stack_a, stack_b, nb);
	}
}
void	sort_all_test(t_num **stack_a, t_num **stack_b)
{
	if (ft_lstsize_stack(*stack_a) > 3)
		push_b(stack_a, stack_b);
	if (ft_lstsize_stack(*stack_a) > 3)
		push_b(stack_a, stack_b);
	if (ft_lstsize_stack(*stack_a) > 3)
		sort_b_till_3(stack_a, stack_b);
	sort_5(stack_a, stack_b); //It will have to be changed to sort_3 when it all works, sort_5 can be deleted
	sort_a_to_b(stack_a, stack_b);
	clean_a(stack_a);
}

void	sort_stack(t_num **stack_a, t_num **stack_b)
{
	int size;

	size = ft_lstsize_stack(*stack_a);
	if (size == 2)
		swap_a(stack_a);
	else if (size >= 3 && size <= 5)
		sort_5(stack_a, stack_b);
	else
		sort_all_test(stack_a, stack_b);
}