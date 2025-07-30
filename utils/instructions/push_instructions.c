/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:39:39 by maleca            #+#    #+#             */
/*   Updated: 2025/07/30 03:33:59 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_a(t_stack **s_a, t_stack **s_b)
{
	t_stack	*tmp;

	if (!s_a || !s_b || !*s_b)
		return ;
	tmp = *s_b;
	if ((*s_b)->next == *s_b)
		*s_b = NULL;
	else
	{
		(*s_b)->next->prev = (*s_b)->prev;
		(*s_b)->prev->next = (*s_b)->next;
		*s_b = (*s_b)->next;
	}
	tmp->next = NULL;
	tmp->prev = NULL;
	if (add_to_stack(s_a, tmp) == -1)
	{
		free_all(s_a, s_b);
		return ;
	}
	*s_a = (*s_a)->prev;
	write(1, "pa\n", 3);
}

void	push_b(t_stack **s_a, t_stack **s_b)
{
	t_stack	*tmp;

	if (!s_a || !s_b || !*s_a)
		return ;
	tmp = *s_a;
	if ((*s_a)->next == *s_a)
		*s_a = NULL;
	else
	{
		(*s_a)->next->prev = (*s_a)->prev;
		(*s_a)->prev->next = (*s_a)->next;
		*s_a = (*s_a)->next;
	}
	tmp->next = NULL;
	tmp->prev = NULL;
	if (add_to_stack(s_b, tmp) == -1)
	{
		free_all(s_a, s_b);
		return ;
	}
	*s_b = (*s_b)->prev;
	write(1, "pb\n", 3);
}
