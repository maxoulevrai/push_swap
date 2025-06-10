/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:56:31 by maleca            #+#    #+#             */
/*   Updated: 2025/06/10 22:03:41 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_node(char *value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->value = ft_atoi(value);
	node->idx = -1;
	node->pos = -1;
	node->trgt_cost = -1;
	node->trgt = NULL;
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
		dbl_s_addback(&head, tmp);
		i++;
	}
	tmp->next = head;
	head->prev = tmp;
	return (head);
}

int	main(void)
{
	t_stack	*s_a;
	t_stack	*s_b;
	t_stack	*p_a;
	t_stack	*p_b;
	char	*dtab1[5];
	// char	*dtab2[5];

	dtab1[0] = "3";
	dtab1[1] = "-1";
	dtab1[2] = "25";
	dtab1[3] = "15";
	dtab1[4] = NULL;
	// dtab2[0] = "2";
	// dtab2[1] = "-5";
	// dtab2[2] = "21";
	// dtab2[3] = "4";
	// dtab2[4] = NULL;
	s_a = init_value(dtab1);
	move_b_optimize(&s_a, &s_b);
	// s_b = init_value(dtab2);
	p_a = s_a;
	p_b = s_b;
	while (1)
	{
		printf("%d\n", p_a->value);
		printf("\n");
		p_a = p_a->next;
		if (p_a == s_a)
			break;
	}
	while (1)
	{
		printf("%d\n", p_b->value);
		printf("\n");
		p_b = p_b->next;
		if (p_b == s_b)
			break;
	}
	free(s_a);
	free(s_b);
	// tiny_sort(&head, 'A');
	// p = head;
	// while (1)
	// {
	// 	printf("%d\n", p->value);
	// 	printf("\n");
	// 	p = p->next;
	// 	if (p == head)
	// 		break;
	// }
	return (0);
}
