/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 19:17:12 by maleca            #+#    #+#             */
/*   Updated: 2025/07/08 17:32:21 by maleca           ###   ########.fr       */
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
	if (!s_a || !s_b || !best || !*s_a || !*s_b)
		return ;
	while (best->trgt->value != (*s_a)->prev->value && best->value != (*s_b)->value)
	{
		reverse_rotate(s_a, 'A');
		rotate(s_b, 'B');
	}
	while (best->trgt->value != (*s_a)->prev->value)
		reverse_rotate(s_a, 'A');
	while (best->value != (*s_b)->value)
		rotate(s_b, 'B');
	if (best->value < best->trgt->value)
		reverse_rotate(s_a, 'A');
	push_a(s_a, s_b);
}

void	ra_rrb(t_stack **s_a, t_stack **s_b, t_stack *best)
{
	if (!s_a || !s_b || !best || !*s_a || !*s_b)
		return ;
	while (best->trgt->value != (*s_a)->value && best->value != (*s_b)->value)
	{
		rotate(s_a, 'A');
		reverse_rotate(s_b, 'B');
	}
	while (best->trgt->value != (*s_a)->value)
		rotate(s_a, 'A');
	while (best->value != (*s_b)->value)
		reverse_rotate(s_b, 'B');
	if (best->value > best->trgt->value)
		rotate(s_a, 'A');
	push_a(s_a, s_b);
}

void	rrrr_pos(t_stack **s_a, t_stack **s_b, t_stack *best)
{
	if (!s_a || !s_b || !best || !*s_a || !*s_b)
		return ;
	while (best->trgt->value != (*s_a)->value && best->value != (*s_b)->value)
		rr(s_a, s_b);
	while (best->trgt->value != (*s_a)->value)
		rotate(s_a, 'A');
	while (best->value != (*s_b)->value)
		rotate(s_b, 'B');
	if (best->value > best->trgt->value)
		rotate(s_a, 'A');
	push_a(s_a, s_b);
}

void	rrrr_neg(t_stack **s_a, t_stack **s_b, t_stack *best)
{
	if (!s_a || !s_b || !best || !*s_a || !*s_b)
		return ;
	while (best->trgt->value != (*s_a)->prev->value && best->value != (*s_b)->value)
		rrr(s_a, s_b);
	while (best->trgt->value != (*s_a)->prev->value)
		reverse_rotate(s_a, 'A');
	while (best->value != (*s_b)->value)
		reverse_rotate(s_b, 'B');
	if (best->value < best->trgt->value)
		reverse_rotate(s_a, 'A');
	push_a(s_a, s_b);
}
