/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:41:23 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/16 17:36:40 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "checker_bonus.h"

static void	exec_instructions(char *instruct, t_num **stack_a, t_num **stack_b)
{
	if (ft_strcmp(instruct, "sa\n") == 0)
		swap_a_bonus(stack_a);
	else if (ft_strcmp(instruct, "sb\n") == 0)
		swap_b_bonus(stack_b);
	else if (ft_strcmp(instruct, "ss\n") == 0)
		swap_all_bonus(stack_a, stack_b);
	else if (ft_strcmp(instruct, "pa\n") == 0)
		push_a_bonus(stack_a, stack_b);
	else if (ft_strcmp(instruct, "pb\n") == 0)
		push_b_bonus(stack_a, stack_b);
	else if (ft_strcmp(instruct, "ra\n") == 0)
		rotate_a_bonus(stack_a);
	else if (ft_strcmp(instruct, "rb\n") == 0)
		rotate_b_bonus(stack_b);
	else if (ft_strcmp(instruct, "rr\n") == 0)
		rotate_all_bonus(stack_a, stack_b);
	else if (ft_strcmp(instruct, "rra\n") == 0)
		reverse_rotate_a_bonus(stack_a);
	else if (ft_strcmp(instruct, "rrb\n") == 0)
		reverse_rotate_b_bonus(stack_b);
	else if (ft_strcmp(instruct, "rrr\n") == 0)
		reverse_rotate_all_bonus(stack_a, stack_b);
	else
		exit_error();
}

static void	check_instructions(t_num **stack_a, t_num **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (line)
		{
			exec_instructions(line, stack_a, stack_b);
			free (line);
		}
		line = get_next_line(0);
	}
	if (is_sorted(*stack_a) && *stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_num	*stack_a;
	t_num	*stack_b;

	if (argc < 2)
		return (0);
	if (check_arguments(argc, argv) < 0)
		exit_error();
	stack_a = NULL;
	stack_b = NULL;
	if (init_stacks(&stack_a, argc, argv) < 0)
		exit_error();
	check_instructions(&stack_a, &stack_b);
	ft_lstclear_stack(&stack_a);
	ft_lstclear_stack(&stack_b);
	return (0);
}
