/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 21:48:36 by maleca            #+#    #+#             */
/*   Updated: 2025/06/10 22:08:27 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_idx(t_stack **head)
{
	size_t		idx;
	size_t		size;
	t_stack		*tmp;
	t_stack		*min;

	idx = 0;
	size = get_dbl_ll_size(head);
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

	pos = 1;
	p = *head;
	while (1)
	{
		p->pos = pos;
		p = p->next;
		pos++;
		if (p == *head)
			return (head);
	}
}

t_stack	*init_value(char **splited_args)
{
	t_stack	*head;
	t_stack	*tmp;
	size_t	i;
	int 	pos;

	head = NULL;
	pos = get_dtab_len(splited_args);
	i = 0;
	while (splited_args[i])
	{
		tmp = init_node(splited_args[i++]);
		if (!tmp)
		{
			if (head)
				return (stack_clear(&head), NULL);
			return (NULL);
		}
		tmp->pos = pos--;
		dbl_s_addback(&head, tmp);
	}
	tmp->next = head;
	head->prev = tmp;
	return (head);
}
