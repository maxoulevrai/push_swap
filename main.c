/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:33:02 by maleca            #+#    #+#             */
/*   Updated: 2025/07/31 20:30:00 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char **av)
{
	t_stack	*s_a;
	t_stack	*s_b;

	s_b = NULL;
	s_a = parse(av);
	if (!s_a)
	{
		ft_putendl_fd("Error", 2);
		return ;
	}
	get_idx(&s_a);
	if (is_sorted(&s_a))
	{
		free_dbl_ll(&s_a);
		return ;
	}
	opti_b(&s_a, &s_b);
	if (!is_sorted(&s_a))
		tiny_sort(&s_a, 'A');
	opti_a(&s_a, &s_b);
	if (is_sorted(update_pos(&s_a)) && s_a->idx == 1)
		return (free_all(&s_a, &s_b));
	order(&s_a);
	free_all(&s_a, &s_b);
}

int	main(int ac, char **av)
{
	if (ac == 1 || (av[1][0] == 0 && ac == 2))
		return (0);
	if (!av || !*av)
		return (ft_putendl_fd("Error", 2), 1);
	push_swap(av);
	return (0);
}
