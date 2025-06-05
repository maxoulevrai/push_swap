/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tester.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:29:35 by maleca            #+#    #+#             */
/*   Updated: 2025/05/26 22:27:24 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_dbl(char **splited_args)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (splited_args[i])
	{
		j = i + 1;
		while (splited_args[j])
		{
			if (!strcmp(splited_args[i], splited_args[j]))
				return (0);
			j++;
		}
		i++;
	}

	return (1);
}

void	stack_clear(t_stack **lst)
{
	t_stack	*tmp;

	while ((*lst))
	{
		tmp = (*lst)->next;
		free((*lst));
		(*lst) = tmp;
	}
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
		if (ft_atoi(av[i]) == 0 && *av[i] != 0)
			return (0);
	}
	if (!check_dbl(&av[1]))
		return (0);
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

void	stack_addback(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!*lst && !new)
		return ;
	if (!*lst)
	{
		(*lst) = new;
		return ;
	}
	tmp = (*lst);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_stack	*init(char **splited_args)
{
	t_stack	*head;
	t_stack	*tmp;
	size_t	i;

	head = NULL;
	i = 0;
	while (splited_args[i])
	{
		tmp = malloc(sizeof(t_stack));
		if (!tmp)
		{
			if (head)
				return (stack_clear(&head), NULL);
			return (NULL);
		}
		tmp->content = ft_atoi(splited_args[i++]);
		tmp->next = NULL;
		stack_addback(&head, tmp);
	}
	return (head);
}

t_stack	*parse(char **av)
{
	char	**splited_args;
	t_stack	*stack_A;
	size_t	i;

	if (!is_valid(&av[1]))
		return (NULL);
	i = 0;
	splited_args = join_n_split(av);
	if (!splited_args)
		return (NULL);
	stack_A = init(splited_args);
	if (!stack_A)
		return (NULL);
	free_dtab(splited_args);
	return (stack_A);
}

int	main(int ac, char **av)
{
	t_stack	*stack_A;
	t_stack	*tmp;

	if (ac == 1)
		return (ft_putendl_fd("Error (too few arguments)", 2), 0);
	stack_A = parse(av);
	tmp = stack_A;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	// tmp = stack_A;
	// while (tmp != NULL)
	// {
	// 	tmp->content += 1;
	// 	tmp = tmp->next;
	// }
	// tmp = stack_A;
	// while (tmp != NULL)
	// {
	// 	printf("%d\n", tmp->content);
	// 	tmp = tmp->next;
	// }
	stack_clear(&stack_A);
	return (0);
	// if (!args)
	// 	return (ft_putendl_fd("Error", 2), 0);
}
