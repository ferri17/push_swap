/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:03:13 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/15 19:18:15 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	find_best_move(t_num *stack_a, t_num *stack_b, t_moves *move)
{
	t_num	*temp_stack;
	int		best_nb;
	int		n_moves;
	int		temp;

	temp_stack = stack_a;
	n_moves = INT_MAX;
	while (temp_stack)
	{
		temp = calculate_moves(stack_a, stack_b, temp_stack->value, move);
		if (temp < n_moves)
		{
			n_moves = temp;
			best_nb = temp_stack->value;
		}
		temp_stack = temp_stack->next;
	}
	return (best_nb);
}

void	optimise_moves(t_moves *move)
{
	if (move->ra > move->rb)
	{
		move->rall = move->rb;
		move->ra -= move->rb;
		move->rb = 0;
	}
	else
	{
		move->rall = move->ra;
		move->rb -= move->ra;
		move->ra = 0;
	}
	if (move->r_ra > move->r_rb)
	{
		move->r_rall = move->r_rb;
		move->r_ra -= move->r_rb;
		move->r_rb = 0;
	}
	else
	{
		move->r_rall = move->r_ra;
		move->r_rb -= move->r_ra;
		move->r_ra = 0;
	}
}

int	calculate_moves(t_num *stack_a, t_num *stack_b, int nb, t_moves *move)
{
	int	i_target;
	int	i_nb;
	int	total;
	int	size_stack_a;
	int	size_stack_b;

	init_moves(move);
	size_stack_a = ft_lstsize_stack(stack_a);
	size_stack_b = ft_lstsize_stack(stack_b);
	i_target = find_target_smaller(stack_b, nb);
	i_nb = find_index(stack_a, nb);
	if (i_nb <= size_stack_a / 2)
		move->ra = i_nb;
	else
		move->r_ra = size_stack_a - i_nb;
	if (i_target <= size_stack_b / 2)
	{
		move->rb = i_target;
	}
	else
		move->r_rb = size_stack_b - i_target;
	optimise_moves(move);
	total = move->ra + move->r_ra + move->rb + move->r_rb + move->rall
		+ move->r_rall;
	return (total);
}

void	do_best_move(t_num **stack_a, t_num **stack_b, t_moves *move)
{
	while (move->ra--)
		rotate_a(stack_a);
	while (move->r_ra--)
		reverse_rotate_a(stack_a);
	while (move->rb--)
		rotate_b(stack_b);
	while (move->r_rb--)
		reverse_rotate_b(stack_b);
	while (move->rall--)
		rotate_all(stack_a, stack_b);
	while (move->r_rall--)
		reverse_rotate_all(stack_a, stack_b);
	push_b(stack_a, stack_b);
}
