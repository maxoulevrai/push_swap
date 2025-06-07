/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:46:55 by maleca            #+#    #+#             */
/*   Updated: 2025/06/07 19:27:11 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	move_a_optimize(t_stack **s_a, t_stack **s_b)
{
	set_target(&s_a, &s_b);
	get_target_cost(&s_a, &s_b);


}

void	move_b_optimize(t_stack **s_a, t_stack **s_b)
{
	t_ter	*ter;

	ter = set_tertiles(&s_a);
	if (!ter)
		return ;
	while (!only_q3(s_a))
	{
		if ((*s_a)->idx < ter->t1)
		{
			push_b(&s_a, &s_b);
			rotate(&s_b, 'B');
		}
		else if (((*s_a)->idx > ter->t2))
			rotate(&s_a, 'A');
		else 
			push_b(&s_a, &s_b);
	}
	while (get_dbl_ll_size(&s_a) > 3)
		push_b(&s_a, &s_b);
	tiny_sort(&s_a, 'A');
	free(ter);
}

void	launch_algo(t_stack **s_a, t_stack **s_b)
{

	move_b_optimize(&s_a, &s_b);
	move_a_optimize(&s_a, &s_b);

}