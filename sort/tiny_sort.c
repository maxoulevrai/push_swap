/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 22:11:39 by maleca            #+#    #+#             */
/*   Updated: 2025/08/01 03:34:02 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	tiny_sort(t_stack **head, char print)
{
	int	first;
	int	second;
	int	third;

	if (!head || !*head || !(*head)->next || !(*head)->prev)
		return ;
	first = (*head)->value;
	second = (*head)->next->value;
	third = (*head)->next->next->value;
	if ((first > second) && (second > third))
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
