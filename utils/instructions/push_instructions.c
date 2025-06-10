/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 01:04:24 by maleca            #+#    #+#             */
/*   Updated: 2025/06/10 21:18:05 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_a(t_stack **s_a, t_stack **s_b)
{
	t_stack	*p;

	p = (*s_b);
	if (add_to_stack(s_a, *s_b) == -1)
	{
		// free_all(s_a, s_b);
		return ;
	}
	(*s_b)->next->prev = (*s_b)->prev;
	(*s_b)->prev->next = (*s_b)->next;
	(*s_b) = (*s_b)->next;
	write(1, "pa\n", 3);
}

void	push_b(t_stack **s_a, t_stack **s_b)
{
	t_stack	*p;

	p = (*s_a);
	if (add_to_stack(s_b, *s_a) == -1)
	{
		// free_all(s_a, s_b);
		return ;
	}
	(*s_a)->next->prev = (*s_a)->prev;
	(*s_a)->prev->next = (*s_a)->next;
	(*s_a) = (*s_a)->next;
	write(1, "pb\n", 3);
}
