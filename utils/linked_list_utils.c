/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 23:21:15 by maleca            #+#    #+#             */
/*   Updated: 2025/06/05 21:40:59 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_clear(t_stack **lst)
{
	t_stack	*tmp;

	while ((*lst))
	{
		tmp = (*lst)->next;
		free((*lst));
		(*lst) = tmp;
	}
}

void	dbl_stack_addback(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!*lst && !new)
		return ;
	if (!*lst)
	{
		(*lst) = new;
		return ;
	}
	tmp = (*lst);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

t_stack	*init_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->content = value;
	node->idx = 0;
	node->pos = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
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
		dbl_stack_addback_(&head, tmp);
	}
	tmp->next = head;
	head->prev = tmp;
	return (head);
}

