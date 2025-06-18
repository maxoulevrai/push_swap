/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:46:55 by maleca            #+#    #+#             */
/*   Updated: 2025/06/18 16:12:00 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void get_tertiles(t_stack **head, t_ter **ter)
{
    t_ter *new_ter;

    if (!head || !*head || !ter)
        return;
    new_ter = malloc(sizeof(t_ter));
    if (!new_ter)
        return;
    new_ter->len = get_dbl_ll_size(head);
    if (new_ter->len % 3 == 0)
        new_ter->t1 = new_ter->len / 3;
    else
        new_ter->t1 = (new_ter->len + 1) / 3;
    new_ter->t2 = new_ter->t1 * 2;
    if (new_ter->len % 2 == 0)
        new_ter->med = new_ter->len / 2;
    else
        new_ter->med = (new_ter->len + 1) / 2;
    *ter = new_ter;
}

void	ft_finguin(t_stack **s_a)
{
	t_stack	*p;
	t_ter	*ter;
	int		i;

	get_tertiles(s_a, &ter);
	if (!ter)
		return ;
	i = 0;
	p = *s_a;
	while (i < get_dbl_ll_size(s_a))
	{
		if (p->pos != i)
			return ;
		p = p->next;
		i++;
	}
	if (is_sorted(s_a, NULL))
		return ;
	while (p->value != 0)
	{
		reverse_rotate(s_a, 'A');
		p = *s_a;
	}
	free(ter);
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
		update_pos(s_a);
		update_pos(s_b);
		get_target(s_a, s_b);
		best_move = find_best_move(s_b);
		if (!best_move || !best_move->trgt)
			break;
		if (best_move->pos > 0 && best_move->trgt->pos < 0)
			rra_rb(s_a, s_b, best_move);
		else if (best_move->pos < 0 && best_move->trgt->pos > 0)
			ra_rrb(s_a, s_b, best_move);
		else
			rrrr(s_a, s_b, best_move);
	}
	ft_finguin(s_a);
}

void	opti_b(t_stack **s_a, t_stack **s_b)
{
	t_ter	*ter;

	get_tertiles(s_a, &ter);
	if (!ter)
		return ;
	while (only_t3(s_a, ter->t2) == 0)
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
	free(ter);
}
