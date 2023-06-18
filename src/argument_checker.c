/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbosch <fbosch@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:49:21 by fbosch            #+#    #+#             */
/*   Updated: 2023/06/18 17:35:44 by fbosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	compare_numbers(const char *s1, const char *s2)
{
	return (ft_atoi(s1) - ft_atoi(s2));
}

static int	check_int(char *s_num)
{
	long int	result;
	int			sign;

	sign = 1;
	if (*s_num == '+' || *s_num == '-')
	{
		if (*s_num == '-')
			sign *= -1;
		s_num++;
	}
	result = 0;
	while (*s_num >= '0' && *s_num <= '9')
	{
		result = result * 10 + *s_num - '0';
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result > -(long int)INT_MIN))
			return (-1);
		s_num++;
	}
	return (0);
}

static int	check_duplicates(int len, char **argv, int index)
{
	int	j;

	j = index + 1;
	while (j < len)
	{
		if (compare_numbers(argv[index], argv[j]) == 0)
			return (-1);
		j++;
	}
	return (0);
}

static int	check_words(char **words, int len)
{
	int	i;
	int	j;

	i = 0;
	if (len == 0)
		return (-1);
	while (i < len)
	{
		j = 0;
		if (words[i][j] == '+' || words[i][j] == '-')
			j++;
		if (words[i][j] == '\0')
			return (-1);
		while (words[i][j])
		{
			if (words[i][j] >= '0' && words[i][j] <= '9')
				j++;
			else
				return (-1);
		}
		if (check_duplicates(len, words, i) < 0 || check_int(words[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}

int	check_arguments(int argc, char **argv)
{
	char	**words;
	int		len;
	int		status;

	words = NULL;
	len = 0;
	if (argc == 2)
	{
		words = ft_split(argv[1], ' ');
		if (!words)
			return (-1);
		len = 0;
		while (words[len])
			len++;
		status = check_words(words, len);
	}
	else
		status = check_words(++argv, argc - 1);
	free_memory_array_string(words, len);
	if (status < 0)
		return (-1);
	return (0);
}
