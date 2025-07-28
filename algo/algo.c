/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:15:43 by maleca            #+#    #+#             */
/*   Updated: 2025/07/28 17:32:40 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_insert(t_stack **s_a, t_stack **s_b, t_stack *best)
{
	t_ter	*ter_a;
	t_ter	*ter_b;

	ter_a = get_tertiles(s_a);
	ter_b = get_tertiles(s_b);
	if (best->pos <= ter_b->med && best->trgt->pos > ter_a->med)
		rra_rb(s_a, s_b, best);
	else if (best->pos > ter_b->med && best->trgt->pos <= ter_a->med)
		ra_rrb(s_a, s_b, best);
	else if (best->pos > ter_b->med && best->trgt->pos > ter_a->med)
		rrrr_neg(s_a, s_b, best);
	else if (best->pos <= ter_b->med && best->trgt->pos <= ter_a->med)
		rrrr_pos(s_a, s_b, best);
	free(ter_a);
	free(ter_b);
}

void	ft_finguin(t_stack **s_a)
{
	t_stack	*p_a;
	t_ter	*ter_a;

	p_a = *s_a;
	while (p_a->idx != 1)
		p_a = p_a->next;
	ter_a = get_tertiles(s_a);
	if (p_a->pos < ter_a->med)
	{
		while (p_a->value != (*s_a)->value)
		{
			reverse_rotate(s_a, 'A');
			p_a->pos++;
		}
	}
	else
	{
		while (p_a->value != (*s_a)->value)
		{
			rotate(s_a, 'A');
			p_a->pos--;
		}
	}
}

t_stack	*find_best_move(t_stack **s_b, t_ter *ter_a, t_ter *ter_b)
{
	t_stack *p_b;
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
		current_cost = get_cost(p_b, ter_a, ter_b);
		if (current_cost < best_cost)
		{
			best_cost = current_cost;
			best = p_b;
		}
		p_b = p_b->next;
		if (p_b == *s_b)
			return (free(ter_a), free(ter_b), best);
	}
}

void	opti_a(t_stack **s_a, t_stack **s_b)
{
	t_stack	*best;
	t_ter	*ter_a;
	t_ter	*ter_b;

	if (!s_a || !*s_a || !s_b || !*s_b)
		return ;
	while (get_dbl_ll_size(s_b) > 0)
	{
		update_pos(s_a);
		update_pos(s_b);
		get_target(s_a, s_b);
		ter_a = get_tertiles(s_a);
		ter_b = get_tertiles(s_b);
		// printf("stack A:\n");
		// check_circular(*s_a);
		// printf("stack B:\n");
		// check_circular(*s_b);
		best = find_best_move(s_b, ter_a, ter_b);
		// printf("objet: %d cible: %d\n", best->value, best->trgt->value);
		if (!best || !best->trgt)
			break;
		sort_insert(s_a, s_b, best);
	}
	if (is_sorted(update_pos(s_a)) && (*s_a)->idx == 1)
		return ;
}

void	opti_b(t_stack **s_a, t_stack **s_b)
{
	t_ter	*ter;

	ter = get_tertiles(s_a);
	if (!ter)
		return ;
	while (only_t3(s_a, ter->t2) == 0 && get_dbl_ll_size(s_a) > 3)
	{
		if ((*s_a)->idx < ter->t1)
		{
			push_b(s_a, s_b);
			rotate(s_b, 'B');
		}
		else if (((*s_a)->idx >= ter->t2))
			rotate(s_a, 'A');
		else
			push_b(s_a, s_b);
	}
	while (get_dbl_ll_size(s_a) > 3)
		push_b(s_a, s_b);
	if (!is_sorted(s_a))
		tiny_sort(s_a, 'A');
	free(ter);
}
