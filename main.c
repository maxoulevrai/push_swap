/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:22:33 by root              #+#    #+#             */
/*   Updated: 2025/06/07 19:27:11 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*push_swap(char **av)
{
	t_stack	*s_a;
	t_stack	*s_b;

	s_a = parse(av);
	if (!s_a)
		return (NULL);
	get_idx(&s_a);
	launch_algo(s_a, s_b);

}


int	main(int ac, char **av)
{
	t_stack	*s_a;
	t_stack	*tmp;

	if (ac == 1)
		return (ft_putendl_fd("Error (too few arguments)", 2), 0);
	s_a = push_swap(av);
	tmp = s_a;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	stack_clear(&s_a);
	return (0);
}
