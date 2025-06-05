/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:16:38 by maleca            #+#    #+#             */
/*   Updated: 2025/06/05 18:22:21 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	reverse_rotate_a(t_stack **stack_A, int flag)
{
	*stack_A = (*stack_A)->prev;
	if (flag)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **stack_B, int flag)
{
	*stack_B = (*stack_B)->prev;
	if (flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_A, t_stack **stack_B)
{
	rotate_a(&stack_A, 0);
	rotate_a(&stack_B, 0);
	write(1, "rrr\n", 4);
}
