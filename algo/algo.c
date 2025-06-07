/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:46:55 by maleca            #+#    #+#             */
/*   Updated: 2025/06/08 00:06:05 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_best_move(t_stack **s_a, t_stack **s_b)
{
	t_stack *p_b;
	t_stack	*min;

	get_target(&s_a, &s_b);
	get_target_cost(&s_a, &s_b);
	p_b = *s_b;
	min = *s_b;
	while (1)
	{
		if (p_b->trgt_cost < min->trgt_cost)
			min = p_b;
		p_b = p_b->next;
		if (p_b == s_b)
			break ;
	}
	return (min);
}

void	move_a_optimize(t_stack **s_a, t_stack **s_b)
{
	find_best_move(&s_a, &s_b);

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