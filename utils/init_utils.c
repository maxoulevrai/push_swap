/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 04:08:49 by maleca            #+#    #+#             */
/*   Updated: 2025/06/17 16:33:30 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void	get_idx(t_stack **head)
{
	size_t		idx;
	size_t		size;
	t_stack		*tmp;
	t_stack		*min;

	if (!head || !*head)
		return;
	size = get_dbl_ll_size(head);
	if (size == 0)
		return;
	idx = 0;
	while (idx < size)
	{
		tmp = *head;
		min = NULL;
		while (1)
		{
			if (tmp->idx == -1)
			{
				if (!min || tmp->value < min->value)
					min = tmp;
			}
			tmp = tmp->next;
			if (tmp == *head)
				break;
		}
		if (min)
			min->idx = idx++;
	}
}
t_stack	**update_pos(t_stack **head)
{
	int		pos;
	t_stack	*p;
	t_ter	*ter;

	if (!head || !*head)
		return (NULL);
	get_tertiles(head, &ter);
	pos = 1;
	p = *head;
	while (1)
	{
		p->pos = pos;
		if (pos == ter->med)
			pos *= -1;
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
