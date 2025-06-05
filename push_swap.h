/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:36:37 by root              #+#    #+#             */
/*   Updated: 2025/06/05 22:09:31 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "lib/libft.h"

typedef struct s_stack
{
	int				content;
	int				idx;
	int				pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

// parsing
t_stack	*parse(char **av);

// init
t_stack	*init_value(char **splited_args);
t_stack	*init_node(int value);
void	get_idx(t_stack *head);

// linked_list
void	stack_clear(t_stack **lst);
void	stack_addback(t_stack **lst, t_stack *new);

// instructions
void	push_a(t_stack *stack_A, t_stack *stack_B);
void	push_b(t_stack *stack_A, t_stack *stack_B);

void	swap_a(t_stack **stack_A, int flag);
void	swap_b(t_stack **stack_B, int flag);
void	ss(t_stack **stack_A, t_stack **stack_B);

void	rotate_a(t_stack **stack_A, int flag);
void	rotate_b(t_stack **stack_B, int flag);
void	rr(t_stack **stack_A, t_stack **stack_B);

void	reverse_rotate_a(t_stack **stack_A, int flag);
void	reverse_rotate_b(t_stack **stack_B, int flag);
void	rrr(t_stack **stack_A, t_stack **stack_B);

#endif