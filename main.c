/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:33:02 by maleca            #+#    #+#             */
/*   Updated: 2025/07/08 21:58:08 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_circular(t_stack *head)
{
	t_stack *p = head;
	int i = 0;
	if (!head)
		return;
	do {
		printf("node value: %d (pos: %d)\n", p->value, p->pos);
		p = p->next;
		i++;
	} while (p != head && i < 1000);
}

void push_swap(char **av)
{
	t_stack *s_a;
	t_stack *s_b;
//	t_ter *ter;

	s_b = NULL;
	s_a = parse(av);
	if (!s_a)
		return;
	get_idx(&s_a);
	if (is_sorted(&s_a))
	{
		free_dbl_ll(&s_a);
		return;
	}
	opti_b(&s_a, &s_b);
	// ter = get_tertiles()
	opti_a(&s_a, &s_b);
	free_all(&s_a, &s_b);
}


int main(int ac, char **av)
{
	if (ac == 1)
		return (ft_putendl_fd("Error", 2), 0);
	if (!av || !*av)
		return (ft_putendl_fd("Error", 2), 0);
	push_swap(av);
	return (0);
}