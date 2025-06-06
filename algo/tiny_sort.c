/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 22:11:39 by maleca            #+#    #+#             */
/*   Updated: 2025/06/06 13:43:52 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	tiny_sort(t_stack **head, char print)
{
	int	first;
	int	second;
	int	third;

	first = (*head)->content;
	second = (*head)->next->content;
	third = (*head)->prev->content;
	if ((first < second) && (second < third))
	{
		swap(&head, print);
		reverse_rotate(&head, print);
	}
	else if ((first < third) && (third < second))
	{
		reverse_rotate(&head, print);
		swap(head, print);
	}
	else if ((second < first) && (first < third))
		swap(&head, print);
	else if ((third < first) && (first < second))
		reverse_rotate(&head, print);
	else if ((second < third) && (third < first))
		rotate(&head, print);
}
