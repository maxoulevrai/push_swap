/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 19:17:12 by maleca            #+#    #+#             */
/*   Updated: 2025/07/28 15:20:37 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		get_cost(t_stack *p_b, t_ter *ter_a, t_ter *ter_b)
{
	int	cost;

	cost = 0;
	if (p_b->pos <= ter_b->med && p_b->trgt->pos <= ter_a->med)
		cost = ABS(p_b->pos - p_b->trgt->pos);
	else if (p_b->pos > ter_b->med && p_b->trgt->pos > ter_a->med)
		cost = ABS((ter_b->len - p_b->pos) - (ter_a->len - p_b->trgt->pos));
	else if (p_b->pos <= ter_b->med && p_b->trgt->pos > ter_a->med)
		cost = p_b->pos + (ter_a->len - p_b->trgt->pos);
	else if (p_b->pos > ter_b->med && p_b->trgt->pos <= ter_a->med)
		cost = (ter_b->len - p_b->pos) + p_b->trgt->pos;
	return (cost);
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
