/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:36:37 by root              #+#    #+#             */
/*   Updated: 2025/06/06 16:43:57 by maleca           ###   ########.fr       */
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
	int				trgt;
	int				trgt_cost;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

// parsing
t_stack	*parse(char **av);

// init
t_stack	*init_value(char **splited_args);
t_stack	*init_node(char *value);
void	get_idx(t_stack **head);

// linked_list
void	stack_clear(t_stack **lst);
void	stack_addback(t_stack **lst, t_stack *new);
size_t	get_dbl_ll_size(t_stack **head);

// instructions
void	push_a(t_stack **stack_A, t_stack **stack_B);
void	push_b(t_stack **stack_A, t_stack **stack_B);

void	swap(t_stack **head, char print);
void	ss(t_stack **stack_A, t_stack **stack_B);

void	rotate(t_stack **head, char print);
void	rr(t_stack **stack_A, t_stack **stack_B);

void	reverse_rotate(t_stack **head, char print);
void	rrr(t_stack **stack_A, t_stack **stack_B);

// algo
void	tiny_sort(t_stack **head, char print);



#endif