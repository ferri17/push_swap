/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:23:06 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/02 17:18:57 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_array_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	init_stacks(t_num **stack_a, t_num **stack_b, int argc, char **argv)
{
	char	**num_array;
	t_num	*new;
	int		i;

	*stack_b = NULL;
	if (argc == 2)
	{
		num_array = ft_split(argv[1], ' ');
		if (!num_array)
			return (-1);
	}
	else
		num_array = argv + 1;
	i = 0;
	while (num_array[i])
	{
		new = ft_lstnew_stack(ft_atoi(num_array[i]));
		if (!new)
			return (-1);
		ft_lstadd_back_stack(stack_a, new);
		i++;
	}
	if (argc == 2)
		free_memory_array_string(num_array, ft_array_len(num_array));
	return (0);
}

int	is_sorted(t_num *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->value < stack->next->value)
			stack = stack->next;
		else
			return (-1);
	}
	return (0);
}

void	print_stacks(t_num *stack_a, t_num *stack_b)
{
	ft_printf("--Stack A--\n");
	while (stack_a)
	{
		ft_printf("%i\n", stack_a->value);
		stack_a = stack_a->next;
	}
	ft_printf("-----------------\n");
	ft_printf("--Stack B--\n");
	while (stack_b)
	{
		ft_printf("%i\n", stack_b->value);
		stack_b = stack_b->next;
	}
	ft_printf("\n################\n");
}
