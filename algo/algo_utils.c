/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:46:11 by maleca            #+#    #+#             */
/*   Updated: 2025/06/16 03:12:56 by maleca           ###   ########.fr       */
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

void	get_target(t_stack **s_a, t_stack **s_b)
{
	t_stack	*p_a;
	t_stack	*p_b;
	t_stack	*best;

	p_b = *s_b;
	best = *s_a;
	while (1)
	{
		p_a = *s_a;
		while (1)
		{
			if (p_b->value < p_a->value && best->value > p_a->value)
				best = p_a;
			p_a = p_a->next;
			if (p_a == (*s_a))
				break ;
		}
		p_b->trgt = best;
		p_b = p_b->next;
		if (p_b == (*s_b))
			break ;
	}
}

void	rra_rb(t_stack **s_a, t_stack **s_b, t_stack *best)
{
	while (best->trgt->pos != 1)
	{
		reverse_rotate(s_a, 'A');
		best->trgt->pos++;
	}
	while (best->pos != 1)
	{
		rotate(s_b, 'B');
		best->trgt->pos--;
	}
	push_a(s_a, s_b);
}

void	ra_rrb(t_stack **s_a, t_stack **s_b, t_stack *best)
{
	while (best->trgt->pos != 1 && best->pos != 1)
	{
		reverse_rotate(s_b, 'B');
		rotate(s_a, 'A');
		best->trgt->pos++;
		best->pos--;
	}
	while (best->trgt->pos != 1)
	{
		reverse_rotate(s_b, 'B');
		best->trgt->pos++;
	}
	while (best->pos != 1)
	{
		rotate(s_a, 'A');
		best->pos--;
	}
	push_a(s_a, s_b);
}

void	rrrr(t_stack **s_a, t_stack **s_b, t_stack *best)
{
	while (best->trgt->pos != 1 && best->pos != 1)
	{
		rotate(s_a, 'A');
		reverse_rotate(s_b, 'B');
		best->trgt->pos--;
		best->pos++;
	}
	while (best->trgt->pos != 1)
	{
		rotate(s_a, 'A');
		best->trgt->pos--;
	}
	while (best->pos != 1)
	{
		reverse_rotate(s_b, 'B');
		best->pos++;
	}
	push_a(s_a, s_b);
}

