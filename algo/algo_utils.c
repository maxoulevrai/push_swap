/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:46:11 by maleca            #+#    #+#             */
/*   Updated: 2025/06/07 19:27:11 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_ter	*set_tertiles(t_stack **head)
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

void	set_target(t_stack **s_a, t_stack **s_b)
{
	t_stack	*p_A;
	t_stack	*p_B;
	int		best;

	p_A = s_a;
	p_B = s_b;
	best = p_A->content;
	while (1)
	{
		p_A = s_a;
		while (1)
		{
			if (p_B->content < p_A->content && best > p_A->content)
				best = p_A->content;
			p_A = p_A->next;
			if (p_A == s_a)
				break ;
		}
		p_B->trgt = best;
		p_B = p_B->next;
		if (p_B == s_b)
			break ;
	}
}

void	get_target_cost(t_stack **s_a, t_stack **s_b)
{
	int		delta_A;
	int		delta_B;
	t_stack	*p_B;

	delta_A = 0;
	delta_B = 0;
	p_B = s_b;
	while (1)
	{
		
	}
}
