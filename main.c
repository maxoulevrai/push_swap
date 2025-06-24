/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:22:33 by root              #+#    #+#             */
/*   Updated: 2025/06/24 16:42:13 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void push_swap(char **av)
{
	t_stack *s_a;
	t_stack *s_b;
//	t_ter *ter;

	s_b = NULL;
	s_a = parse(av);
	if (!s_a)
		return;
	get_idx(&s_a);
	if (is_sorted(&s_a))
	{
		free_dbl_ll(&s_a);
		return;
	}
	opti_b(&s_a, &s_b);
	//ter = get_tertiles()
	opti_a(&s_a, &s_b);
	free_all(&s_a, &s_b);
}


int main(int ac, char **av)
{
	if (ac == 1)
		return (ft_putendl_fd("Error", 2), 0);
	if (!av || !*av)
		return (ft_putendl_fd("Error", 2), 0);
	push_swap(av);
	return (0);
}