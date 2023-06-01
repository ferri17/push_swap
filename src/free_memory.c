/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:50:29 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/01 11:54:53 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_memory_array_string(char **arr, int len)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free (arr);
}
