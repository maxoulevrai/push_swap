/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:00:20 by maleca            #+#    #+#             */
/*   Updated: 2025/05/30 01:03:58 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack **stack_A, int flag)
{
	int	tmp;

	tmp = (*stack_A)->content;
	(*stack_A)->content =  (*stack_A)->next->content;
	(*stack_A)->next->content = tmp;
	if (flag)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack **stack_B, int flag)
{
	int	tmp;

	tmp = (*stack_B)->content;
	(*stack_B)->content =  (*stack_B)->next->content;
	(*stack_B)->next->content = tmp;
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_A, t_stack **stack_B)
{
	swap_a(stack_A, 0);
	swap_b(stack_B, 0);
	write(1, "ss\n", 3);
}
