/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:09:19 by maleca            #+#    #+#             */
/*   Updated: 2025/07/30 03:32:20 by root             ###   ########.fr       */
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

void	rr(t_stack **s_a, t_stack **s_b)
{
	rotate(s_a, 0);
	rotate(s_b, 0);
	write(1, "rr\n", 3);
}
