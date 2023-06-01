/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:21:20 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/01 21:33:42 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	ini_stacks(t_num **stack_a, t_num **stack_b, int argc, char **argv)
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

int	main(int argc, char **argv)
{
	t_num	*stack_a;
	t_num	*stack_b;

	if (argc < 2)
		return (0);
	if (check_arguments(argc, argv) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (ini_stacks(&stack_a, &stack_b, argc, argv) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	/* t_num *temp = stack_a;
	while (stack_a)
	{
		ft_printf("Number: %i\n", temp->value);
		temp = temp->next;
	} */
	ft_lstclear_stack(&stack_a);
	ft_lstclear_stack(&stack_b);
	return (0);
}
