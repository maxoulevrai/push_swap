/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:09:19 by maleca            #+#    #+#             */
/*   Updated: 2025/06/06 18:46:49 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate(t_stack **head, char print)
{
	if (!(*head) || !(*head)->next)
		return ;
	*head = (*head)->next;
	if (print == 'A')
		write(1, "ra\n", 3);
	if (print == 'B')
		write(1, "rb\n", 3);
}


void	rr(t_stack **stack_A, t_stack **stack_B)
{
	rotate(stack_A, 0);
	rotate(stack_B, 0);
	write(1, "rr\n", 3);
}
