/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:46:55 by maleca            #+#    #+#             */
/*   Updated: 2025/06/14 04:29:25 by maleca           ###   ########.fr       */
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

int	insert(t_stack *node)
{
	if (node->pos > 0 && node->trgt->pos < 0)
		rra_rb();
	else if (node->pos < 0 && node->trgt->pos > 0)
		ra_rrb();
	else
		rrrr();
}

t_stack	*find_best_move(t_stack **s_a, t_stack **s_b, t_ter **ter)
{
	t_stack *p_b;
	t_stack	*best;
	int		current_cost;
	int		best_cost;

	current_cost = 0;
	best_cost = INT_MAX;
	p_b = *s_b;
	best = *s_b;
	while (1)
	{
		p_b = *s_b;
		current_cost = ABS(p_b->pos - p_b->trgt->pos);
		if (current_cost < best_cost)
		{
			best_cost = current_cost;
			best = p_b;
		}
		p_b = p_b->next;
		if (p_b == *s_b)
			return (free(*ter), best);
	}
}

void	opti_a(t_stack **s_a, t_stack **s_b, t_ter **ter)
{
	t_stack	*best_move;

	while (get_dbl_ll_size(s_b) > 0)
	{
		get_target(update_pos(s_a), update_pos(s_b));
		get_tertiles(s_a, ter);
		best_move = find_best_move(s_a, s_b, ter);
		if (best_move->pos > 0 && best_move->trgt->pos < 0)
			rra_rb(s_a, s_b, best_move);
		else if (best_move->pos < 0 && best_move->trgt->pos > 0)
			ra_rrb(s_a, s_b, best_move);
		else
			rrrr(s_a, s_b, best_move);
	}
	ft_finguin(s_a);
	free_all(s_a, s_b, ter);
}

void	opti_b(t_stack **s_a, t_stack **s_b)
{
	t_ter	*ter;

	get_tertiles(s_a, &ter);
	if (!ter)
		return ;
	while (!only_t3(s_a, ter->t2))
	{
		if ((*s_a)->idx < ter->t1)
		{
			push_b(s_a, s_b);
			rotate(s_b, 'B');
		}
		else if (((*s_a)->idx > ter->t2))
			rotate(s_a, 'A');
		else 
			push_b(s_a, s_b);
	}
	while (get_dbl_ll_size(s_a) > 3)
		push_b(s_a, s_b);
	if (!is_sorted(s_a, ter))
		tiny_sort(s_a, 'A');
	move_a_optimize(s_a, s_b, &ter);
}
