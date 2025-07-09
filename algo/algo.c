/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:15:43 by maleca            #+#    #+#             */
/*   Updated: 2025/07/09 16:29:12 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_ter	*get_tertiles(t_stack **head)
{
	t_ter	*ter;

	if (!head || !*head)
		return (NULL);
	ter = malloc(sizeof(t_ter));
	if (!ter)
		return (NULL);
	ter->len = get_dbl_ll_size(head);
	if (ter->len % 3 == 0)
		ter->t1 = ter->len / 3;
	else
		ter->t1 = (ter->len + 1) / 3;
	ter->t2 = ter->t1 * 2;
	if (ter->len % 2 == 0)
		ter->med = ter->len / 2;
	else
		ter->med = (ter->len + 1) / 2;
	return (ter);
}

void	ft_finguin(t_stack **s_a)
{
	t_stack	*p_a;

	p_a = *s_a;
	while (p_a->idx != 1)
		p_a = p_a->next;
	if (p_a->pos < 0)
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

t_stack	*find_best_move(t_stack **s_b)
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
		current_cost = ABS(p_b->pos - p_b->trgt->pos);
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

void	opti_a(t_stack **s_a, t_stack **s_b)
{
	t_stack	*best_move;

	if (!s_a || !*s_a || !s_b || !*s_b)
		return ;
	while (get_dbl_ll_size(s_b) > 0)
	{
		s_a = update_pos(s_a);
		s_b = update_pos(s_b);
		get_target(s_a, s_b);
		printf("stack A:\n");
		check_circular(*s_a);
		printf("stack b:\n");
		check_circular(*s_b);
		best_move = find_best_move(s_b);
		printf("objet: %d cible: %d\n", best_move->value, best_move->trgt->value);
		if (!best_move || !best_move->trgt)
			break;
		if (best_move->pos > 0 && best_move->trgt->pos < 0)
			rra_rb(s_a, s_b, best_move);
		else if (best_move->pos < 0 && best_move->trgt->pos > 0)
			ra_rrb(s_a, s_b, best_move);
		else if (best_move->pos < 0 && best_move->trgt->pos < 0)
			rrrr_neg(s_a, s_b, best_move);
		else if (best_move->pos > 0 && best_move->trgt->pos > 0)
			rrrr_pos(s_a, s_b, best_move);
	}
	update_pos(s_a);
	if (is_sorted(s_a) && (*s_a)->idx == 1)
		return ;
	ft_finguin(s_a);
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
		else if (((*s_a)->idx > ter->t2))
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
