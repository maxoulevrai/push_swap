/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:15:43 by maleca            #+#    #+#             */
/*   Updated: 2025/07/30 04:09:16 by root             ###   ########.fr       */
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

void	ft_finguin(t_stack **s_a)
{
	t_stack	*p_a;
	t_mq	*mq_a;

	p_a = *s_a;
	while (p_a->idx != 1)
		p_a = p_a->next;
	mq_a = get_mq(s_a);
	if (p_a->pos <= mq_a->med)
	{
		while (p_a->value != (*s_a)->value)
			rotate(s_a, 'A');
	}
	else
	{
		while (p_a->value != (*s_a)->value)
			reverse_rotate(s_a, 'A');
	}
	free(mq_a);
}

t_stack	*find_best_move(t_stack **s_b, t_mq *mq_a, t_mq *mq_b)
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
		current_cost = get_cost(p_b, mq_a, mq_b);
		if (current_cost < best_cost)
		{
			best_cost = current_cost;
			best = p_b;
		}
		p_b = p_b->next;
		if (p_b == *s_b)
			return (free(mq_a), free(mq_b), best);
	}
}

void	opti_a(t_stack **s_a, t_stack **s_b)
{
	t_stack	*best;
	t_mq	*mq_a;
	t_mq	*mq_b;

	if (!s_a || !*s_a || !s_b || !*s_b)
		return ;
	while (get_dbl_ll_size(s_b) > 0)
	{
		get_target(update_pos(s_a), update_pos(s_b));
		mq_a = get_mq(s_a);
		mq_b = get_mq(s_b);
		// printf("stack A:\n");
		// check_circular(*s_a);
		// printf("stack B:\n");
		// check_circular(*s_b);
		best = find_best_move(s_b, mq_a, mq_b);
		// printf("objet: %d cible: %d\n", best->value, best->trgt->value);
		if (!best || !best->trgt)
			break ;
		sort_insert(s_a, s_b, best);
	}
	update_pos(s_a);
}

void	opti_b(t_stack **s_a, t_stack **s_b)
{
	t_mq	*mq;

	mq = get_mq(s_a);
	if (!mq)
		return ;
	while (inter(s_a, mq) && get_dbl_ll_size(s_a) > 10)
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
	if (!is_sorted(s_a))
		tiny_sort(s_a, 'A');
	free(mq);
}
