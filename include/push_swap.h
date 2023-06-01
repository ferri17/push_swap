/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:22:37 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/01 11:54:47 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_numbers
{
	int					value;
	struct s_numbers	*next;
}	t_numbers;

int		check_arguments(int argc, char **argv);
void	free_memory_array_string(char **arr, int len);

#endif
