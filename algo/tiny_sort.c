/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 22:11:39 by maleca            #+#    #+#             */
/*   Updated: 2025/06/17 18:09:33 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	tiny_sort(t_stack **head, char print)
{
	int	first;
	int	second;
	int	third;

	if (!head || !*head || !(*head)->next || !(*head)->prev)
		return;
	first = (*head)->value;
	second = (*head)->next->value;
	third = (*head)->prev->value;
	if ((first < second) && (second < third))
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

int	is_sorted(t_stack **head, t_ter *ter)
{
	t_stack	*p;
	int		i;

	if (!head || !*head || !ter)
		return (0);
	i = 0;
	p = (*head);
	while (i < ter->len)
	{
		if (p->value > p->next->value && p->next != (*head))
			return (0);
		p = p->next;
		i++;
	}
	return (1);
}
