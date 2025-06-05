/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:33:52 by maleca            #+#    #+#             */
/*   Updated: 2025/05/29 00:36:26 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"


long	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + (nptr[i] - '0');
		i++;
	}
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return (sign * nbr);
}

// int	main(void)
// {
// 	printf("%ld\n", ft_atoi("-44"));
// 	return (0);
// }
