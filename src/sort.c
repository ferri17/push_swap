/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:42:29 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/14 22:26:22 by fbosch           ###   ########.fr       */
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

static void	sort_3(t_num **stack_a)
{
	int		highest;
	
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
	sort_3(stack_a);
	while (*stack_b)
		push_a(stack_a, stack_b);
	if (!is_sorted(*stack_a))
		swap_a(stack_a);
}

/* void	sort_all(t_num **stack_a, t_num **stack_b)
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
} */

int	find_index(t_num *stack, int nb)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->value == nb)
		{
			//ft_printf("INDEX FOUND -> %i\n", index);
			return (index);
		}
		index++;
		stack = stack->next;
	}
	return (-1);
}

int	find_target(t_num *stack, int nb)
{
	int	target;
	int index;
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
	return(index_target);
}

void	init_moves(t_moves *move)
{
	move->ra = 0;
	move->r_ra = 0;
	move->rb = 0;
	move->r_rb = 0;
	move->rall = 0;
	move->r_rall = 0;
}

int	calculate_moves(t_num *stack_a, t_num *stack_b, int nb)
{
	t_moves move;
	int		i_target;
	int		i_nb;

	init_moves(&move);
	i_target = find_target(stack_b, nb);
	i_nb = find_index(stack_a, nb);
	//print_stacks(stack_a, stack_b);
	ft_printf("\n\n\n------------------- NB -> %i || INDEX NB -> %i || INDEX TARGET -> %i\n\n\n", nb, i_nb, i_target);
	if (i_nb <= ft_lstsize_stack(stack_a)/2)
		move.ra = i_nb;
	else
		move.r_ra = ft_lstsize_stack(stack_a) - i_nb;
	if (i_target <= ft_lstsize_stack(stack_b)/2)
		move.rb = i_target;
	else
		move.r_rb = ft_lstsize_stack(stack_b) - i_target;
	if (move.ra > move.rb)
	{
		move.rall = move.rb;
		move.ra -= move.rb;
		move.rb = 0;
	}
	else
	{
		move.rall = move.ra;
		move.rb -= move.ra;
		move.ra = 0;
	}
	if (move.r_ra > move.r_rb)
	{
		move.r_rall = move.r_rb;
		move.r_ra -= move.r_rb;
		move.r_rb = 0;
	}
	else
	{
		move.r_rall = move.r_ra;
		move.r_rb -= move.r_ra;
		move.r_ra = 0;
	}
	ft_printf("NUMBER OF MOVES %i\n", nb);
	ft_printf("-RA: %i\n", move.ra);
	ft_printf("-RB: %i\n", move.rb);
	ft_printf("-R_RA: %i\n", move.r_ra);
	ft_printf("-R_RB: %i\n", move.r_rb);
	ft_printf("-RALL: %i\n", move.rall);
	ft_printf("-R_RALL: %i\n\n", move.r_rall);
	int total = move.ra + move.r_ra + move.rb + move.r_rb + move.rall + move.r_rall;
	return (total);
}

int	find_best_move(t_num *stack_a, t_num *stack_b)
{
	t_num	*temp_stack;
	int		best_nb;
	int		moves;
	int		temp;

	temp_stack = stack_a;
	moves = INT_MAX;
	while (temp_stack)
	{
		temp = calculate_moves(stack_a, stack_b, temp_stack->value);
		ft_printf("TOTAL NUMBER OF MOVES %i -> %i\n\n\n\n", temp_stack->value, temp);
		if (temp < moves)
		{
			moves = temp;
			best_nb = temp_stack->value;
		}
		temp_stack = temp_stack->next;
	}
	ft_printf("---BEST MOVE NUMBER -> %i---\n", best_nb);
	return (best_nb);
}

void	sort_b_till_3(t_num **stack_a, t_num **stack_b)
{
	int		nb;

	nb = find_best_move(*stack_a, *stack_b);
	/* while (ft_lstsize_stack(*stack_a) > 3)
	{
		nb = find_best_move(*stack_a, *stack_b);
		//do_best_move(stack_a, stack_b, nb);
	} */
}
void	sort_all_test(t_num **stack_a, t_num **stack_b)
{
	if (ft_lstsize_stack(*stack_a) > 3)
		push_b(stack_a, stack_b);
	if (ft_lstsize_stack(*stack_a) > 3)
		push_b(stack_a, stack_b);
	if (ft_lstsize_stack(*stack_a) > 3)
		sort_b_till_3(stack_a, stack_b);
	//sort_3(stack_a);
	//sort_5(stack_a, stack_b); //It will have to be changed to sort_3 when it all works, sort_5 can be deleted
	//sort_a_to_b(stack_a, stack_b);
	//clean_a(stack_a);
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