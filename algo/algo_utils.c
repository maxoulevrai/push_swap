/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 19:17:12 by maleca            #+#    #+#             */
/*   Updated: 2025/06/24 17:02:11 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		only_t3(t_stack **head, int t2)
{
	t_stack	*p;

	if (!(*head))
		return (-1);
	p = (*head);
	while (1)
	{
		if (p->idx < t2)
			return (0);
		p = p->next;
		if (p == (*head))
			return (1);
	}
}


void	rra_rb(t_stack **s_a, t_stack **s_b, t_stack *best)
{
	while (best->trgt->pos < 0 && best->pos < 0)
	{
		reverse_rotate(s_a, 'A');
		rotate(s_b, 'B');
		best->trgt->pos++;
		best->pos--;
	}
	while (best->trgt->pos < 0)
	{
		reverse_rotate(s_a, 'A');
		best->trgt->pos++;
	}
	while (best->pos > 0)
	{
		rotate(s_b, 'B');
		best->pos--;
	}
	// if (best->trgt->value < best->value)
	// 	rotate(s_a, 'A');
	push_a(s_a, s_b);
}

void	ra_rrb(t_stack **s_a, t_stack **s_b, t_stack *best)
{
	while (best->trgt->pos > 0 && best->pos < 0)
	{
		reverse_rotate(s_b, 'B');
		rotate(s_a, 'A');
		best->trgt->pos--;
		best->pos++;
	}
	while (best->trgt->pos > 0)
	{
		rotate(s_a, 'A');
		best->trgt->pos--;
	}
	while (best->pos < 0)
	{
		reverse_rotate(s_b, 'B');
		best->pos++;
	}
	push_a(s_a, s_b);
}

void	rrrr_pos(t_stack **s_a, t_stack **s_b, t_stack *best)
{
	if (!s_a || !s_b || !best || !*s_a || !*s_b)
		return ;
	while (best->trgt->pos > -1 && best->pos > 1)
	{
		rotate(s_a, 'A');
		rotate(s_b, 'B');
		best->trgt->pos--;
		best->pos--;
	}
	while (best->trgt->pos > -1)
	{
		rotate(s_a, 'A');
		best->trgt->pos--;
	}
	while (best->pos > 1)
	{
		rotate(s_b, 'B');
		best->pos--;
	}
	push_a(s_a, s_b);
}

void	rrrr_neg(t_stack **s_a, t_stack **s_b, t_stack *best)
{
	if (!s_a || !s_b || !best || !*s_a || !*s_b)
		return ;
	while (best->trgt->pos < -1 && best->pos < 0)
	{
		reverse_rotate(s_a, 'A');
		reverse_rotate(s_b, 'B');
		best->trgt->pos++;
		best->pos++;
	}
	while (best->trgt->pos < -1)
	{
		reverse_rotate(s_a, 'A');
		best->trgt->pos++;
	}
	while (best->pos < 0)
	{
		reverse_rotate(s_b, 'B');
		best->pos++;
	}
	push_a(s_a, s_b);
}
