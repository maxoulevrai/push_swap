/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 19:17:12 by maleca            #+#    #+#             */
/*   Updated: 2025/08/01 03:33:53 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_opti(t_stack **s_a, t_stack **s_b, t_stack *best, int *len)
{
	if (best->pos <= len[1] / 2 && best->trgt->pos <= len[0] / 2)
	{
		while (*s_b != best && *s_a != best->trgt)
			rr(s_a, s_b);
	}
	else if (best->pos > len[1] / 2 && best->trgt->pos > len[0] / 2)
	{
		while (*s_b != best && (*s_a)->prev != best->trgt)
			rrr(s_a, s_b);
	}
}

void	do_a_move(t_stack **s_a, t_stack *best, int *len)
{
	if (best->trgt->pos <= len[0] / 2)
	{
		while (*s_a != best->trgt)
			rotate(s_a, 'A');
		if (best->value > best->trgt->value)
			rotate(s_a, 'A');
	}
	else if (best->trgt->pos > len[0] / 2)
	{
		while ((*s_a)->prev != best->trgt)
			reverse_rotate(s_a, 'A');
		if (best->value < best->trgt->value)
			reverse_rotate(s_a, 'A');
	}
}

void	do_b_move(t_stack **s_b, t_stack *best, int *len)
{
	if (best->pos <= len[1] / 2)
	{
		while (*s_b != best)
			rotate(s_b, 'B');
	}
	else if (best->pos > len[1] / 2)
	{
		while (*s_b != best)
			reverse_rotate(s_b, 'B');
	}
}

int	is_sorted(t_stack **head)
{
	t_stack	*p;

	p = (*head);
	while (1)
	{
		if (p->value > p->next->value && p->next != (*head))
			return (0);
		p = p->next;
		if (p == *head)
			break ;
	}
	return (1);
}

int	inter(t_stack **head, t_mq *mq)
{
	t_stack	*p;

	p = (*head);
	while (1)
	{
		if (p->idx >= mq->q1 && p->idx <= mq->q3)
			return (1);
		p = p->next;
		if (p == (*head))
			return (0);
	}
}
