/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:16:38 by maleca            #+#    #+#             */
/*   Updated: 2025/06/12 23:27:29 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	reverse_rotate(t_stack **head, char print)
{
	if (!(*head) || !(*head)->prev)
		return ;
	*head = (*head)->prev;
	if (print == 'A')
		write(1, "rra\n", 4);
	if (print == 'B')
		write(1, "rrb\n", 4);
}


void	rrr(t_stack **s_a, t_stack **s_b)
{
	reverse_rotate(s_a, 0);
	reverse_rotate(s_b, 0);
	write(1, "rrr\n", 4);
}
