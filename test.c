/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:56:31 by maleca            #+#    #+#             */
/*   Updated: 2025/06/06 18:54:38 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack **head, char print)
{
	int	first;
	int	second;
	int	third;

	first = (*head)->content;
	second = (*head)->next->content;
	third = (*head)->prev->content;
	if ((third < second) && (second < first))
	{
		swap(head, print);
		reverse_rotate(head, print);
	}
	else if ((first < third) && (third < second))
	{
		reverse_rotate(head, print);
		swap(head, print);
	}
	else if ((second < first) && (first < third))
		swap(head, print);
	else if ((third < first) && (first < second))
		reverse_rotate(head, print);
	else if ((second < third) && (third < first))
		rotate(head, print);
}


t_stack	*init_node(char *value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->content = ft_atoi(value);
	node->idx = -1;
	node->pos = -1;
	node->trgt = -1;
	node->trgt_cost = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

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

void	dbl_stack_addback(t_stack **head, t_stack *new)
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

t_stack	*init_value(char **splited_args)
{
	t_stack	*head;
	t_stack	*tmp;
	size_t	i;
	int 	pos;

	head = NULL;
	pos = 1;
	i = 0;
	while (splited_args[i])
	{
		tmp = init_node(splited_args[i]);
		if (!tmp)
		{
			if (head)
				return (stack_clear(&head), NULL);
			return (NULL);
		}
		tmp->pos = pos++;
		dbl_stack_addback(&head, tmp);
		i++;
	}
	tmp->next = head;
	head->prev = tmp;
	return (head);
}

int	main(void)
{
	t_stack	*head;
	t_stack	*p;
	char	*dtab[4];

	dtab[0] = "3";
	dtab[1] = "2";
	dtab[2] = "1";
	dtab[3] = NULL;
	head = init_value(dtab);
	p = head;
	while (1)
	{
		printf("%d\n", p->content);
		printf("\n");
		p = p->next;
		if (p == head)
			break;
	}
	tiny_sort(&head, 'A');
	p = head;
	while (1)
	{
		printf("%d\n", p->content);
		printf("\n");
		p = p->next;
		if (p == head)
			break;
	}
	return (0);
}
