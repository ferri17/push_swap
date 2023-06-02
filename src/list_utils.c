/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:21:25 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/02 13:57:27 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_num	*ft_lstnew_stack(int number)
{
	t_num	*lst;

	lst = (t_num *)malloc(sizeof(t_num));
	if (lst == NULL)
		return (NULL);
	lst->value = number;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back_stack(t_num **lst, t_num *new)
{
	t_num	*last_lst;

	if (lst)
	{
		if (*lst)
		{
			last_lst = ft_lstlast_stack(*lst);
			last_lst->next = new;
		}
		else
			*lst = new;
	}
}

t_num	*ft_lstlast_stack(t_num *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstclear_stack(t_num **lst)
{
	t_num	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free(*lst);
			*lst = tmp;
		}
	}
}

int	ft_lstsize_stack(t_num *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
