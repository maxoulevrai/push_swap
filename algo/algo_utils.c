/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 19:17:12 by maleca            #+#    #+#             */
/*   Updated: 2025/07/31 20:33:52 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_insert(t_stack **s_a, t_stack **s_b, t_stack *best)
{
	t_mq	*mq_a;
	t_mq	*mq_b;

	mq_a = get_mq(s_a);
	mq_b = get_mq(s_b);
	if (best->pos <= mq_b->med && best->trgt->pos > mq_a->med)
		rra_rb(s_a, s_b, best);
	else if (best->pos > mq_b->med && best->trgt->pos <= mq_a->med)
		ra_rrb(s_a, s_b, best);
	else if (best->pos > mq_b->med && best->trgt->pos > mq_a->med)
		rrrr_neg(s_a, s_b, best);
	else if (best->pos <= mq_b->med && best->trgt->pos <= mq_a->med)
		rrrr_pos(s_a, s_b, best);
	free(mq_a);
	free(mq_b);
}

void	rra_rb(t_stack **s_a, t_stack **s_b, t_stack *best)
{
	if (!s_a || !s_b || !best || !*s_a || !*s_b)
		return ;
	while (best->trgt->value != (*s_a)->prev->value
		&& best->value != (*s_b)->value)
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
	while (best->trgt->value != (*s_a)->prev->value
		&& best->value != (*s_b)->value)
		rrr(s_a, s_b);
	while (best->trgt->value != (*s_a)->prev->value)
		reverse_rotate(s_a, 'A');
	while (best->value != (*s_b)->value)
		reverse_rotate(s_b, 'B');
	if (best->value < best->trgt->value)
		reverse_rotate(s_a, 'A');
	push_a(s_a, s_b);
}
