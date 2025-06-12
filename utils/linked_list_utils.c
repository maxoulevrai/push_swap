/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 23:21:15 by maleca            #+#    #+#             */
/*   Updated: 2025/06/12 23:31:28 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_all(t_stack **s_a, t_stack **s_b, t_ter **ter)
{
	stack_clear(s_a);
	stack_clear(s_b);
	free(*ter);
}

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
	new->prev->next = new;
	new->next = (*head);
	(*head)->prev = new;
	return (0);
}

int get_dbl_ll_size(t_stack **head)
{
	size_t	size;
	t_stack	*p;

	if (!(*head))
		return (0);
	size = 1;
	p = (*head)->next;
	while (1)
	{
		if (p == *head)
			return (size);
		size++;
		p = p->next;
	}
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


