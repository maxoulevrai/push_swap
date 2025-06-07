/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:36:37 by root              #+#    #+#             */
/*   Updated: 2025/06/07 23:55:49 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "lib/libft.h"

# define ABS(value) ((value < 0) ? (value * -1) : value)

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


typedef struct s_ter
{
	size_t				t1;
	size_t				t2;
	size_t				len;
	size_t				med;
}				t_ter;

// parsing
t_stack	*parse(char **av);

// init
t_stack	*init_value(char **splited_args);
t_stack	*init_node(char *value);
void	get_idx(t_stack **head);

// linked_list
void	stack_clear(t_stack **lst);
void	s_addback(t_stack **lst, t_stack *new);
size_t	get_dbl_ll_size(t_stack **head);

// instructions
void	push_a(t_stack **s_a, t_stack **s_b);
void	push_b(t_stack **s_a, t_stack **s_b);

void	swap(t_stack **head, char print);
void	ss(t_stack **s_a, t_stack **s_b);

void	rotate(t_stack **head, char print);
void	rr(t_stack **s_a, t_stack **s_b);

void	reverse_rotate(t_stack **head, char print);
void	rrr(t_stack **s_a, t_stack **s_b);

// algo
void	tiny_sort(t_stack **head, char print);



#endif