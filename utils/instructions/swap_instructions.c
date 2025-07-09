/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:00:20 by maleca            #+#    #+#             */
/*   Updated: 2025/07/07 20:42:17 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap(t_stack **head, char print)
{
	t_stack	*p;

	if (!(*head) || !(*head)->next)
		return ;
	p = (*head)->next;
	(*head)->next->next->prev = *head;
	(*head)->prev->next = p;
	(*head)->next = p->next;
	p->prev = (*head)->prev;
	p->next = (*head);
	(*head)->prev = p;
	(*head) = p;
	if (print == 'A')
		write(1, "sa\n", 3);
	else if (print == 'B')
		write(1, "sb\n", 3);
}

void	ss(t_stack **s_a, t_stack **s_b)
{
	swap(s_a, 0);
	swap(s_b, 0);
	write(1, "ss\n", 3);
}
