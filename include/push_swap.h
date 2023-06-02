/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:22:37 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/02 14:24:27 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_number
{
	int					value;
	struct s_number		*next;
}	t_num;

int			check_arguments(int argc, char **argv);
void		free_memory_array_string(char **arr, int len);
t_num		*ft_lstnew_stack(int number);
void		ft_lstadd_back_stack(t_num **lst, t_num *new);
t_num		*ft_lstlast_stack(t_num *lst);
int			ft_array_len(char **arr);
void		ft_lstclear_stack(t_num **lst);
int			is_sorted(t_num *stack);
int			init_stacks(t_num **stack_a, t_num **stack_b, int argc, char **argv);
int			is_sorted(t_num *stack);
void		print_stacks(t_num *stack_a, t_num *stack_b);
int			ft_lstsize_stack(t_num *lst);
void		swap_a(t_num **stack_a);
void		swap_b(t_num **stack_a);

#endif