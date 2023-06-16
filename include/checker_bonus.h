/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:54:45 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/16 17:33:46 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

void	reverse_rotate_a_bonus(t_num **stack_a);
void	reverse_rotate_b_bonus(t_num **stack_b);
void	reverse_rotate_all_bonus(t_num **stack_a, t_num **stack_b);
void	rotate_a_bonus(t_num **stack_a);
void	rotate_b_bonus(t_num **stack_b);
void	rotate_all_bonus(t_num **stack_a, t_num **stack_b);
void	swap_a_bonus(t_num **stack_a);
void	swap_b_bonus(t_num **stack_b);
void	swap_all_bonus(t_num **stack_a, t_num **stack_b);
void	push_a_bonus(t_num **stack_a, t_num **stack_b);
void	push_b_bonus(t_num **stack_a, t_num **stack_b);

#endif
