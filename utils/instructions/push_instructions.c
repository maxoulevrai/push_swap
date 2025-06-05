/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 01:04:24 by maleca            #+#    #+#             */
/*   Updated: 2025/06/05 18:13:50 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_a(t_stack *stack_A, t_stack *stack_B)
{
	t_stack	*p;

	if (!stack_B)
		return ;
	p = stack_B;
	stack_B->next->prev = stack_B->next;
	stack_B->prev->next = stack_B->prev;
	stack_B = stack_B->next;
	stack_A->next = p;
	stack_A->prev = p;
	stack_A = p;
	write(1, "pa\n", 3);
}

void	push_b(t_stack *stack_A, t_stack *stack_B)
{
	t_stack	*p;

	if (!stack_A)
		return ;
	p = stack_A;
	stack_A->next->prev = stack_A->next;
	stack_A->prev->next = stack_A->prev;
	stack_A = stack_A->next;
	stack_B->next = p;
	stack_B->prev = p;
	stack_B = p;
	write(1, "pb\n", 3);
}
