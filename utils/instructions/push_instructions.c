/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 01:04:24 by maleca            #+#    #+#             */
/*   Updated: 2025/06/07 19:27:11 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_a(t_stack **s_a, t_stack **s_b)
{
	t_stack	*p;

	if (!(*s_a) || !(*s_b))
		return ;
	p = (*s_b);
	(*s_b)->next->prev = (*s_b)->next;
	(*s_b)->prev->next = (*s_b)->prev;
	(*s_b) = (*s_b)->next;
	(*s_a)->next = p;
	(*s_a)->prev = p;
	(*s_a) = p;
	write(1, "pa\n", 3);
}

void	push_b(t_stack **s_a, t_stack **s_b)
{
	t_stack	*p;

	if (!(*s_a) || !(*s_b))
		return ;
	p = (*s_a);
	(*s_a)->next->prev = (*s_a)->next;
	(*s_a)->prev->next = (*s_a)->prev;
	(*s_a) = (*s_a)->next;
	(*s_b)->next = p;
	(*s_b)->prev = p;
	(*s_b) = p;
	write(1, "pb\n", 3);
}
