/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:09:19 by maleca            #+#    #+#             */
/*   Updated: 2025/06/05 18:18:50 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate_a(t_stack **stack_A, int flag)
{
	*stack_A = (*stack_A)->next;
	if (flag)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack **stack_B, int flag)
{
	*stack_B = (*stack_B)->next;
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_A, t_stack **stack_B)
{
	rotate_a(&stack_A, 0);
	rotate_a(&stack_B, 0);
	write(1, "rr\n", 3);
}
