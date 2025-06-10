/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 23:21:15 by maleca            #+#    #+#             */
/*   Updated: 2025/06/10 21:02:16 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_clear(t_stack **head)
{
	t_stack	*tmp;

	while ((*head))
	{
		tmp = (*head)->next;
		free((*head));
		(*head) = tmp;
	}
}

void	dbl_s_addback(t_stack **head, t_stack *new)
{
	t_stack	*tmp;

	if (!*head && !new)
		return ;
	if (!*head)
	{
		(*head) = new;
		return ;
	}
	tmp = (*head);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

int	add_to_stack(t_stack **head, t_stack *new)
{
	if (!*head && !new)
		return (-1);
	if (!*head)
	{
		(*head) = new;
		return (1);
	}
	new->prev = (*head)->prev;
	new->next = (*head);
	(*head)->prev->next = new;
	(*head)->prev = new;
	(*head) = new;
	return (0);
}

int	get_dbl_ll_size(t_stack **head)
{
	size_t	size;
	t_stack	*p;

	size = 0;
	if (!(*head))
		return (0);
	p = (*head)->next;
	while (p != (*head))
	{
		size++;
		p = p->next;
	}
	return (size);
}

t_stack	*init_node(char *value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->value = ft_atoi(value);
	node->idx = 0;
	node->pos = 0;
	node->trgt = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}


