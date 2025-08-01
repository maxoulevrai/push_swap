/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:36:37 by root              #+#    #+#             */
/*   Updated: 2025/07/31 23:05:56 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/libft.h"

typedef struct s_stack
{
	int				value;
	int				idx;
	int				pos;
	struct s_stack	*trgt;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_mq
{
	int				q1;
	int				q3;
	int				med;
	int				len;
}				t_mq;

// parsing
t_stack	*parse(char **av);

// init
t_stack	*init_value(char **splited_args);
t_stack	**update_pos(t_stack **head);
void	get_idx(t_stack **head);

// linked_list
t_stack	*init_node(int value);
int		get_dbl_ll_size(t_stack **head);
int		add_to_stack(t_stack **head, t_stack *new);
void	free_all(t_stack **s_a, t_stack **s_b);
void	free_dbl_ll(t_stack **head);

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
void	opti_b(t_stack **s_a, t_stack **s_b);
void	opti_a(t_stack **s_a, t_stack **s_b);
void	tiny_sort(t_stack **head, char print);
void	do_opti(t_stack **s_a, t_stack **s_b, t_stack *best, int *len);
void	do_a_move(t_stack **s_a, t_stack *best, int *len);
void	do_b_move(t_stack **s_b, t_stack *best, int *len);
void	get_target(t_stack **s_a, t_stack **s_b);
int		is_sorted(t_stack **head);
int		inter(t_stack **head, t_mq *mq);
int		get_cost(t_stack *p_b, int *len);
t_mq	*get_mq(t_stack **head);
t_stack	*find_best_move(t_stack **s_b, int *len);

void	order(t_stack **s_a);

// debug
void	check_circular(t_stack *head);

#endif