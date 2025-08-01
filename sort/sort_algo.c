/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:15:43 by maleca            #+#    #+#             */
/*   Updated: 2025/08/01 04:53:33 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_cost(t_stack *p_b, int *len)
{
	int	cost;

	cost = p_b->pos;
	if (p_b->pos > len[1] / 2)
		cost = len[1] - p_b->pos;
	if (p_b->trgt->pos <= len[0] / 2)
		cost += p_b->trgt->pos;
	else
		cost += len[0] - p_b->trgt->pos;
	return (cost);
}

static t_stack	*find_best_move(t_stack **s_b, int *len)
{
	t_stack	*p_b;
	t_stack	*best;
	int		current_cost;
	int		best_cost;

	if (!s_b || !*s_b)
		return (NULL);
	current_cost = 0;
	best_cost = INT_MAX;
	p_b = *s_b;
	best = *s_b;
	while (1)
	{
		current_cost = get_cost(p_b, len);
		if (current_cost < best_cost)
		{
			best_cost = current_cost;
			best = p_b;
		}
		p_b = p_b->next;
		if (p_b == *s_b)
			return (best);
	}
}

void	move_to_a(t_stack **s_a, t_stack **s_b)
{
	t_stack	*best;
	int		len[2];

	if (!s_a || !*s_a || !s_b || !*s_b)
		return ;
	while (get_dbl_ll_size(s_b) > 0)
	{
		get_target(update_pos(s_a), update_pos(s_b));
		len[0] = get_dbl_ll_size(s_a);
		len[1] = get_dbl_ll_size(s_b);
		best = find_best_move(s_b, len);
		if (!best || !best->trgt)
			break ;
		do_opti(s_a, s_b, best, len);
		do_a_move(s_a, best, len);
		do_b_move(s_b, best, len);
		push_a(s_a, s_b);
	}
	update_pos(s_a);
}

void	move_to_b(t_stack **s_a, t_stack **s_b)
{
	t_mq	*mq;

	mq = get_mq(s_a);
	if (!mq)
		return ;
	while (inter(s_a, mq) && get_dbl_ll_size(s_a) > 12)
	{
		if ((*s_a)->idx >= mq->q1 && (*s_a)->idx <= mq->med)
		{
			push_b(s_a, s_b);
			rotate(s_b, 'B');
		}
		else if ((*s_a)->idx <= mq->q3 && (*s_a)->idx >= mq->med)
			push_b(s_a, s_b);
		else
			rotate(s_a, 'A');
	}
	while (get_dbl_ll_size(s_a) > 3)
	{
		push_b(s_a, s_b);
		if ((*s_b)->idx < mq->med)
			rotate(s_b, 'B');
	}
	free(mq);
}

void	order(t_stack **s_a)
{
	t_stack	*p_a;
	int		len;

	p_a = *s_a;
	while (p_a->idx != 1)
		p_a = p_a->next;
	len = get_dbl_ll_size(s_a);
	if (p_a->pos <= len / 2)
	{
		while (p_a->value != (*s_a)->value)
			rotate(s_a, 'A');
	}
	else
	{
		while (p_a->value != (*s_a)->value)
			reverse_rotate(s_a, 'A');
	}
}
