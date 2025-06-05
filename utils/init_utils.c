/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 21:48:36 by maleca            #+#    #+#             */
/*   Updated: 2025/06/05 22:08:34 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_idx(t_stack *head)
{
	size_t	idx;
	t_stack	*p;
	t_stack	*g;
	t_stack	*min_node;

	g = head->next;
	min_node = p;
	idx = 0;
	while (g != head)
	{
		p = g;
		while (p != head)
		{
			if (p->content < min_node->content)
				min_node = p;
			p = p->next;	
		}
		min_node->idx = idx;
		g = g->next;
	}
}