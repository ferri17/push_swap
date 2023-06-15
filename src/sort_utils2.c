/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:14:11 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/15 19:18:22 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	find_index(t_num *stack, int nb)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->value == nb)
			return (index);
		index++;
		stack = stack->next;
	}
	return (-1);
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
