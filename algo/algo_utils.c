/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:46:11 by maleca            #+#    #+#             */
/*   Updated: 2025/06/10 22:14:03 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_tertiles(t_stack **head,t_ter **ter)
{
	t_ter	*new_ter;

	new_ter = malloc(sizeof(t_ter));
	if (!ter)
		return ;
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
	if (*ter)
		free(*ter);
	*ter = new_ter;
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

// void	rra_rb(t_stack *best)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
	
	
// }

// void	ra_rb(t_stack *best)
// {

// }

// void	ft_finguin(t_stack **s_a)
// {

// }

// total_cost 


// if (target->pos > ter->med)
// 	total_cost = ABS(len - target_cost) + pos;
// else
// 	total_cost = ABS(target_cost - pos);


