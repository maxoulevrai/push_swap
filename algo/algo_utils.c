/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:46:11 by maleca            #+#    #+#             */
/*   Updated: 2025/06/08 00:14:16 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_ter	*get_tertiles(t_stack **head)
{
	t_ter	*ter;

	ter = malloc(sizeof(t_ter));
	if (!ter)
		return (NULL);
	ter->len = get_dbl_ll_size(&head);
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

int		only_t3(t_stack **head, size_t t2)
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
	int		best;

	p_a = s_a;
	p_b = s_b;
	best = p_a->content;
	while (1)
	{
		p_a = s_a;
		while (1)
		{
			if (p_b->content < p_a->content && best > p_a->content)
				best = p_a->content;
			p_a = p_a->next;
			if (p_a == s_a)
				break ;
		}
		p_b->trgt = best;
		p_b = p_b->next;
		if (p_b == s_b)
			break ;
	}
}

int		target_pos(t_stack **head, int target)
{
	t_ter	*ter;
	t_stack	*p;

	ter = get_tertiles(&head);
	p = *head;
	while (p->content != target)
		p = p->next;
	if (p->pos > ter->med)
	{
		if (ABS(p->trgt_cost) < ABS(p->pos - ter->len))
			p->trgt_cost = (p->pos - ter->len);
		return (free(ter), p->pos - ter->len);
	}
	p->trgt_cost = p->pos;
	return (free(ter), p->pos);
} 

void	get_target_cost(t_stack **s_a, t_stack **s_b)
{
	int		trgt_pos;
	t_stack	*p_b;

	p_b = *s_b;
	update_pos(&s_a);
	update_pos(&s_b);
	while (1)
	{
		trgt_pos = target_pos(&s_a, p_b->trgt);
		if (trgt_pos < 0)
			p_b->trgt_cost = (trgt_pos * (-1)) + p_b->pos;
		else
			p_b->trgt_cost = p_b->pos;
		p_b = p_b->next;
		if (p_b == *s_b)
			return ;
	}
}
