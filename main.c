/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:22:33 by root              #+#    #+#             */
/*   Updated: 2025/06/05 22:11:25 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*push_swap(char **av)
{
	t_stack	*stack_A;
	t_stack	*stack_B;

	stack_A = parse(av);
	if (!stack_A)
		return (NULL);
	get_idx(&stack_A);
	launch_algo(stack_A, stack_B);

}


int	main(int ac, char **av)
{
	t_stack	*stack_A;
	t_stack	*tmp;

	if (ac == 1)
		return (ft_putendl_fd("Error (too few arguments)", 2), 0);
	stack_A = push_swap(av);
	tmp = stack_A;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	stack_clear(&stack_A);
	return (0);
}
