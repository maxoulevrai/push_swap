/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:08:20 by maleca            #+#    #+#             */
/*   Updated: 2025/07/08 18:38:44 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void free_all(t_stack **s_a, t_stack **s_b)
{
	if (s_a && *s_a)
		free_dbl_ll(s_a);
	if (s_b && *s_b)
		free_dbl_ll(s_b);
}

void	free_dbl_ll(t_stack **head)
{
	t_stack	*current;
	t_stack	*next;
	t_ter	*ter;

	if (!head || !*head)
		return ;
	ter = get_tertiles(head);
	if (!ter)
		return ;
	current = *head;
	while (ter->len > 0)
	{
		next = current->next;
		ter->len--;
		free(current);
		if (next == *head)
			break ;
		current = next;
	}
	if (ter)
	{
		free(ter);
		ter = NULL;
	}
	*head = NULL;
}

int add_to_stack(t_stack **head, t_stack *new)
{
	if (!head || !new)
		return (-1);
	if (!*head)
	{
		*head = new;
		(*head)->next = new;
		(*head)->prev = new;
		return (0);
	}
	new->prev = (*head)->prev;
	new->prev->next = new;
	new->next = *head;
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

t_stack *init_node(int value)
{
	t_stack *node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->idx = -1;
	node->pos = -1;
	node->trgt = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
