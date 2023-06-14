/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:22:37 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/14 21:23:55 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


typedef struct s_number
{
	int					value;
	struct s_number		*next;
}	t_num;

typedef struct s_moves
{
	int	ra;
	int	r_ra;
	int	rb;
	int	r_rb;
	int	rall;
	int	r_rall;
}	t_moves;

int		check_arguments(int argc, char **argv);
void	free_memory_array_string(char **arr, int len);
t_num	*ft_lstnew_stack(int number);
void	ft_lstadd_back_stack(t_num **lst, t_num *new);
t_num	*ft_lstlast_stack(t_num *lst);
int		ft_array_len(char **arr);
void	ft_lstclear_stack(t_num **lst);
int		is_sorted(t_num *stack);
int		init_stacks(t_num **stack_a, int argc, char **argv);
int		is_sorted(t_num *stack);
void	print_stacks(t_num *stack_a, t_num *stack_b);
int		ft_lstsize_stack(t_num *lst);
void	swap_a(t_num **stack_a);
void	swap_b(t_num **stack_b);
void	swap_all(t_num **stack_a, t_num **stack_b);
void	push_a(t_num **stack_a, t_num **stack_b);
void	push_b(t_num **stack_a, t_num **stack_b);
void	rotate_a(t_num **stack_a);
void	rotate_b(t_num **stack_b);
void	rotate_all(t_num **stack_a, t_num **stack_b);
void	reverse_rotate_a(t_num **stack_a);
void	reverse_rotate_b(t_num **stack_b);
void	reverse_rotate_all(t_num **stack_a, t_num **stack_b);
void	exit_error();
void	sort_stack(t_num **stack_a, t_num **stack_b);
void	sort_5(t_num **stack_a, t_num **stack_b);
void	sort_all(t_num **stack_a, t_num **stack_b);


#endif
