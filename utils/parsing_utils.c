/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:04:50 by root              #+#    #+#             */
/*   Updated: 2025/07/30 17:11:23 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_dbl(char **splited_args)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (splited_args[i])
	{
		j = i + 1;
		while (splited_args[j])
		{
			if (ft_atoi(splited_args[i]) == ft_atoi(splited_args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_valid(char **av)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] == '+' || av[i][j] == '-')
			{
				if (av[i][j + 1] && !ft_isdigit(av[i][j + 1]))
					return (0);
			}
			if ((!ft_isdigit(av[i][j]) && av[i][j] != 32
				&& av[i][j] != '-' && av[i][j] != '+'))
				return (0);
		}
		if (ft_atoi(av[i]) == 0 && av[i] != 0)
			return (0);
	}
	return (1);
}

static char	**join_n_split(char **av)
{
	size_t	i;
	char	*tmp;
	char	**splited_args;

	tmp = NULL;
	i = 1;
	while (av[i])
	{
		tmp = ft_strjoin(tmp, av[i]);
		if (!tmp)
			return (NULL);
		tmp = ft_strjoin(tmp, " ");
		if (!tmp)
			return (NULL);
		i++;
	}
	splited_args = ft_split(tmp, ' ');
	free(tmp);
	if (!splited_args)
		return (NULL);
	return (splited_args);
}

t_stack	*parse(char **av)
{
	char	**splited_args;
	t_stack	*s_a;

	if (!is_valid(&av[1]))
		return (NULL);
	splited_args = join_n_split(av);
	if (!splited_args)
		return (NULL);
	if (!check_dbl(splited_args))
		return (NULL);
	s_a = init_value(splited_args);
	if (!s_a)
		return (NULL);
	free_dtab(splited_args);
	return (s_a);
}
