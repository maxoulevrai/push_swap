/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:00:20 by maleca            #+#    #+#             */
/*   Updated: 2025/06/09 05:18:25 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap(t_stack **head, char print)
{
	int	tmp;

	if (!(*head) || !(*head)->next)
		return ;
	tmp = (*head)->value;
	(*head)->value =  (*head)->next->value;
	(*head)->next->value = tmp;
	if (print == 'A')
		write(1, "sa\n", 3);
	else if (print == 'B')
		write(1, "sb\n", 3);
}

void	ss(t_stack **s_a, t_stack **s_b)
{
	swap(s_a, 'A');
	swap(s_b, 'B');
	write(1, "ss\n", 3);
}
