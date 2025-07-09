/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:04:16 by maleca            #+#    #+#             */
/*   Updated: 2025/07/09 16:41:26 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

t_ter	*get_tertiles(t_stack **head)
{
	t_ter	*ter;

	if (!head || !*head)
		return (NULL);
	ter = malloc(sizeof(t_ter));
	if (!ter)
		return (NULL);
	ter->len = get_dbl_ll_size(head);
	if (ter->len % 3 == 0)
		ter->t1 = ter->len / 3;
	else
		ter->t1 = (ter->len + 1) / 3;
	ter->t2 = ter->t1 * 2;
	if (ter->len % 2 == 0)
		ter->med = ter->len / 2;
	else
		ter->med = (ter->len + 1) / 2;
	return (ter);
}

void	get_idx(t_stack **head)
{
	size_t		idx;
	size_t		size;
	t_stack		*tmp;
	t_stack		*min;

	if (!head || !*head)
		return ;
	size = get_dbl_ll_size(head);
	idx = 1;
	while (idx < size)
	{
		tmp = *head;
		min = NULL;
		while (1)
		{
			if (tmp->idx == -1 && (!min || tmp->value < min->value))
				min = tmp;
			tmp = tmp->next;
			if (tmp == *head)
				break ;
		}
		if (min)
			min->idx = idx++;
	}
}

void	get_target(t_stack **s_a, t_stack **s_b)
{
	t_stack	*p_a;
	t_stack	*p_b;
	t_stack	*best;

	p_b = *s_b;
	best = *s_a;
	while (1)
	{
		p_a = *s_a;
		while (1)
		{
			if (p_b->value > p_a->value && best->value < p_a->value)
				best = p_a;
			p_a = p_a->next;
			if (p_a == (*s_a))
				break ;
		}
		p_b->trgt = best;
		p_b = p_b->next;
		if (p_b == (*s_b))
			break ;
	}
}

t_stack	**update_pos(t_stack **head)
{
	int		pos;
	t_stack	*p;
	t_ter	*ter;

	if (!head || !*head)
		return (NULL);
	ter = get_tertiles(head);
	if (!ter)
		return (NULL);
	pos = 1;
	p = *head;
	while (1)
	{
		p->pos = pos;
		pos++;
		p = p->next;
		if (p == *head)
			return (free(ter), head);
	}
}

t_stack	*init_value(char **splited_args)
{
	t_stack	*head;
	t_stack	*tmp;
	size_t	i;
	int		pos;

	pos = 0;
	head = NULL;
	while (splited_args[pos])
		pos++;
	i = 0;
	while (splited_args[i])
	{
		tmp = init_node(ft_atoi(splited_args[i++]));
		if (!tmp)
			return (free_dbl_ll(&head), NULL);
		tmp->pos = pos--;
		if (add_to_stack(&head, tmp) > 0)
			return (free_dbl_ll(&head), free(tmp), NULL);
	}
	if (head && tmp)
	{
		tmp->next = head;
		head->prev = tmp;
	}
	return (head);
}
