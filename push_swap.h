/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:36:37 by root              #+#    #+#             */
/*   Updated: 2025/06/14 00:49:49 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/libft.h"

# define ABS(value) ((value < 0) ? (value * -1) : value)

typedef struct s_stack
{
	int				value;
	int				idx;
	int				pos;
	struct s_stack	*trgt;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;


typedef struct s_ter
{
	int				t1;
	int				t2;
	int				len;
	int				med;
}				t_ter;

// parsing
t_stack	*parse(char **av);

// init
t_stack	*init_value(char **splited_args);
t_stack	**update_pos(t_stack **head);
void	get_idx(t_stack **head);

// linked_list
t_stack	*init_node(char *value);
int		get_dbl_ll_size(t_stack **head);
void	stack_clear(t_stack **lst);
int		add_to_stack(t_stack **head, t_stack *new);
void	free_all(t_stack **s_a, t_stack **s_b, t_ter **ter);

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
void	opti_a(t_stack **s_a, t_stack **s_b, t_ter **ter);
t_stack	*find_best_move(t_stack **s_a, t_stack **s_b, t_ter **ter);
int		only_t3(t_stack **head, int t2);
void	get_tertiles(t_stack **head,t_ter **ter);
void	get_target(t_stack **s_a, t_stack **s_b);
void	tiny_sort(t_stack **head, char print);
int		is_sorted(t_stack **head, t_ter *ter);
void	rra_rb(t_stack *best);
void	ra_rb(t_stack *best);
void	ft_finguin(t_stack **s_a);

#endif